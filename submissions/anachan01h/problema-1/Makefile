bin/main: src/main.c bin/mochila_pd.o
	gcc -o bin/main src/main.c bin/mochila_pd.o

bin/mochila_pd.o: src/mochila_pd.asm bin/
	nasm -f elf64 -o bin/mochila_pd.o src/mochila_pd.asm

bin/:
	mkdir bin

all: clean bin/main

.PHONY: clean
clean:
	rm -rf bin

