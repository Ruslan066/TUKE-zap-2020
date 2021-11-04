#include <curses.h>
// ch = getch();
// space2 = ch+'0';
// move(8, 3);
// printw("%d",space2);
// refresh();

void DrawBorder(int width, int height){
    WINDOW *win = newwin(height, width, 0, 0);

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    
    refresh();
    box(win, 0, 0);
    wrefresh(win); 
}

void DrawMenuStart(int width, int height, int vertical, int n){
    for(int i = 1; i<height-2; i++)
        mvprintw(i, 3, "                                      ");
    refresh();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

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
        //wchar_t codepoint = 0xE2;
        //mvprintw(12, 3,"%c", codepoint);
        refresh();
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
        mvprintw(5, width/2-2, "Login");
        mvprintw(6, width/2-6, "Registration");
        mvprintw(7, width/2-2, "Exit");
    attroff(COLOR_PAIR(2));
    mvprintw(vertical, width/2+13, "<");
    refresh();
}

void DrawMenuEnter(int width, int height, int vertical, int n){
    for(int i = 1; i<height-2; i++)
        mvprintw(i, 3, "                                      ");
    refresh();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

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
    attron(COLOR_PAIR(2));
        mvprintw(5, width/2-3, "Levels");
        //mvprintw(6, width/2-2, "Play");
        //mvprintw(7, width/2-2, "Shop");
        mvprintw(6, width/2-2, "Exit");
    attroff(COLOR_PAIR(2));
    mvprintw(vertical, width/2+13, "<");
    refresh();
}

void DrawCursor(int vertical, int width, int space){
    if(space == 113){
        mvprintw(vertical, width/2+13, " ");
        vertical--;
        mvprintw(vertical, width/2+13, "<");
        refresh();
    }
    if(space == 114){
        mvprintw(vertical, width/2+13, " ");
        vertical++;
        mvprintw(vertical, width/2+13, "<");
        refresh();
    }
}

void DrawIncorrect(int width){
    mvprintw(8, width/2-17, "Username or password is incorrect.");
    refresh();
}

void DrawCorrectProg(int width){
    mvprintw(8, width/2-4, "Welcome.");
    refresh();
}

void DrawMenuLevels(int width, int height, int vertical, int n, int DoneLvl){
    for(int i = 1; i<height-2; i++)
        mvprintw(i, 3, "                                      ");
    refresh();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    int p = 5;
    attron(COLOR_PAIR(1));
        mvprintw(2, width/2-p, "L");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+1, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+2, "E");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+3, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+4, "V");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+5, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+6, "E");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+7, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+8, "l");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+88, " ");
        usleep( n * 100000 );
        refresh();
        mvprintw(2, width/2-p+10, "S");
        usleep( n * 100000 );
        refresh();
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
        mvprintw(5, width/2-3, "Level 1");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
        mvprintw(6, width/2-3, "Level 2");
        mvprintw(7, width/2-3, "Level 3");
    attroff(COLOR_PAIR(3));

        if(DoneLvl >=1){
            attron(COLOR_PAIR(2));
                mvprintw(6, width/2-3, "Level 2");
            attroff(COLOR_PAIR(2));
        }
        if(DoneLvl >=2){
            attron(COLOR_PAIR(2));
                mvprintw(7, width/2-3, "Level 3");
            attroff(COLOR_PAIR(2));
        }
        attron(COLOR_PAIR(2));
        mvprintw(8, width/2-3, "Exit");
        attroff(COLOR_PAIR(2));
    
    mvprintw(vertical, width/2+13, "<");
    refresh();
}
