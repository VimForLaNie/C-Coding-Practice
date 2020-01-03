#include <stdio.h>

char table[25][25];

void format(char str[],char num[]){
    size_t pointer = 0;
    size_t i = 0;
    while (i < sizeof(str)/sizeof(str[0]))
    {
        if(str[i] >= '0' && str[i] <= '9' && str[i + 1] == ' ' || str[i + 1] == '\n'){
            num[pointer] = str[i] - '0';
            pointer++;
            i += 2;
        }
        if (str[i] >= '0' && str[i] <= '9' && str[i + 1] >= '0' && str[i + 1] <= '9');
        {
            num[pointer] = (str[i] - '0') * 10 + (str[i + 1] - '0'); 
            pointer++;
            i += 3;
        }
    }
}

void search(char word[],char cord[],char row,char col){
    //search fo initial character in word;
    size_t Spointer = 0;
    char starter[50][2];
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (table[i][j] == word[0])
            {
                starter[Spointer][0] = i;
                starter[Spointer][1] = j;
                Spointer++;
            }
        }
    }
    //check top
    //check down
    //check left
    //check right
    //check top-left
    //check top-right
    //check down-left
    //check down-right
}

int main(){
    //getting input
    char rawInput[5] = { 0 };
    char input[2] = { 0 };
    fgets(rawInput,5 + 5,stdin);
    format(rawInput,input);
    //getting word table
    for (size_t i = 0; i < input[0]; i++)
    {
        fgets(table[i],input[0] + 5,stdin);
    }
    //getting nWord
    char nWord;
    scanf("%hd",&nWord);
    //getting WordList
    char WordList[nWord][15];
    for (size_t i = 0; i < nWord; i++)
    {
        fgets(WordList[i],nWord + 5,stdin);
    }
    //searching . . .
    char cord[nWord][2];
    for (size_t i = 0; i < nWord; i++)
    {
        search(WordList[i],cord[i],input[0],input[1]);
    }
    //printing
    for (size_t i = 0; i < nWord; i++)
    {
        printf("%hd %hd\n",cord[0],cord[1]);
    }
    
    return 0;
}