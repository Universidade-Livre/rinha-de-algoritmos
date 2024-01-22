#!/bin/bash

set -e

echo "Preparing..."
g++ main.cpp -W -Wall -std=c++14 -O3

echo "Expected results are:"
cat "../../resources/instances/problem_01/resultados.txt"

for f in ../../resources/instances/problem_01/exemplo_*.txt; do
    echo "Running for input file: $f";
    cat "$f" | ./a.out;
done;
