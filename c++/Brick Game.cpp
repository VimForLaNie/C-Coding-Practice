#include <stdio.h>
#include <math.h>

short row,col;

void format(char input[], char output[]){
    short pointer = col - 1;
    short num = 0;
    short count = 0;
    for(char i = 58; i > -1; i--)
    {
        short charvalue = input[i] - '0';
        short power = pow(10, count);
        if(input[i] != ' ' && input[i] != 0){
            num += charvalue * power;
            count++;
        }
        else if(num > 0)
        {
            count = 0;
            output[pointer] = num;
            num = 0;
            pointer--;
        }
    }
    output[pointer] = num;
}

void fall (char array[],char obj[],short col){
    loop:
    char i = 0;
    while (i < row)
    {
        if ((array[i] == '0' || array[i] == '#') && obj[col] > 0)
        {
            array[i - 1] = '#';
            obj[col]--;
            goto loop;
        }
        i++;
    }
}

int main(){
    scanf("%hd %hd",&row,&col);
    char stage[row][col];
    char inputObj[59] = { 0 };
    char Object[col] = { 0 };
    for (char i = 0; i < row; i++)
    {
        scanf("%s",stage[i]);
    }
    scanf(" %[^\n]s", inputObj);
    format(inputObj, Object);
    for (char i = 0; i < col; i++)
    {

        char tempCol[row];
        for (char j = 0; j < row; j++)
        {
            tempCol[j] = stage[j][i];
        }

        fall(tempCol,Object,i);

        for (char z = 0; z < row; z++)
        {
            stage[z][i] = tempCol[z];
        }
    }
    for (char i = 0; i < row; i++)
    {
        for (char j = 0; j < col; j++)
        {
            printf("%c",stage[i][j]);
        }
        printf("\n");
    }
}