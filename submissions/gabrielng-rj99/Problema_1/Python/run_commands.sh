#!/bin/sh

MFNL=0          # Max FileName Length Start

for file in examples/*
do
  filename=$(basename $file)
  len=$(echo -n "$filename" | wc -c)
  if [ $len -gt $MFNL ]; then
    MFNL=$len
  fi
done

clear

printf "%-${MFNL}s  %s \t \n" "FileName" "Respostas"
for file in examples/*
do
  output=$(python problema-1.py $file)
  filename=$(basename $file)
  printf "%-${MFNL}s $output\n" "$filename"
done