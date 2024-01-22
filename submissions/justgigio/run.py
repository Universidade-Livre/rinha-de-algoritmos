#!/usr/bin/env python3

import sys
import math
import time
import psutil
from os import path, listdir
from subprocess import Popen, PIPE, call, DEVNULL

IO_FOLDER = '../instances'

GREEN = '\033[92m'
RED = '\033[91m'
ENDCOLOR = '\033[0m'


def profile_script(script, stdin):
  t0 = time.time()
  popen = Popen(script, stdin=open(stdin, 'rb'), stdout=PIPE, stderr=PIPE)
  process = psutil.Process(popen.pid)
  max_mem = 0
  while popen.poll() is None:
    try:
      curr_mem = process.memory_full_info().uss
      if curr_mem > max_mem:
        max_mem = curr_mem
    except psutil.NoSuchProcess:
      break
  execution_time = time.time() - t0
  status_code = popen.poll()
  script_ouput = popen.stdout.read().decode('utf-8')[:-1]
  if status_code != 0:
    raise Exception(script_ouput + popen.stderr.read().decode('utf-8'))
  popen.terminate()
  return [script_ouput, execution_time, max_mem]


def convert_size(size_bytes):
  # https://stackoverflow.com/a/14822210/4288138
  if size_bytes == 0:
    return "0B"
  size_name = ("B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB")
  i = int(math.floor(math.log(size_bytes, 1024)))
  p = math.pow(1024, i)
  s = round(size_bytes / p, 2)
  return "%s %s" % (s, size_name[i])


def run_script(number):
  script_name = f"problema-{number}.py"
  io_path = path.join(IO_FOLDER, f"problem_{number:0>2}")
  results_file = path.join(io_path, "resultados.txt")

  if not path.isfile(script_name):
    print(f"{RED}ERROR: No file {script_name} found!{ENDCOLOR}")
    return

  if not path.isfile(results_file):
    print(f"{RED}ERROR: No results found for {script_name}{ENDCOLOR}")
    return

  results = {}
  with open(results_file, "r") as fr:
    for line in fr.readlines():
      key, value = line.split()
      results[key] = value

  examples = [f for f in listdir(io_path) if path.isfile(path.join(io_path, f)) and f.startswith("exemplo_")]
  examples = sorted(examples)

  if len(examples) == 0:
    print(f"{RED}ERROR: No examples found for {script_name}{ENDCOLOR}")
    return

  print('=' * 30)
  print(f"# {script_name: <26} #")
  print('=' * 30)

  for example in examples:
    try:
      script_ouput, execution_time, memory_used = profile_script(["python", f"{script_name}"], f"{path.join(io_path, example)}")
    except Exception as e:
      title = f"{script_name} < {example} !!"
      print(f"{RED}  - FAILED :: {title}{ENDCOLOR}")
      print(f"    {e}")
      continue
      
    cmd = f"diff -q <(echo \"{results[example]}\") <(echo \"{script_ouput}\")"
    exit_code = call(["/bin/bash", "-c", cmd], stdout=DEVNULL)
    
    title = f"{script_name} < {example} :: [{execution_time:.4f}s | {convert_size(memory_used)}]"

    if exit_code == 0:
      print(f"{GREEN}  - OK :: {title}{ENDCOLOR}")
    else:
      print(f"{RED}  - FAILED :: {title}{ENDCOLOR}")
      print(f"    Expected: {results[example]}")
      print(f"    Found: {script_ouput}")


if len(sys.argv) > 1:
  number = int(sys.argv[1])
  run_script(number)
else:
  scripts = [f for f in listdir() if path.isfile(f) and f.startswith("problema-")]
  scripts = sorted(scripts)

  for script in scripts:
    _, num_ext = script.split('-')
    num, ext = num_ext.split('.')

    run_script(num)
