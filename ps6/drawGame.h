#include <ncurses.h>
#include <time.h>

// ch = getch();
// space2 = ch+'0';
// move(8, 3);
// printw("%d",space2);
// refresh();

void DrawBorder2(int width, int height){ 
    WINDOW *win = newwin(height, width, 0, 0);
    
    refresh();
    box(win, 0, 0);
    wrefresh(win);
}

void drawGame(int lenth1, int height1, int lenth2,  int height2, int width, char level1Border[lenth1][height1], char level1[lenth2][height2]){
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for(int i = 0; i < lenth1; i++){
        for(int j = 0; j < height1; j++){
            mvprintw(3+i, width/2-2+j,"%c", level1Border[i][j]);
            //usleep( 1 * 100000 );
            refresh();
        }
    }
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    for(int i = 0; i < lenth2; i++){
        for(int j = 0; j < height2; j++){
            mvprintw(4+i, width/2-1+j,"%c", level1[i][j]);
            //usleep( 1 * 100000 );
            refresh();
        }
    }
    attroff(COLOR_PAIR(2));
}

void DrawCursorVertical(int lenth1, int height1, int vertical, int gorizontal, int width, int space, char level1[lenth1][height1]){
    //4, 24
    //0, 0
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_GREEN);
    if(space == 113){
        move(vertical, gorizontal);
        attron(COLOR_PAIR(3));
        printw("%c", level1[vertical-4][gorizontal-24]);
        //mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(3));
        refresh();
        vertical--;

        move(vertical, gorizontal);
        attron(COLOR_PAIR(4));
        printw("%c", level1[vertical-4][gorizontal-24]);
        //mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(4));

        refresh();
    }
    if(space == 114){
        move(vertical, gorizontal);
        attron(COLOR_PAIR(3));
        printw("%c", level1[vertical-4][gorizontal-24]);
        //mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(3));
        refresh();
        vertical++;

        move(vertical, gorizontal);
        attron(COLOR_PAIR(4));
        printw("%c", level1[vertical-4][gorizontal-24]);
        //mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(4));

        refresh();
    }
}

void DrawCursorGorizontal(int lenth1, int height1, int vertical, int gorizontal, int width, int space, char level1[lenth1][height1]){
    //4, 24
    //0, 0
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_GREEN);
    if(space == 116){
        
        attron(COLOR_PAIR(3));
        mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(3));
        refresh();
        gorizontal--;

        attron(COLOR_PAIR(4));
        mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(4));

        refresh();
    }
    if(space == 115){
        attron(COLOR_PAIR(3));
        mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(3));
        refresh();
        gorizontal++;

        attron(COLOR_PAIR(4));
        //mvaddch(vertical, gorizontal, level1[vertical-4][gorizontal-24]);
        mvprintw(vertical, gorizontal, "%c", level1[vertical-4][gorizontal-24]);
        attroff(COLOR_PAIR(4));

        refresh();
    }
}

void DrawWin(){
    int ch = 0, space;
    do{
    usleep( 3 * 100000 );
    for(int i = 1; i<20-2; i++)
        mvprintw(i, 3, "                                      ");
    refresh();
    mvprintw(3, 25-2, "W I N");
    refresh();
    }while((space = (ch = getch()+'0')) != 80);
}

void DrawTimer(){
    //00:00
    const time_t timer = time(NULL);
    usleep( 1 * 100000 );
    mvprintw(12, 50/2-10,"%s", ctime(&timer));
    refresh();
}

void DrawSteps(int steps){
    mvprintw(2, 50/2-3,"Steps: %d", steps);
    refresh();
}