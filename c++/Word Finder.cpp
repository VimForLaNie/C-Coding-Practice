#include <stdio.h>

void format(char str[],char num[]){
    char pointer = 0;
    for (size_t i = 0; i < sizeof(str)/sizeof(str[0]); i++)
    {
        if(str[i + 1] = ' '){
            num[pointer] = str[i] - '0';
            i++;
        }
        else if (str[i + 2] = ' ')
        {
            num[pointer] = ((str[i] - '0') * 10) + (str[i] - '0');
            i += 2;
        }
    }
}

int main(){
    char rawInput[6] = { 0 };
    char input[2];
    fgets(rawInput, 5 + 2, stdin);
    format(rawInput,input);
    return 0;
}