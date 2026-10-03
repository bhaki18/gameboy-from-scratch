#define WOB "\033[30;47m"
#define RESET "\033[0m"
#define NGIOCHI 2
#define name_len 20

void print_menu();
void print_game_name();

int giochi[NGIOCHI];
char nome_giochi[NGIOCHI];

char nome_gioco_1[name_len] = {"pacman              "};
char nome_gioco_2[name_len] = {"snake               "};

nome_giochi[0] = nome_gioco_1;
nome_giochi[1] = nome_gioco_2;

for(int i = 0;i<NGIOCHI;i++){
    giochi[i] = 0;
    if(i == 0){
        giochi[i] = 1;
    }
}


void menu(){
    print_menu();
}

void print_menu(){
    int gioco_sel = 0;
    for(int i = 0;i<NGIOCHI;i++){
        if(giochi[i] == 1){
            gioco_sel = i;
        }
    }

    for(int i = 0;i<NGIOCHI;i++){
        if(i != gioco_sel){
            printf("%c%c"nome_giochi[i])
        }
    }
}

void print_game_name(){
    
}