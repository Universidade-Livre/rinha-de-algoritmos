## Execução do Projeto

Este projeto utiliza Docker para criar um ambiente isolado para a execução de scripts Bash. A seguir, são fornecidas instruções para construir a imagem Docker, executar o contêiner e passar um arquivo externo como entrada.

1. Construa a imagem Docker e execute o contêiner:

```
$ docker build submissions/marcosvile/. -t problem_01 && time sudo docker run --rm --cpus=2 --memory=2g -v $(pwd)/[diretório do arquivo de entrada]:/app/resources problem_01 ./problema-1.sh resources/[nome do arquivo de entrada].txt
```

Este comando constrói a imagem a ser utilizada no contêiner contento o script bash, e executa um contêiner a partir dessa imagem parametrizado conforme os requisitos do problema com dois núcleos de CPU, 2 GB de RAM e mapeia o diretório local passado pela flag -v, para dentro do contêiner. Certifique-se de substituir o nome do diretório onde contém o arquivo de entrada e o nome utilizado pelo arquivo de entrada externo.

Certifique-se de ajustar os caminhos e nomes de arquivo conforme necessário com base na sua estrutura de diretórios e requisitos específicos.
