CC = gcc
FLAGS = -lncurses 
start:
	$(CC) start.c -o bin/gameboy.o $(FLAGS)

clear:
	rm bin/gameboy.o