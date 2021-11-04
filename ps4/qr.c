#include <string.h>
#include <stdio.h>
#include <stdbool.h>


void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);

void encode_string(const char string[], bool bytes[strlen(string) + 1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);

int main()
{
/*
    printf("\n Task:1 \n");///
	bool bits1[8];
	encode_char('A', bits1);
	for (int i = 0; i < 8; i++) {
		printf("%d", bits1[i]);
	}
	printf("\n");
	// prints: 01000001

	bool bits2[8] = { 0,1,0,0,0,0,0,1 };
	printf("%c\n", decode_byte(bits2));
	// prints: A

    printf("\n Task:2 \n");

	char* text = "zvlastne";
    const int len = strlen(text);
    bool bytes1[len+1][8];
    encode_string(text, bytes1);
    for(int j = 0; j <= len; j++){
        printf("%c: ", text[j]);
        for(int i = 0; i < 8; i++){
            printf("%d", bytes1[j][i]);
        }
        printf("\n");
    }

    bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
    };
    char string[7];
    decode_bytes(7, bytes2, string);
    printf("%s\n", string);
*/
    // prints: Hello!

    printf("\n Task:3 \n");

   int length = 6+1, cols = 4, offset = 2;
    bool bytes1[6+1][8] = {
        {0, 1, 1, 1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    bool blocks1[offset*8][cols];
    bytes_to_blocks(cols, offset, blocks1, length, bytes1);
    for(int j = 0; j < offset*8; j++){
        for(int i = 0; i < cols; i++){
            printf("%d ", (blocks1[j][i] == true) ? 1 : 0);
        }
        printf("\n");
        if(j % 8 == 7){
            printf("\n");
        }
    }
/*
    bool blocks2[2*8][3] = {
        {0,0,0},
        {1,1,1},
        {0,1,1},
        {0,0,0},
        {0,1,1},
        {0,0,1},
        {0,0,1},
        {1,0,1},
        {0,0,0},
        {1,0,0},
        {1,0,0},
        {0,0,0},
        {1,0,0},
        {0,0,0},
        {1,0,0},
        {0,0,0}
    };
    bool bytes22[length][8];
    blocks_to_bytes(3, 2, blocks2, length, bytes22);
    for(int j = 0; j < length; j++){
        for(int i = 0; i < 8; i++){
            printf("%d", bytes22[j][i]);
        }
        printf("\n");
    }
*/
}
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    for(int i = 0; i < offset*8; i++)
        for(int j = 0; j < cols; j++)
            blocks[i][j] = 0;

    int k = 0, l = 0;
    for(int x = 0; x < offset; x++){
        for(int i = 0; i < cols; i++){
            if(i+k>=rows)break;
            for(int j = 0; j < 8; j++){
                blocks[j+l][i] = bytes[i+k][j]; // [строка - ] [колона | ] 
            }
        }
        k+=cols;
        l+=8;
    }
}
void encode_char(const char character, bool bits[8])
{
	int c, power, a = 0;
	c = character;
	for (power = 7; power + 1; power--, a++)
		if (c >= (1 << power))
		{
			c -= (1 << power);
			bits[a] = 1;
		}
		else {
			bits[a] = 0;
		}
}

char decode_byte(const bool bits[8])
{
	char parsed = 0;
	for (int i = 0; i < 8; i++)
		if (bits[i] == 1)
			parsed |= 1 << (7 - i);
	return parsed;
}

void encode_string(const char string[], bool bytes[strlen(string) + 1][8])
{
    int i , c, power, a = 0,  n = strlen(string);
    for (i = 0; i <= n; i++)
    {
        a = 0;
        c = string[i];
        for (power = 7; power + 1; power--, a++){
            if (c >= (1 << power))
            {
                c -= (1 << power);
                bytes[i][a] = 1;
            }
            else {
                bytes[i][a] = 0;
            }
        }
   }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
    char parsed = 0;
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < 8; j++)
            if (bytes[i][j] == 1)
                parsed |= 1 << (7 - j);
        string[i] = parsed;
        parsed = 0;
    }  
}



void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 8; j++)
            bytes[i][j] = 0;

    int k = 0, l = 0;
    for(int x = 0; x < offset; x++){
        for(int i = 0; i < cols; i++){
            if(i+k>=rows)break;
            for(int j = 0; j < 8; j++){
                bytes[i+k][j] = blocks[j+l][i]; // [строка - ] [колона | ]
            }
        }
        k+=cols;
        l+=8;
    }
}