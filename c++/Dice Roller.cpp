#include <stdio.h>

using namespace std;

char countD = 0;

void swap(short a, short b, short ar[])
{
    short holder = ar[a];
    ar[a] = ar[b];
    ar[b] = holder;
}

void F(short dice[6], short result[], char pointer)
{
    swap(0, 3, dice);
    swap(3, 1, dice);
    swap(3, 5, dice);
    result[pointer] = dice[1];
}

void B(short dice[6], short result[], char pointer)
{
    swap(5, 3, dice);
    swap(0, 3, dice);
    swap(0, 1, dice);
    result[pointer] = dice[1];
}

void L(short dice[6], short result[], char pointer)
{
    swap(0, 4, dice);
    swap(2, 4, dice);
    swap(5, 4, dice);
    result[pointer] = dice[1];
}

void R(short dice[6], short result[], char pointer)
{
    swap(0, 2, dice);
    swap(2, 5, dice);
    swap(5, 4, dice);
    result[pointer] = dice[1];
}

void C(short dice[6], short result[], char pointer)
{
    swap(2, 3, dice);
    swap(1, 4, dice);
    swap(2, 4, dice);
    result[pointer] = dice[1];
}

void D(short dice[6], short result[], char pointer)
{
    swap(1, 2, dice);
    swap(2, 3, dice);
    swap(3, 4, dice);
    result[pointer] = dice[1];
}

int main()
{
    short i = 0;
    short j = 0;
    scanf(" %d", &countD);
    short result[countD] = {0};
    char command[1000] = {0};
    while (i < countD)
    {
        scanf("%s", command);
        short dice[] = {1, 2, 3, 5, 4, 6};
        for (j = 0; j < 1000; j++)
        {
            switch (command[j])
            {
            case 'F':
                F(dice, result, i);
                break;
            case 'B':
                B(dice, result, i);
                break;
            case 'L':
                L(dice, result, i);
                break;
            case 'R':
                R(dice, result, i);
                break;
            case 'C':
                C(dice, result, i);
                break;
            case 'D':
                D(dice, result, i);
                break;
            default:
                goto exit;
            }
        }
    exit:
        i++;
        j = 0;
    }
    for (i = 0; i < countD; i++)
    {
        printf("%d ", result[i]);
    }
}