# GameBoy From Scratch

A terminal GameBoy launcher and retro games suite written in C with ncurses.

## Included Games
1. **Pacminal**: Terminal-based Pac-Man with original-style map, ghosts, and power pellets.
2. **Snake (Terton)**: Classic terminal Snake game with food spawning and growing tail.

## Build and Run

Ensure you have `gcc`, `make`, and `libncurses-dev` installed.

```bash
# Build all binaries (launcher + games)
make all

# Run GameBoy launcher
make start
# or
./bin/gameboy.o
```

To clean generated binaries:
```bash
make clean
```

## Controls

### Main Menu
- `Up` / `Down` or `W` / `S`: Navigate games
- `ENTER`: Launch selected game
- `Q`: Exit

### Pacminal
- `W` / `A` / `S` / `D`: Movement (Up / Left / Down / Right)

### Snake
- `W` / `A` / `S` / `D`: Movement (Up / Left / Down / Right)
