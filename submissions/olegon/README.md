# Como rodar?

Eu deixei um script chamado `compile-and-run.sh`, então basta executá-lo:

```bash
./compile-and-run.sh
```

A saída esperada é:

```plain
Preparing...
Expected results are:
instances/exemplo_01.txt        1194
instances/exemplo_02.txt        407
instances/exemplo_03.txt        1566
Running for input file: ../../resources/instances/problem_01/exemplo_01.txt
1194
Running for input file: ../../resources/instances/problem_01/exemplo_02.txt
407
Running for input file: ../../resources/instances/problem_01/exemplo_03.txt
1566
```

# Qual linguagem foi utilizada?

Eu utilizei C++ por preferência pessoal e por ser uma linguagem muito rápida.

# Como resolvi?

Para cada semente, eu testo o valor obtido caso eu plante a semente e caso eu descarte a semente. É necessário testar o caso de descartar a semente, por mais que ela parece ótima, porque combinações de outras sementes podem gerar um valor melhor. A desvantagem de fazer isso é que eu posso calcular as mesmas combinações várias vezes:

- Caso 1: descartar - descartar - descartar - descartar - descartar
- Caso 2: descartar - descartar - descartar - descartar - **plantar**
- Caso 3: descartar - descartar - descartar - **plantar** - descartar
- Caso 4: descartar - descartar - descartar - **plantar** - **plantar**

Como exemplo, os casos 3 e 4 repetem os casos 1 e 2, e isto vai acontecer várias vezes. Para resolver esse problema, eu usei um *cache* para guardar as computações já feitas e reutilizá-las. Problemas com característica de subproblemas que se repetem e que podem ser usados para resolver problemas maiores podem ser resolvidos com *programação dinâmica*, que foi o que utilizei.
