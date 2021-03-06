#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include "hangman.h"

int get_word(char secret[]){
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        long int random = (rand() % size) + 1;
        fseek(fp, random, SEEK_SET);
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]) {
	int index, size = 0;
	const char* symbol;

	for (index = 0; index < strlen(secret); index++)
	{
		symbol = strchr(letters_guessed, secret[index]);
		size += (symbol != NULL) ? 1 : 0;
		if (size - 1 != index) break;
	}
	return (size == strlen(secret)) ? 1 : 0;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[])
{
	int index;
	const char* symbol;

	for (index = 0; index < strlen(secret); index++)
	{
		symbol = strchr(letters_guessed, secret[index]);
		guessed_word[index] = (symbol != NULL) ? secret[index] : '_';
		//if (symbol != NULL)
		//	guessed_word[index] = secret[index];
	}
	guessed_word[strlen(secret)] = '\0';
}

void get_guessed_word2(const char secret[], const char letters_guessed[], char guessed_word[])
{
	int index;
	const char* symbol;

	for (index = 0; index < strlen(secret); index++)
	{
		symbol = strchr(letters_guessed, secret[index]);
		//guessed_word[index] = (symbol != NULL) ? secret[index] : '_';
		if (symbol != NULL)
			guessed_word[index] = secret[index];
	}
	guessed_word[strlen(secret)] = '\0';
}

void get_available_letters(const char letters_guessed[], char available_letters[])
{
	char alphabet[] = { "abcdefghijklmnopqrstuvwxyz" };
	//strcpy(alphabet, available_letters);

	int index, index2 = 0;
	const char* symbol;

	for (index = 0; index < strlen(alphabet); index++)
	{
		symbol = strchr(letters_guessed, alphabet[index]);
		if (symbol == NULL) {
			available_letters[index2] = alphabet[index];
			index2++;
		}
	}
	available_letters[26 - strlen(letters_guessed)] = '\0';
	//available_letters[index2] = '\0';
}

void get_available_letters2(const char letters_guessed[], char available_letters[])
{
	char alphabet[] = { "abcdefghijklmnopqrstuvwxyz" };
	strcpy(alphabet, available_letters);

	int index, index2 = 0;
	const char* symbol;

	for (index = 0; index < strlen(alphabet); index++)
	{
		symbol = strchr(letters_guessed, alphabet[index]);
		if (symbol == NULL) {
			available_letters[index2] = alphabet[index];
			index2++;
		}
	}
	//available_letters[26 - strlen(letters_guessed)] = '\0';
	available_letters[index2] = '\0';
}

void hangman(const char secret[]) {

	int iterator;
	int count_attempts = 8; // ???????????????????? ??????????????
	char available_letters_alphabet[] = { "abcdefghijklmnopqrstuvwxyz" }; // ?????????????????? ??????????
	char enter_symbol[15]; // ???????????? / ???????????? ???? ?????? ???????????? ????????????????????????
	char result_word[15]; // ???????????????????? ??????????
	int is_letter = 1;

	/// ?????????????????????????? ??????????????
	char result[30];
	get_available_letters("arpstxgoieyu", result);
	char result2[30];
	get_guessed_word("container", "arpstxgoieyu", result2);
	///-----------------------

	/// <summary>
	/// ?????????????????? result_word '_' ???? ?????????? secret
	/// </summary>
	/// <param name="secret"></param>
	for (iterator = 0; iterator < strlen(secret); iterator++)
		result_word[iterator] = '_';
	result_word[strlen(secret)] = '\0';

	printf("Welcome to the game, Hangman!\nI am thinking of a word that is %ld letters long.", strlen(secret));

	while (!is_word_guessed(secret, result_word) && count_attempts > 0)
	{
		is_letter = 1;
		/// <summary>
		/// ??????????
		/// </summary>
		printf("\n-------------\n");
		printf("You have %d guesses left.\n", count_attempts);
		printf("Available letters: %s", available_letters_alphabet);
		printf("\nPlease guess a letter: ");
		
		/// <summary>
		/// ???????????? ?????????????? ?? ????????????????????
		/// </summary>
		scanf("%s", enter_symbol);

		/// <summary>
		/// ?????????????????? ???????? ?????????? ???????????? ?????????????????? ??????????
		/// </summary>
		/// <param name="secret"></param>
		if (is_word_guessed(secret, enter_symbol)) {
			printf("Congratulations, you won!\n");
			break;
		}

		/// <summary>
		/// ???????????????? ???????????????? ???? ???????????? ????????????
		/// </summary>
		/// <param name="secret"></param>
		else{
			for (iterator = 0; iterator < strlen(enter_symbol); iterator++)
			{
				if (!isalpha(enter_symbol[iterator])) {
					is_letter = 0;
					printf("Oops! '%c", enter_symbol[iterator]);
					printf("' is not a valid letter:");
					for (iterator = 0; iterator < strlen(result_word); iterator++)
					{
						printf(" %c", result_word[iterator]); //       --??????????--
					}
					break;
				}
			}
			if(is_letter)
			{
				/// <summary>
				/// ?????????????????? ?? ???????????? ??????????????
				/// </summary>
				/// <param name="secret"></param>
				for (iterator = 0; iterator < strlen(enter_symbol); iterator++)
				{
					enter_symbol[iterator] = tolower(enter_symbol[iterator]);
				}
				/// <summary>
				/// ???????????????????? ???????????? ???? ?????? ?????????? ??????????
				/// </summary>
				/// <param name="secret"></param>
				if (!is_word_guessed(enter_symbol, available_letters_alphabet)) {
					printf("Oops! You've already guessed that letter:");
					for (iterator = 0; iterator < strlen(result_word); iterator++)
					{
						printf(" %c", result_word[iterator]);//       --??????????--
					}
				}
				/// <summary>
				/// ???????? ???? ???????????? ???? ???????????? ??????
				/// </summary>
				/// <param name="secret"></param>
				else
				{
					get_available_letters2(enter_symbol, available_letters_alphabet); // ?????????????? ???????????? ?? available_letters_alphabet
					get_guessed_word2(secret, enter_symbol, result_word); // ?? ???????????????????? result_word ?????????????? enter_symbol ?????????????? ???????? ?? secret

					const char* ach;
					ach = strchr(secret, enter_symbol[0]);

					if (ach != NULL) {
						printf("Good guess:");
						for (iterator = 0; iterator < strlen(result_word); iterator++)
						{
							printf(" %c", result_word[iterator]);//       --??????????--
						}
						if (is_word_guessed(result_word, secret))
						{
							printf("\n-------------\n");
							printf("Congratulations, you won!\n");
							break;
						}
					}
					else
					{
						printf("Oops! That letter is not in my word:");
						for (iterator = 0; iterator < strlen(result_word); iterator++)
						{
							printf(" %c", result_word[iterator]);//       --??????????--
						}
						count_attempts--;
					}
					if (count_attempts == 0) {
						printf("\n-------------\n");
						printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
						break;
					}
				}
			}
		}
	}
}