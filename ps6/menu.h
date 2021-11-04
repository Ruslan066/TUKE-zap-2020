#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include "logReg.h"
#include "drawMenu.h"
#include <stdbool.h>
#include <unistd.h>
#include "game.h"

void menuLevels();

void menuStart(char* fileLogin[], char* filePassword[], int *DoneLvl, int *id){
    int ch = 0, space;
    int space2 = 0;
    int ch2 = 0;
    bool go = false;
    const int width = 50;
    const int height = 20;
    int n = 1;
    int flag = 0;
    int vertical = 5;

    while(!go){
        DrawBorder(width, height);
        DrawMenuStart(width, height, vertical, n);
        flag = 0;
        while(flag == 0){
            ch = getch();
            space = ch + '0';
            switch (space){
                case 113:
                    DrawCursor(vertical, width, space);
                    vertical--;                    

                    if((space2 = (ch = getch()+'0')) == 80){
                        switch(vertical) {
                        case 5:
                            go = login(fileLogin, filePassword, DoneLvl, id);
                            if(!go){
                                DrawIncorrect(width);
                                ch2 = getch();
                                ch = ch2;
                                flag = 1;
                            }
                            else{
                                DrawCorrectProg(width);
                                ch2 = getch();
                                ch = ch2;
                                flag = 1;
                            }
                            break;
                        case 6:
                            registration(fileLogin, filePassword);
                            flag = 1;
                            break;
                        case 7:
                            endwin();
                            go = true;
                            break;
                        default:
                            printf("No option selected");
                        }
                    }
                    break;
                case 114:
                    DrawCursor(vertical, width, space);
                    vertical ++;
                    if((space2 = (ch = getch()+'0')) == 80){
                        switch(vertical) {
                        case 5:
                            go = login(fileLogin, filePassword, DoneLvl, id);
                            if(!go){
                                DrawIncorrect(width);
                                ch2 = getch();
                                ch = ch2;
                                flag = 1;
                            }
                            else{
                                DrawCorrectProg(width);
                                ch2 = getch();
                                ch = ch2;
                                flag = 1;
                            }
                            break;
                        case 6:
                            registration(fileLogin, filePassword);
                            flag = 1;
                            break;
                        case 7:
                            endwin();
                            go = true;
                            break;
                        default:
                            printf("No option selected");
                        }
                    }
                break;
                case 80:
                    switch(vertical)
                        case 5:
                            go = login(fileLogin, filePassword, DoneLvl, id);
                            if(!go){
                                DrawIncorrect(width);
                                ch2 = getch();
                                ch = ch2;
                                flag = 1;
                            }
                            else{
                                DrawCorrectProg(width);
                                ch2 = getch();
                                ch = ch2;
                                flag = 1;
                            }
                            break;
                        case 6:
                            registration(fileLogin, filePassword);
                            flag = 1;
                            break;
                        case 7:
                            endwin();
                            go = true;
                            break;
            }
        }    
    }
}

void menuEnter(int *DoneLvl, int id){
    int ch = 0, space;
    int space2 = 0;
    //int ch2 = 0;
    bool go = false;
    const int width = 50;
    const int height = 20;
    int n = 1;
    int flag = 0;
    int vertical = 5;

    while(!go){
        DrawBorder(width, height);
        DrawMenuEnter(width, height, vertical, n);
        refresh();
        flag = 0;
        while(flag == 0){
            ch = getch();
            space = ch + '0';
            switch (space){
                case 113:
                    DrawCursor(vertical, width, space);
                    vertical--;                    

                    if((space2 = (ch = getch()+'0')) == 80){
                        switch(vertical) {
                        case 5:
                            menuLevels(DoneLvl,  id);
                            flag = 1;
                            break;
                        case 6:
                            endwin();
                            go = true;
                            break;
                        default:
                            printf("No option selected");
                        }
                    }
                    break;
                case 114:
                    DrawCursor(vertical, width, space);
                    vertical ++;
                    if((space2 = (ch = getch()+'0')) == 80){
                        switch(vertical) {
                        case 5:
                            menuLevels(DoneLvl,  id);
                            flag = 1;
                            break;
                        case 6:
                            endwin();
                            go = true;
                            break;
                        default:
                            printf("No option selected");
                        }
                    }
                break;
                case 80:
                    switch(vertical)
                    case 5:
                        menuLevels(DoneLvl,  id);
                        flag = 1;
                        break;
                    case 6:
                        endwin();
                        go = true;
                        break;
            }
        }
    }
}

void menuLevels(int *DoneLvl, int id){
    int ch = 0, space;
    int space2 = 0;
    //int ch2 = 0;
    bool go = false;
    const int width = 50;
    const int height = 20;
    int n = 1;
    int flag = 0;
    int vertical = 5;

    while(!go){
        DrawBorder(width, height);
        DrawMenuLevels(width, height, vertical, n, *DoneLvl);
        flag = 0;
        while(flag == 0){
            ch = getch();
            space = ch + '0';
            switch (space){
                case 113:
                    DrawCursor(vertical, width, space);
                    vertical--;                    

                    if((space2 = (ch = getch()+'0')) == 80){
                        switch(vertical) {
                        case 5:
                            game(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 6:
                            if(*DoneLvl <1)
                                break;
                            game2(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 7:
                            if(*DoneLvl <2)
                                break;
                            game3(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 8:
                            go = true;
                            menuEnter(DoneLvl,  4);
                            
                            break;
                        default:
                            printf("No option selected");
                        }
                    }
                    break;
                case 114:
                    DrawCursor(vertical, width, space);
                    vertical ++;
                    if((space2 = (ch = getch()+'0')) == 80){
                        switch(vertical) {
                        case 5:
                            game(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 6:
                            if(*DoneLvl <1)
                                break;
                            game2(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 7:
                            if(*DoneLvl <2)
                                break;
                            game3(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 8:
                            go = true;
                            menuEnter(DoneLvl,  4);
                            break;
                        default:
                            printf("No option selected");
                        }
                    }
                break;
                case 80:
                    switch(vertical)
                        case 5:
                            game(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 6:
                            if(*DoneLvl <1)
                                break;
                            game2(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 7:
                            if(*DoneLvl <2)
                                break;
                            game3(id,  DoneLvl);
                            flag = 1;
                            break;
                        case 8:
                            go = true;
                            menuEnter(DoneLvl,  4);
                            break;
            }
        }
    }
}