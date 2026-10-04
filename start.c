#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "boot.h"
#include "menu.h"




int main(){
    boot();
    menu();
    return 0;
}

