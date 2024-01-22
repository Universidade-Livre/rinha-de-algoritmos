#!/bin/sh

WARMUP=10
RUNS=10
SUM_MEANS=0
FILE_COUNT=0
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

echo -e "\n\nRodará um (Hyperfine) Benchmark de $RUNS runs para cada arquivo"
echo -e "Depois pego as médias numa jq, e calculo ao final a soma das médias"
echo -e "Isso foi feito para facilitar a execução e visualização dos resultados\n\n"

printf "%-${MFNL}s  %s \t %s \n" "FileName" "Respostas" "Runtime"
for file in examples/*
do
  result=$(hyperfine --warmup $WARMUP --runs $RUNS "python problema-2.py $file" --export-json /tmp/hyperfine_results.json 2>/dev/null)
  
  output=$(python problema-2.py $file)
  filename=$(basename $file)
  mean=$(jq -r '.results | .[0].mean' /tmp/hyperfine_results.json)
  
  formatted_mean=$(printf "%.9f" $mean)
  SUM_MEANS=$(echo "$SUM_MEANS + $mean" | bc)
  FILE_COUNT=$((FILE_COUNT + 1))
  
  printf "%-${MFNL}s $output \t $formatted_mean s\n" "$filename"
done

AVERAGE_MEAN=$(echo "scale=9; $SUM_MEANS / $FILE_COUNT" | bc)

TOTAL_RUNTIME=$(printf "%.9f" $SUM_MEANS)
AVERAGE_MEAN=$(printf "%.9f" $AVERAGE_MEAN)

echo -e "\nTotal Runtime:   \t\t $TOTAL_RUNTIME s\n"
echo -e "\nAvarage Runtime: \t\t $AVERAGE_MEAN s\n\n"