"""
LICENSE

Copyright (c) 2023 Felipe Markson dos Santos Monteiro

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
"""

import random as rng
import sys

class WrongNumberOfArguments(TypeError):
    pass 

W = 2666
N = 1000
vlimits = (30, 200)
wlimits = (1, 7)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise WrongNumberOfArguments

    rng.seed(sys.argv[1])
    print(f"{N} {W}")
    for _ in range(N):
        w = rng.randint(*wlimits)
        v = rng.randint(*vlimits)
        print(f"{w}\t{v}")
