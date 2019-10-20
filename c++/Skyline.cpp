#include <stdio.h>
using namespace std;

short nTower;

void format(char input[],short output[]) {
    short pointer = 0;
    for (char i = 0; i < 8; i++)
    {
        if (input[i] >= 48 && input[i] <= 57 && (input[i + 1] == 0 || input[i + 1] == ' '))
        {
            output[pointer] = input[i] - '0';
            pointer++;
        }
        else if (input[i] >= 48 && input[i] <= 57 && (input[i + 1] != 0 || input[i + 1] != ' '))
        {
            output[pointer] = ((input[i] - '0') * 10) + (input[i + 1] - '0');
            pointer++;
            i++;
        }
        else if (input[i] == 42)
        {
            break;
        }
    }
}

void draw(short start,short height, short end, short output[]){
    for(short i = start - 1; i < end - 1; i++){
        if(output[i] < height){
            output[i] = height;
        }
    }
}

short max(short array[]){
    short a = 0;
    for (char i = 0; i < nTower; i++)
    {
        if(array[i] > a){
            a = array[i];
        }
    }
    return a;
}

int main () {
    scanf("%hd",&nTower);

    short Tower[nTower][3] = { 0 };

    for (short i = 0; i < nTower; i++)
    {
        char text[10] = { 0 };
        scanf(" %[^\n]s",text);
        format(text,Tower[i]);
    }

    short temp[nTower];
    for (char i = 0; i <= nTower; i++)
    {
        temp[i] = Tower[i][2];
    }
    short Max = max(temp);

    short skyline[Max] = { 0 };
    
    for (short i = 0; i < nTower; i++)
    {
        draw(Tower[i][0],Tower[i][1],Tower[i][2],skyline);
    }
    
    for (short i = 0; i < Max; i++)
    {
        printf("%hd ",skyline[i]);
    }
    printf("\n");
    short curr;
    short prev;
    for (short i = 1; i <= Max; i++)
    {
        prev = skyline[i - 2];
        curr = skyline[i - 1];
        if(curr != prev){
            printf("%hd ",i);
            printf("%hd ",curr);
        }
    }
    
}