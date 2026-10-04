#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define NGIOCHI 3
#define NAME_LEN 24

static const char *nome_giochi[NGIOCHI] = {
    "Pacman",
    "Snake",
    "Exit"
};

void draw_gameboy_frame(int start_y, int start_x, int width, int height) {
    attron(COLOR_PAIR(2));
    // Top border
    mvprintw(start_y, start_x, "+");
    for (int i = 1; i < width - 1; i++) addch('-');
    addch('+');

    // Side borders
    for (int y = start_y + 1; y < start_y + height - 1; y++) {
        mvprintw(y, start_x, "|");
        mvprintw(y, start_x + width - 1, "|");
    }

    // Bottom border
    mvprintw(start_y + height - 1, start_x, "+");
    for (int i = 1; i < width - 1; i++) addch('-');
    addch('+');
    attroff(COLOR_PAIR(2));
}

void menu(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    if (has_colors()) {
        start_color();
        use_default_colors();
        init_pair(1, COLOR_YELLOW, -1);
        init_pair(2, COLOR_CYAN, -1);
        init_pair(3, COLOR_BLACK, COLOR_WHITE);
        init_pair(4, COLOR_GREEN, -1);
    }

    int selected = 0;
    int ch;

    while (1) {
        clear();
        int rows, cols;
        getmaxyx(stdscr, rows, cols);

        int box_width = 38;
        int box_height = 14;
        int start_y = (rows - box_height) / 2;
        int start_x = (cols - box_width) / 2;

        if (start_y < 0) start_y = 0;
        if (start_x < 0) start_x = 0;

        draw_gameboy_frame(start_y, start_x, box_width, box_height);

        // Header Title
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(start_y + 1, start_x + (box_width - 15) / 2, "GAMEBOY ADVANCE");
        attroff(COLOR_PAIR(1) | A_BOLD);

        attron(COLOR_PAIR(2));
        mvprintw(start_y + 2, start_x + (box_width - 24) / 2, "========================");
        attroff(COLOR_PAIR(2));

        mvprintw(start_y + 3, start_x + (box_width - 17) / 2, "SELECT YOUR GAME");

        // Menu entries
        for (int i = 0; i < NGIOCHI; i++) {
            int item_y = start_y + 5 + (i * 2);
            int item_x = start_x + 8;

            if (i == selected) {
                attron(COLOR_PAIR(4) | A_BOLD);
                mvprintw(item_y, item_x - 3, "-> ");
                attroff(COLOR_PAIR(4) | A_BOLD);

                attron(COLOR_PAIR(3) | A_BOLD);
                mvprintw(item_y, item_x, "  %-14s", nome_giochi[i]);
                attroff(COLOR_PAIR(3) | A_BOLD);
            } else {
                mvprintw(item_y, item_x - 3, "   ");
                mvprintw(item_y, item_x, "  %-14s", nome_giochi[i]);
            }
        }

        // Instructions
        mvprintw(start_y + box_height - 2, start_x + (box_width - 28) / 2, "[^/v / W/S] Select [ENTER] OK");

        refresh();

        ch = getch();
        if (ch == KEY_UP || ch == 'w' || ch == 'W') {
            selected = (selected - 1 + NGIOCHI) % NGIOCHI;
        } else if (ch == KEY_DOWN || ch == 's' || ch == 'S') {
            selected = (selected + 1) % NGIOCHI;
        } else if (ch == 10 || ch == 13 || ch == KEY_ENTER) {
            if (selected == 0) {
                endwin();
                system("./bin/games/pacminal.o");
                initscr();
                cbreak();
                noecho();
                keypad(stdscr, TRUE);
                curs_set(0);
            } else if (selected == 1) {
                endwin();
                system("./bin/games/terton.o");
                initscr();
                cbreak();
                noecho();
                keypad(stdscr, TRUE);
                curs_set(0);
            } else if (selected == 2) {
                break;
            }
        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }

    endwin();
}