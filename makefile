CC = gcc
FLAGS = -lncurses 
start:
	mkdir bin
	$(CC) start.c -o bin/gameboy.o $(FLAGS)
	mkdir bin/games

clear:
	rm bin/gameboy.o
	rmdir bin/games
	rmdir bin