#include "hangman.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main(){

    srand(time(0));
    char secret_slovo[15];

    int start = get_word(secret_slovo);
    hangman(secret_slovo);
    //hangman("qwerty");

    return start;
}
