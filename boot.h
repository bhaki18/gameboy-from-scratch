#include <stdio.h>
#include <unistd.h>

void stampa_gameboy_starting();
void pulisci_terminale();
void boot();
void pulisci_terminale() { printf("\033[2J\033[H"); }

void stampa_gameboy_starting(){

printf(" ██████╗  █████╗ ███╗   ███╗███████╗██████╗  ██████╗ ██╗   ██╗\n");
printf("██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔══██╗██═══██╗╚██╗ ██╔╝\n");
printf("██║  ███╗███████║██╔████╔██║█████╗  ██████╔╝██   ██║ ╚████╔╝\n");
printf("██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ██╔══██╗██   ██║  ╚██╔╝\n");
printf("╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██████╔╝╚██████╔╝   ██║\n");
printf(" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═════╝  ╚═════╝    ╚═╝\n");
printf("               your gameboy is starting!...\n");


}

void boot(){
    pulisci_terminale();
    stampa_gameboy_starting();
    sleep(2);
    pulisci_terminale();
}