bin/main: src/main.c bin/mcds.o
	gcc -o bin/main src/main.c bin/mcds.o

bin/mcds.o: src/mcds.asm bin/
	nasm -f elf64 -o bin/mcds.o src/mcds.asm

bin/:
	mkdir bin

all: clean bin/main

.PHONY: clean
clean:
	rm -rf bin