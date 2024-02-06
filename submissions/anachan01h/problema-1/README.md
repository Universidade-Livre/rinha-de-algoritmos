# Solução do Problema 1

Minha solução do problema 1 em Assembly.

## Pré-requisitos

- Um computador com Linux e arquitetura x64
- NASM
- GCC
- GNU Make

## Como executar

Primeiro, execute o comando:
```
make
```

O executável será compilado na basta `bin`. Para executar com um arquivo `exemplo.txt`, basta executar o comando:
```
./bin/main exemplo.txt
```

## Como executar pelo Docker

Primeiro, criamos a imagem no Docker:
```
docker build -t problema-1
```

Para executar com um arquivo `exemplo.txt`, basta executar o comando:
```
docker run --cpus=2 --memory=2g problema-1 exemplo.txt
```
**Observação:** Para testar um arquivo `exemplo.txt`, ele precisa estar na pasta `problema-1/` quando a imagem no Docker for criada. Recomendo colocar os arquivos de texto para teste numa pasta `test/`.