#include <stdio.h>

int lenthString(const char* str) {
    for (const char* c = str;;c++) if (!*c) return c-str;
}

int main(int argc, char* argv[])
{
    int i = 0, a = 0;
    int startCount = 0;
    int stopCount = 0;

    char start[] = "START";
    char stop[] = "STOP";
    char stringLeterts[5000];
    char secondStringLeterts[5000];
    char result[5000];
    FILE *fp;
    char ch;

    if ((fp=fopen(argv[1], "r"))==NULL) {
        printf("Cannot open file.\n");
        return 0;
    }

    while((ch=fgetc(fp)) !=EOF) {
        stringLeterts[i] = ch;
        secondStringLeterts[i] = ch;
        i++;
    }
    int lenthStringLeters = lenthString(stringLeterts);
    // цикл через всю строку
    for (int i = 0; i < lenthStringLeters; i++)
    {
        // проверка на конец строки
        if (stringLeterts[i] == EOF)
            break;

        // проверка на S
        if(startCount != 5)
            if (stringLeterts[i] == 'S') {
                //цикл через слово START
                for (int j = 0; j < 5; j++) {
                    //сравнить буквы
                    if (stringLeterts[i] == start[j]) {
                        // добавить счетчику +1
                        startCount++;
                        // добавить счетчику +1
                        i++;
                    }
                    else {
                        // установить счетчикам значение 0
                        startCount = 0;
                        break;
                    }
                }
            }
        // проверка на S
        if (stringLeterts[i] == 'S') {
            //цикл через слово STOP
            for (int j = 0; j < 4; j++) {
                //сравнить буквы
                if (stringLeterts[i] == stop[j]) {
                    // добавить счетчику +1
                    stopCount++;
                    // добавить счетчику +1
                    i++;
                }
                else {
                    // установить счетчикам значение 0
                    stopCount = 0;
                    break;
                }
            }
        }
        if (stopCount == 4)
        {
            break;
        }
        //сравнить это слово START или нет
        if (startCount == 5)
        {
            //stringLeterts[i] = '#';
            i++;
            while (stringLeterts[i] != ' ')
                i++;
            i++;
            //------------------------
            int zap = i;
            if (stringLeterts[i] == 'S') {
                //цикл через слово STOP
                for (int j = 0; j < 4; j++) {
                    //сравнить буквы
                    if (stringLeterts[i] == stop[j]) {
                        // добавить счетчику +1
                        stopCount++;
                        // добавить счетчику +1
                        i++;
                    }
                    else {
                        // установить счетчикам значение 0
                        stopCount = 0;
                        //stringLeterts[i-1] = '&';
                        i = zap;
                        break;
                    }
                }
            }
            if (stopCount == 4)
            {
                break;
            }

            //-------------
            //stringLeterts[i] = '#';
            while (stringLeterts[i] != ' ') {
                stringLeterts[i] = '&';
                i++;

            }
            stringLeterts[i] = '&';
        }
    }
    //printf("%s\n", stringLeterts);
    for (int i = 0; i < lenthStringLeters; i++)
    {
        // проверка на конец строки
        if (stringLeterts[i] == EOF)
            break;
        // найти символы которые нужно оставить
        if(stringLeterts[i] == '&'){
            // присвоить переменной result значение из secondStringLeterts которые = &
            result[a] = secondStringLeterts[i];
            a++;
        }
    }
    // узнать длину результата
    int lenthResultLeters = lenthString(result);
    // открыть файл для записи
    fp=fopen(argv[2], "w");
    for (int i = 0; i < lenthResultLeters-1; i++)
    {
        // проверка на конец строки
        if (result[i] == EOF)
            break;
        fputc(result[i], fp );
    }
    fclose(fp);

    //printf("%s\n", stringLeterts);
    //printf("%s\n", result);
    return 0;
}