//important because of usleep()
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include "menu.h"
#include <stdbool.h>

int main(int argc, char* argv[]){
    char *fileLogin = argv[1];
    char *filePassword = argv[2];
    int DoneLvl = 2;
    int id = 0;
    srand(time(NULL));
    initscr();
    start_color();
    noecho();
    curs_set(FALSE);
    menuStart(&fileLogin, &filePassword, &DoneLvl, &id);
    menuEnter(&DoneLvl,  id);
    //cdvccvcccccccCdаcccccccccccccccv
    return 0;
}