#include <stdio.h>

int main(int argc, char* argv[])
{
    int count = 0;
    int ananasCount = 0;
    int i = 0;
    char ananas[] = "ananas";
    char stringLeterts[5000];
    FILE *fp;
    char ch;
    char toLow ;
    char toLow2 ;
    int flag = 0;
    if ((fp=fopen(argv[1], "r"))==NULL) {
        // printf("Cannot open file.\n");
        return 0;
    }
    while((ch=fgetc(fp)) !=EOF) {
        // printf("%c", ch);
        stringLeterts[i] = ch;
        i++;
    }

    fclose(fp);
    //printf("%d", lenthString(stringLeterts));

    // цикл через всю строку
    for (int i = 0; i < 5000; i++)
    {
        if (stringLeterts[i] == EOF)
            break;
        // проверка на пробел
        if (stringLeterts[i] != ' '){
            //цикл через слово ананас
            for (int j = 0; j < 6; j++){
                //сравнить буквы
                toLow = (stringLeterts[i] >='A' && stringLeterts[i] <='Z') ? (stringLeterts[i] + 32) : (stringLeterts[i]);
                toLow2 = (stringLeterts[i+1] >='A' && stringLeterts[i+1] <='Z') ? (stringLeterts[i+1] + 32) : (stringLeterts[i+1]);

                if((toLow == 'a' && toLow2 == 'n') || flag == 1){
                    if (toLow == ananas[j]) {
                        flag  = 1;
                        ananasCount++;
                        i++;
                    }
                    else{
                        flag  = 0;
                        break;
                    }
                }
            }
        }
        //сравнить это слово ананас или нет
        if (ananasCount == 6)
        {
            //засчитать ананас
            count++;
        }
        //обнулить счетчик
        ananasCount = 0;
    }
    //printf("%d\n", count);
    int a =0, r;
    float c, b=0;
    if(count >= 10){
        a = count/ 10;
        c = count/ 10.0;
        b = (c+0.0-a)*10;
        r=b;

        char symb1;
        char symb2;
        symb1 = a+'0';
        symb2 = r+'0';
        fp=fopen(argv[1], "w");
        fputc(symb1, fp );
        fputc(symb2, fp );
        fclose(fp);
    }

    else{
        char symb;
        symb = count+'0';
        fp=fopen(argv[1], "w");
        fputc(symb, fp );
        fclose(fp);
    }
    return 0;
}