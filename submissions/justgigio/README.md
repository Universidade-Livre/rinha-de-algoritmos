# Como rodar

>*Nota:* talvez seja necessário rodar `chmod +x run* problema*`

## Com Docker

Primeiro é necessário fazer o build da imagem (é uma versão slim, então pode ficar de boa que vai ser rápido e ocupar pouquíssimo espaço)

`$ ./run.sh build` 

Depois basta rodar o mesmo script passando o número problema desejado ou nada para rodar todos:

`$ ./run.sh 2` ou simplesmente `$ ./run.sh`

Também é possível rodar o bash no container para fins de debug ou simplesmente ter mais controle:

`$ ./run.sh bash`

Em seguida, para rodar o script deve-se usar o python diretamente:

`$ python run.py [numero_do_problema]`

## Sem Docker

O arquivo `run.py` foi feito pra encontrar as entradas e saídas da forma como elas são copiadas dentro do container/imagem.

Ou seja, para rodar sem o Docker deve-se rodar diretamente o problema desejado passando a entrada desejada por `stdin`. Exemplo:

`$ python problema-3.py < ../../resources/instances/problem_03/exemplo_02.txt`

A respota vai ser direcionada para o `stdout` (nese caso, print no terminal)

Nesse caso é possível comparar o resultado com a resposta dessa forma:

`$ diff -s <(cat ../../resources/instances/problem_01/resultados.txt | grep exemplo_01 | sed 's/exemplo_01.txt\s*//') <(python problema-1.py < ../../resources/instances/problem_01/exemplo_01.txt)` :sweat_smile: 