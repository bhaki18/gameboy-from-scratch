#include <stdio.h>

#define WOB "\033[30;47m"
#define RESET "\033[0m"

#define NGIOCHI 2
#define NAME_LEN 20

void print_menu(void);
void print_game_name(int ng);
void print_game_name_selected(int ng);

int giochi[NGIOCHI];

char nome_giochi[NGIOCHI][NAME_LEN] = {
    "pacman",
    "snake"
};

void menu(void) {
    for (int i = 0; i < NGIOCHI; i++) {
        giochi[i] = 0;
    }

    giochi[0] = 1;

    print_menu();
}

void print_menu(void) {
    print("SELECT YOUR GAME...\n");
    int gioco_sel = 0;

    for (int i = 0; i < NGIOCHI; i++) {
        if (giochi[i] == 1) {
            gioco_sel = i;
        }
    }

    for (int i = 0; i < NGIOCHI; i++) {
        if (i != gioco_sel) {
            print_game_name(i);
        } else {
            print_game_name_selected(i);
        }
    }
}

void print_game_name(int ng) {
    printf("%-*s\n", NAME_LEN, nome_giochi[ng]);
}

void print_game_name_selected(int ng) {
    printf(WOB);
    printf("%-*s", NAME_LEN, nome_giochi[ng]);
    printf(RESET "\n");
}