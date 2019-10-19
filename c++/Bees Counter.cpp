#include <stdio.h>
#include <math.h>

short count = 0;

void format(char input[], short output[])
{
    short pointer = 0;
    for (char i = 0; i < 65; i++)
    {
        if (input[i] >= 47 && input[i] <= 58)
        {
            if (input[i + 1] == ' ')
            {
                output[pointer] = input[i] - '0';
                pointer++;
            }
            else
            {
                output[pointer] = ((input[i] - '0') * 10) + (input[i + 1] - '0');
                pointer++;
                i++;
            }
        }
        else if (input[i] == '-')
        {
            break;
        }
    }
    count = pointer + 1;
}

void sub_breed(short Start,short End,short Bee[]){
    if(Start < End){
        short nW = Bee[1];
        short nS = Bee[2];
        Bee[1] = 1 + nS + nW;
        Bee[2] = nW;
        Start++;
        sub_breed(Start,End,Bee);
    }
}

void breed(short year,short Work[],short Total[], short index){
    short Bee[3] = {1,1,0};
    sub_breed(0,year,Bee);
    for (char i = 0; i < 3; i++)
    {
        Total[index] += Bee[i];
    }
    Work[index] = Bee[1];
}

int main()
{
    char in[65] = {0};
    short input[24] = {0};
    scanf(" %[^\n]s", in);
    format(in, input);
    short Work[count] = {0};
    short Total[count] = {0};
    for (char i = 0; i < count - 1; i++)
    {
        breed(input[i], Work, Total, i);
        printf("%hd %hd", Work[i], Total[i]);
        printf("\n");
    }
    return 0;
}