#!/bin/sh

#Hyperfine all examples one by one
clear

WARMUP=10
RUNS=200

for file in examples/*
do
  namefile=$(basename $file)
  output=$(python problema-1.py $file)
  echo -e "\nResposta do $namefile  ->  $output"
  echo -e "Benchmark"
  hyperfine --warmup $WARMUP --runs $RUNS "python problema-1.py $file" 2>/dev/null | grep -v "^Benchmark 1: python problema-1.py"
done
