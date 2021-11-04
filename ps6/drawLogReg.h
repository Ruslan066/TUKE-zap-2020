#include <curses.h>

void DrawInputLogin(int width, int height, int n){
    for(int i = 1; i<9; i++)
        mvprintw(i, 3, "                                      ");
    refresh();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));
        mvprintw(2, width/2-3, "M");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-3+1, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-3+2, "E");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-3+3, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-3+4, "N");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-3+5, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-3+6, "U");
        usleep( n * 100000 );
        refresh();
    attroff(COLOR_PAIR(1));
    
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvprintw(4, width/2-7,"Input login:");
    attroff(COLOR_PAIR(3));
    refresh();
}

void DrawInputPassword(int width){
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvprintw(6, width/2-7,"Input password: ");
    attroff(COLOR_PAIR(3));
    refresh();
}

void DrawLogPswd(int width, int y, int i, char x){
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    move(y, width/2-7+i);
    attron(COLOR_PAIR(4));
    printw("%c",x);
    attroff(COLOR_PAIR(4));
    refresh();
}