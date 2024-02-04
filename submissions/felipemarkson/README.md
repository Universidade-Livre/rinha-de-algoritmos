# Rinha de Algoritmos -- Problema 01: Lucro de Plantação no Stardew Valley

> Todos os testes foram feitos em um Arch Linux utilizando o GCC `13.2.1` e clang `16.0.6`

> O programa utiliza apenas uma thread e é previsto uma utilização de memória de até 11 MB para a maior instância do problema.

## Build

Para build, você precisará de um compilador C que supporte C99
(praticamente qualquer compilador C moderno) e habilitar flags de otimização
(`-Ofast` para GCC e clang).

> **NOTE**: Se você estiver em um Linux, pode executar o arquivo `build.sh` para realizar o build. Esse script criará uma versão de release `p1` e uma versão de debug `p1d` (veja a sessão de Debug).

Veja os exemplos abaixo.

### GCC

```bash
gcc -Ofast -o p1 problema-1.c
```
### clang

```bash
clang -Ofast -o p1 problema-1.c
```

## Execução

O programa aceita o caminho para o arquivo como primeiro parâmetro no CLI.
Caso o arquivo não seja passado, o programa irá quebrar.
Veja exemplo de utilização abaixo.

```bash
./p1 test.txt
```

## Debug

As vezes coisas estranhas acontecem. Para isso há uma versão de debug `p1d` que é gerada pelo script `build.sh`.

Nessa versão, vários logs são escritos, tanto no `stdout` quanto no `stderr`. Redicione eles corretamente para arquivos afim de obter mais informações de execução.

## Gerando novos casos

O arquivo `gen_case.py` gera casos pseudo-randomicos baseado em um seed passado como primeiro parâmetro. O caso é escrito no `stdout`, redirecione-o de acordo. 

Veja o exemplo abaixo.

```bash
python3 gen_case.py myseed > test_myseed.txt
```

## Copyright

Copyright (c) 2023 Felipe Markson dos Santos Monteiro

Os arquivos nesta pasta estão sob licensa MIT. Veja `LICENSE` para mais detalhes.
