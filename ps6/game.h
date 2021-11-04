#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include "drawGame.h"
#include <stdbool.h>
#include <unistd.h>
#include "machineController.h"

void readDoneLvlsFile(char db[]){
    FILE *fp;
    char ch;
    fp = fopen("DoneLvl.txt", "r");
    int y = 0;
    while (!feof(fp)) {
        ch = fgetc(fp);
        db[y] = ch;
        y++;
    }
    db[y+1]='\0';
    fclose(fp);
}

void writeDoneLvlFile(int id, int DoneLvl, int lvl){
    //if(lvl <= DoneLvl)
    //    return;
    char db[200];
    readDoneLvlsFile(db);
    db[id-1] = lvl+'0';
    mvprintw(3, 3, "%d", id);
    mvprintw(4, 3, "%d", lvl);
    mvprintw(5, 3, "%d", DoneLvl);
    refresh();

    FILE *fp;
    fp = fopen("DoneLvl.txt", "w");
    for(int i = 0; i < strlen(db)-1; i++){
        fputc(db[i], fp);
    }
        
    fclose(fp);
}

void game(int id, int *DoneLvl){
    char level1Border[7][5]={
        {"+   +"},           
        {"    |"},
        {"|   |"},
        {"|    "},
        {"|   |"},
        {"    |"},
        {"+---+"}
    };
    char level1[6][4]={
        {"^ <"},//4
        {"   "},//5
        {"> ^"},//6
        {"   "},//7
        {"  <"} //8
    };
    init_pair(1, COLOR_RED, COLOR_BLACK);
    int ch = 0, space;
    int space2 = 0;
    const int width = 50;
    const int height = 20;
    bool flag = false;
    int vertical = 4;
    int gorizontal = 24;
    int steps = 0;
    time_t start, end;
    double elapsed;
    time(&start); 
    DrawBorder2(width, height);
    drawGame(7, 5, 6, 4, width, level1Border, level1);
    while(flag == false){
        
        time(&end);
        elapsed = difftime(end, start);
        mvprintw(14, 12, "Time elapsed: %0.lf sec", elapsed);
        refresh();
        if(elapsed>=5){
            level1Border[3][4]='|';
            attron(COLOR_PAIR(1));
            mvprintw(3+3, width/2-2+4,"%c",level1Border[3][4]);
            attroff(COLOR_PAIR(1));
            refresh();
        }

        DrawSteps(steps);
        flag = TheEnd(6,4,level1);
        ch = getch();
        space = ch + '0';
        switch (space){
            case 113:
                steps++;
                if(vertical != 4){
                    DrawCursorVertical(6,4,vertical, gorizontal, width, space, level1);
                    vertical --; 
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear(6,4,vertical, gorizontal, level1)){
                        GoGame1(6,4,&vertical, &gorizontal, level1, level1Border);      
                    }
                    
                }
                break;
            case 114:
                steps++;
                if(vertical != 8){
                    DrawCursorVertical(6,4,vertical, gorizontal, width, space, level1);
                    vertical ++;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear(6,4,vertical, gorizontal, level1)){
                        GoGame1(6,4,&vertical, &gorizontal, level1, level1Border);     
                    }
                }
                break;
            case 116:
                steps++;
                if(gorizontal != 24){
                    DrawCursorGorizontal(6,4,vertical, gorizontal, width, space, level1);
                    gorizontal--;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear(6,4,vertical, gorizontal, level1)){
                        GoGame1(6,4,&vertical, &gorizontal, level1, level1Border);       
                    }
                } 
                break;
            case 115:
                steps++;
                if(gorizontal != 26){
                    DrawCursorGorizontal(6,4,vertical, gorizontal, width, space, level1);
                    gorizontal++;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear(6,4,vertical, gorizontal, level1)){
                        GoGame1(6,4,&vertical, &gorizontal, level1, level1Border);       
                    }
                }
            break;
        }
    }
    DrawWin();
    writeDoneLvlFile(id,  *DoneLvl, 1);
    *DoneLvl = 1;
}

void game2(int id, int *DoneLvl){
   /* {"+ -      - +"},
    {" <|^^>8>88> "},
    {"|>88^>88>88 "},
    {" 88<|8>888^|"},
    {" ^<^|8^8888|"},
    {" 88<|8>8^88|"},
    {" <<888<8>>8 "},
    {"|>88>8^8888 "},
    {"|8>8888888^ "},
    {" ^88<^888<8|"},
    {"|>8>888^888 "},
    {"+----------+"},*/

    char level1Border[12][12]={
        {"+ -      - +"},//3
        {"  |         "},//4
        {"|           "},//5
        {"    |       "},//6
        {"    |      |"},//7
        {"    |      |"},//8
        {"            "},//9
        {"|           "},//10
        {"|           "},//11
        {"           |"},//12
        {"|           "},//13
        {"+----------+"}//4
         //24        //35
    };
    
    char level1[10][10]={
        {"< ^^> >  >"},//4
        {">  ^>  >  "},//5
        {"  <  >   ^"},//6
        {"^<^  ^    "},//7
        {"  <  < ^  "},//8
        {"<<   < >> "},//9
        {">  > ^    "},//10
        {" >       ^"},//11
        {"^  <^   < "},//12
        {"> >   ^   "} //13
    };
    int ch = 0, space;
    int space2 = 0;
    const int width = 50;
    const int height = 20;
    bool flag = false;
    int vertical = 4;
    int gorizontal = 24;
    int steps = 0;
    
    DrawBorder2(width, height);
    drawGame(12, 12, 10, 10, width, level1Border, level1);

    
    while(flag == false){
        DrawSteps(steps);
        flag = TheEnd(10,10,level1);
        ch = getch();
        space = ch + '0';
        switch (space){
            case 113:
            steps++;
                if(vertical != 4){
                    DrawCursorVertical(10,10,vertical, gorizontal, width, space, level1);
                    vertical --; 
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear2(10,10,vertical, gorizontal, level1)){
                        Go2(10,10,&vertical, &gorizontal, level1);      
                    }
                    
                }
                break;
            case 114:
            steps++;
                if(vertical != 13){
                    DrawCursorVertical(10,10,vertical, gorizontal, width, space, level1);
                    vertical ++;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear2(10,10,vertical, gorizontal, level1)){
                        Go2(10,10,&vertical, &gorizontal, level1);      
                    }
                }
                break;
            case 116:
            steps++;
                if(gorizontal != 24){
                    DrawCursorGorizontal(10,10,vertical, gorizontal, width, space, level1);
                    gorizontal--;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear2(10,10,vertical, gorizontal, level1)){
                        Go2(10,10,&vertical, &gorizontal, level1);      
                    }
                } 
                break;
            case 115:
            steps++;
                if(gorizontal != 33){
                    DrawCursorGorizontal(10,10,vertical, gorizontal, width, space, level1);
                    gorizontal++;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear2(10,10,vertical, gorizontal, level1)){
                        Go2(10,10,&vertical, &gorizontal, level1);      
                    }
                }
            break;
        }
    }
    DrawWin();
    writeDoneLvlFile(id,  *DoneLvl, 2);
    *DoneLvl = 2;
}

void game3(int id, int *DoneLvl){
   /* {"+ -      - +"},
    {" <|^^>8>88> "},
    {"|>88^>88>88 "},
    {" 88<|8>888^|"},
    {" ^<^|8^8888|"},
    {" 88<|8>8^88|"},
    {" <<888<8>>8 "},
    {"|>88>8^8888 "},
    {"|8>8888888^ "},
    {" ^88<^888<8|"},
    {"|>8>888^888 "},
    {"+----------+"},*/

    char level1Border[14][14]={
        {"+            +"},//3
        {"              "},//4
        {"              "},//5
        {"              "},//6
        {"              "},//7
        {"              "},//8
        {"              "},//9
        {"              "},//10
        {"              "},//11
        {"              "},//12
        {"              "},//13
        {"              "},//13
        {"              "},//13
        {"+            +"}//4
         //24        //35
    };
    
    char level1[12][12]={
        {">      v> >^"},//4
        {"^ < <^<<^ v<"},
        {"> > ^ ^> >v>"},
        {">^v>>  v ^v "},
        {"    ^>  ^   "},
        {"<>v^>^>v ^>^"},
        {">      >^ v>"},
        {"^ <^ v vv  <"},
        {">  v> ^  >v^"},
        {"  < ^     <<"},
        {">   v> > >v "},
        {"^  v< ^< v< "}//15
    };
    int ch = 0, space;
    int space2 = 0;
    const int width = 50;
    const int height = 20;
    bool flag = false;
    int vertical = 4;
    int gorizontal = 24;
    int steps = 0;
    int vert = 0, gor = 0;
    
    DrawBorder2(width, height);
    drawGame(14, 14, 12, 12, width, level1Border, level1);

    
    while(flag == false){
        DrawSteps(steps);
        flag = TheEnd(12,12,level1);
        ch = getch();
        space = ch + '0';
        switch (space){
            case 113:
            steps++;
                if(vertical != 4){
                    DrawCursorVertical(12,12,vertical, gorizontal, width, space, level1);
                    vert = vertical;
                    vertical --; 
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear3(12,12,vertical, gorizontal, level1)){
                        Go3(12,12,&vertical, &gorizontal, level1);      
                    }
                    vertical = vert;
                }
                break;
            case 114:
            steps++;
                if(vertical != 15){
                    DrawCursorVertical(12,12,vertical, gorizontal, width, space, level1);
                    vert = vertical;
                    vertical ++;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear3(12,12,vertical, gorizontal, level1)){
                        Go3(12,12,&vertical, &gorizontal, level1);      
                    }
                    vertical = vert;
                    
                }
                break;
            case 116:
            steps++;
                if(gorizontal != 24){
                    DrawCursorGorizontal(12,12,vertical, gorizontal, width, space, level1);
                    
                    gorizontal--;
                    gor = gorizontal;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear3(12,12,vertical, gorizontal, level1)){
                        Go3(12,12,&vertical, &gorizontal, level1);      
                    }
                    gorizontal = gor;
                } 
                break;
            case 115:
            steps++;
                if(gorizontal != 35){
                    DrawCursorGorizontal(12,12,vertical, gorizontal, width, space, level1);
                    gorizontal++;
                    gor = gorizontal;
                }
                if((space2 = (ch = getch()+'0')) == 80){
                    while(FrontIsClear3(12,12,vertical, gorizontal, level1)){
                        Go3(12,12,&vertical, &gorizontal, level1);      
                    }
                    gorizontal = gor;
                }
            break;
        }
    }
    DrawWin();
    writeDoneLvlFile(id,  *DoneLvl, 3);
    *DoneLvl = 3;
}
