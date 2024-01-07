# COMO USAR

Compile o arquivo ``solve-p1.cc`` com

```sh
g++ -std=c++17 -O2 -o solve solve-p1.cc

```

Após isso para resolver os casos de testes pode-se usar:

```sh
./solve < ../../resources/instances/problem_01/exemplo_01.txt
./solve < ../../resources/instances/problem_01/exemplo_02.txt
./solve < ../../resources/instances/problem_01/exemplo_03.txt
```

Resolvido usando prgramação dinâmica como paradigma, uma vez que os limites da questão nos possibilitam fazer essa abordagem.
Outra técnica usada foi de tabulação com remoção de memória para que seja possível passar nos limites de recursos.