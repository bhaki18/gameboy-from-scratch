CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses

all: bin/gameboy.o bin/games/pacminal.o bin/games/terton.o

bin/gameboy.o: start.c boot.h menu.h | bin
	$(CC) $(CFLAGS) start.c -o bin/gameboy.o $(LDFLAGS)

bin/games/pacminal.o: games/pacminal.c | bin/games
	$(CC) $(CFLAGS) games/pacminal.c -o bin/games/pacminal.o $(LDFLAGS)

bin/games/terton.o: games/terton.c | bin/games
	$(CC) $(CFLAGS) games/terton.c -o bin/games/terton.o $(LDFLAGS)

bin:
	mkdir -p bin

bin/games: | bin
	mkdir -p bin/games

start: all
	./bin/gameboy.o

clean:
	rm -rf bin