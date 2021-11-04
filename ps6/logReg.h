#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#include <malloc.h>
#include "drawLogReg.h"

void encoding(char password[20]){
    for (int i = 0; i < strlen(password); i++){
        password[i]=(password[i] ^ (i+1));
    }
}

void deEncoding(char password[20]){
    for (int i = 0; i < strlen(password); i++){
        password[i]=(password[i] ^ (i+1));
    }
}

bool equal(char str1[20], char str2[20]) {
    int k =0;
    for (int i = 0; i < strlen(str1); i++) 
        if (str1[i] == str2[i])
            k++;
    if(k==strlen(str1))
        return true;
    else
        return false;
}
//-----------------------------
void readLoginFile(char DBLogin[200][20], int *lenth, char* fileLogin[], char* filePassword[]){
    FILE *fp;
    char ch;
    fp = fopen(*fileLogin, "r");
    int y = 0, x =0;
    while (!feof(fp)) {
        ch = fgetc(fp);
        DBLogin[x][y] = ch;
        y++;
        if (ch == '\n'){
            x++;
            y = 0;
        }
    }
    *lenth = x;
    fclose(fp);

}

void readPasswordFile(char DBPassword[200][20], char* fileLogin[], char* filePassword[]){
    FILE *fp;
    char ch;
    fp = fopen(*filePassword, "r");
    int y = 0, x =0;
    char password[20];
    while (!feof(fp)) {
        ch = fgetc(fp);
        DBPassword[x][y] = ch;
        y++;
        if (ch == '\n'){
            x++;
            y = 0;
        }
    }
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < 20; j++)
            password[j] = DBPassword[i][j];
        password[strlen(password)-1] = '\0';
        deEncoding(password);
        for(int j = 0; j < strlen(password); j++)
            DBPassword[i][j] = password[j];
    }
    fclose(fp);
}

void readDoneLvlFile(int *DoneLvl, int id){
    FILE *fp;
    char ch;
    fp = fopen("DoneLvl.txt", "r");
    int y = 0;
    while (y!=id) {
        ch = fgetc(fp);
        *DoneLvl = ch - '0';
        y++;
    }
    fclose(fp);
}

//----------------------------
void writeLoginFile(char login[20], char* fileLogin[], char* filePassword[]){
    FILE *fp;
    fp = fopen(*fileLogin, "a");
    fputs("\n",fp);
    for(int i = 0; i < strlen(login); i++)
        fputc(login[i], fp);
    fclose(fp);
}

void writePasswordFile(char password[20], char* fileLogin[], char* filePassword[]){
    FILE *fp;
    fp = fopen(*filePassword, "a");
    fputs("\n",fp);
    for(int i = 0; i < strlen(password); i++)
        fputc(password[i], fp);
    fclose(fp);
}


bool login(char* fileLogin[], char* filePassword[], int *DoneLvl, int *id2){

    char DBLogin[200][20];
    char DBPassword[200][20];
    char login[20];
    char password[20];
    bool authorization = false;    
    const int width = 50;
    const int height = 20;
    int xLenth = 0;
    bool flag = true;
    int n = 1;
    int id = 0;

    readLoginFile(DBLogin, &xLenth, fileLogin, filePassword);
    readPasswordFile(DBPassword, fileLogin, filePassword); 
    DrawInputLogin(width, height, n);
    
    char x =' ';
    int i = 0, space;
    while(flag)
    {
        x=getch();
        space = x + '0';
        if(space == 80){ 
            flag = false;
        }
        else{
            login[i] = x;
            login[i+1] = '\0';
            DrawLogPswd(width, 5, i, x);
            i++;
        }
    }
    DrawInputPassword(width);

    flag = true;
    i=0;
    while(flag)
    {
        x=getch();
        space = x + '0';
        if(space == 80){ 
            flag = false;
        }
        else{
            password[i] = x;
            password[i+1] = '\0';
            DrawLogPswd(width, 7, i, x);
            i++;
        }
    }

    for(int i = 0; i <= xLenth; i++){
        if(equal(login,DBLogin[i])){
            if(equal(password,DBPassword[i])){
                authorization = true;
                id = i+1;
            }
        }
    }

    if(authorization){
        readDoneLvlFile(DoneLvl, id);
        *id2 = id;
    }
    return authorization;   
}

void registration(char* fileLogin[], char* filePassword[]){
    bool flag = true;
    const int width = 50;
    const int height = 20;
    int n = 1;
    char login[20];
    char password[20];
    DrawInputLogin(width, height, n);
    move(6, width/2-7);
    char x =' ';
    int i = 0, space;
    while(flag)
    {
        x=getch();
        space = x + '0';
        if(space == 80){ 
            flag = false;
        }
        else{
            login[i] = x;
            login[i+1] = '\0';
            DrawLogPswd(width, 5, i, x);
            i++;
        }
    }
    DrawInputPassword(width);

    flag = true;
    i=0;
    while(flag)
    {
        x=getch();
        space = x + '0';
        if(space == 80){ 
            flag = false;
        }
        else{
            password[i] = x;
            password[i+1] = '\0';
            DrawLogPswd(width, 7, i, x);
            i++;
        }
    }

    writeLoginFile(login, fileLogin, filePassword);
    encoding(password);
    writePasswordFile(password, fileLogin, filePassword);
}