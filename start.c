#include <stdio.h>
#include <ncurses.h>

void stampa_gameboy_starting();
void pulisci_terminale();
void boot();

int main(){
    boot();

}

void pulisci_terminale() { printf("\033[2J\033[H"); }

void stampa_gameboy_starting(){
    prinf(
" ██████╗  █████╗ ███╗   ███╗███████╗██████╗  ██████╗ ██╗   ██╗\n",
"██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔══██╗██═══██╗╚██╗ ██╔╝\n",
"██║  ███╗███████║██╔████╔██║█████╗  ██████╔╝██   ██║ ╚████╔╝\n",
"██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ██╔══██╗██   ██║  ╚██╔╝\n",
"╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██████╔╝╚██████╔╝   ██║\n",
" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═════╝  ╚═════╝    ╚═╝\n",
"               your gameboy is starting!...\n");


}

void boot(){
    stampa_gameboy_starting();
    sleep(1);
    pulisci_terminale();
}