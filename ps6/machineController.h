#include <curses.h>

bool FrontIsClear(int lenth1, int height1, int vertical, int gorizontal, char level1[lenth1][height1]){
    char type;
    bool go = false;
    type = level1[vertical-4][gorizontal-24];
    if(type == '<'){
        if(level1[vertical-4][gorizontal-24-1] == ' ')
            go = true;
        else 
            go = false;
    }
    else if(type == '>'){
        if(level1[vertical-4][gorizontal-24+1] == ' ')
            go = true;
        else 
            go = false;
    }
    else if(type == '^'){
        if(vertical==4){
            level1[vertical-4][gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
            go = true;
        }
        if(level1[vertical-4-1][gorizontal-24] == ' ')
            go = true;
        else 
            go = false;
    }
    
    else
        go = false;
    return go;
}

bool FrontIsClear2(int lenth1, int height1, int vertical, int gorizontal, char level1[lenth1][height1]){
    char type;
    bool go = false;
    type = level1[vertical-4][gorizontal-24];
    if(type == '<'){
        if(gorizontal==24)
            level1[vertical-4][gorizontal-24] = ' ';

        if(level1[vertical-4][gorizontal-24-1] == ' ')
            go = true;
        else 
            go = false;
    }
    else if(type == '>'){
        if(gorizontal==33)
            level1[vertical-4][gorizontal-24] = ' ';

        if(level1[vertical-4][gorizontal-24+1] == ' ')
            go = true;
        else 
            go = false;
    }
    else if(type == '^'){
        if(vertical==4){
            level1[vertical-4][gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
            go = true;
        }
        if(level1[vertical-4-1][gorizontal-24] == ' ')
            go = true;
        else 
            go = false;
    }
    
    else
        go = false;
    return go;
}

bool FrontIsClear3(int lenth1, int height1, int vertical, int gorizontal, char level1[lenth1][height1]){
    char type;
    bool go = false;
    type = level1[vertical-4][gorizontal-24];
    if(type == '<'){
        if(gorizontal==24)
            level1[vertical-4][gorizontal-24] = ' ';

        if(level1[vertical-4][gorizontal-24-1] == ' ')
            go = true;
        else 
            go = false;
    }
    else if(type == '>'){
        if(gorizontal==35)
            level1[vertical-4][gorizontal-24] = ' ';

        if(level1[vertical-4][gorizontal-24+1] == ' ')
            go = true;
        else 
            go = false;
    }
    else if(type == '^'){
        if(vertical==4){
            level1[vertical-4][gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
            go = true;
        }
        if(level1[vertical-4-1][gorizontal-24] == ' ')
            go = true;
        else 
            go = false;
    }
    else if(type == 'v'){
        if(vertical==15){
            level1[vertical-4][gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
            go = true;
        }
        if(level1[vertical-4+1][gorizontal-24] == ' ')
            go = true;
        else 
            go = false;
    }
    else
        go = false;
    return go;
}

void Go(int lenth1, int height1, int *vertical, int *gorizontal, char level1[lenth1][height1]){
    //int vert = vertical;
    //int gor = gorizontal;
    char type;
    type = level1[*vertical-4][*gorizontal-24];

    if(type == '<'){
        level1[*vertical-4][*gorizontal-24-1] = '<';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)--;
        if(*gorizontal==24){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        } 
    }
    else if(type == '>'){
        level1[*vertical-4][*gorizontal-24+1] = '>';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)++;
        if(*gorizontal==26){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }
    else if(type == '^'){
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
        level1[*vertical-4-1][*gorizontal-24] = '^';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*vertical)--;
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }

    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    for(int i = 0; i < lenth1; i++){
        for(int j = 0; j < height1; j++){
            mvprintw(4+i, 50/2-1+j,"%c", level1[i][j]);
            refresh();
        }
    }
    attroff(COLOR_PAIR(2));
}

void GoGame1(int lenth1, int height1, int *vertical, int *gorizontal, char level1[lenth1][height1], char level1Border[7][5]){
    //int vert = vertical;
    //int gor = gorizontal;
    char type;
    type = level1[*vertical-4][*gorizontal-24];

    if(type == '<'){
        level1[*vertical-4][*gorizontal-24-1] = '<';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)--;
        if(*gorizontal==24){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        } 
    }
    else if(type == '>'){
        level1[*vertical-4][*gorizontal-24+1] = '>';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)++;
        if(*gorizontal==26 && level1Border[*vertical-3][*gorizontal-23+1] == ' '){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }
    else if(type == '^'){
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
        level1[*vertical-4-1][*gorizontal-24] = '^';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*vertical)--;
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }

    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    for(int i = 0; i < lenth1; i++){
        for(int j = 0; j < height1; j++){
            mvprintw(4+i, 50/2-1+j,"%c", level1[i][j]);
            refresh();
        }
    }
    attroff(COLOR_PAIR(2));
}

void Go2(int lenth1, int height1, int *vertical, int *gorizontal, char level1[lenth1][height1]){
    //int vert = vertical;
    //int gor = gorizontal;
    char type;
    type = level1[*vertical-4][*gorizontal-24];

    if(type == '<'){
        level1[*vertical-4][*gorizontal-24-1] = '<';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)--;
        if(*gorizontal==24){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        } 
    }
    else if(type == '>'){
        level1[*vertical-4][*gorizontal-24+1] = '>';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)++;
        if(*gorizontal==33){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }
    else if(type == '^'){
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
        level1[*vertical-4-1][*gorizontal-24] = '^';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*vertical)--;
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }

    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    for(int i = 0; i < lenth1; i++){
        for(int j = 0; j < height1; j++){
            mvprintw(4+i, 50/2-1+j,"%c", level1[i][j]);
            refresh();
        }
    }
    attroff(COLOR_PAIR(2));
}

void Go3(int lenth1, int height1, int *vertical, int *gorizontal, char level1[lenth1][height1]){
    //int vert = vertical;
    //int gor = gorizontal;
    char type;
    type = level1[*vertical-4][*gorizontal-24];

    if(type == '<'){
        level1[*vertical-4][*gorizontal-24-1] = '<';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)--;
        if(*gorizontal==24){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        } 
    }
    else if(type == '>'){
        level1[*vertical-4][*gorizontal-24+1] = '>';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*gorizontal)++;
        if(*gorizontal==35){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }
    else if(type == '^'){
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
        level1[*vertical-4-1][*gorizontal-24] = '^';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*vertical)--;
        if(*vertical==4){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }
    else if(type == 'v'){
        if(*vertical==15){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
        level1[*vertical-4+1][*gorizontal-24] = 'v';
        level1[*vertical-4][*gorizontal-24] = ' ';
        (*vertical)++;
        if(*vertical==15){
            level1[*vertical-4][*gorizontal-24] = ' ';
            //mvprintw(vertical, gorizontal," ");
        }
    }

    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    for(int i = 0; i < lenth1; i++){
        for(int j = 0; j < height1; j++){
            mvprintw(4+i, 50/2-1+j,"%c", level1[i][j]);
            refresh();
        }
    }
    attroff(COLOR_PAIR(2));
}

bool TheEnd(int lenth1, int height1, char level1[lenth1][height1]){
    bool q = true;
    for(int i = 0; i < lenth1; i++){
        for(int j = 0; j < height1; j++){
            if(level1[i][j] == '<' || level1[i][j] == '>' || level1[i][j] == '^' )
                q = false;
        }
    }
    return q;
}