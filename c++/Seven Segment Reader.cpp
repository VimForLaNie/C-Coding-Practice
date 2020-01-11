#include <stdio.h>
#include <math.h>

unsigned char length1;
unsigned char length2;

long long format(unsigned char array[], short size)
{
    long long num = 0;
    for (short i = 0; i < size; i++)
    {
        num += array[i] * pow(10, size - i - 1);
    }
    return num;
}
// _
int main()
{
    char input[5];
    fgets(input, 5 + 2, stdin);
    sscanf(input, "%d %d", &length1, &length2);
    short size1 = length1 * 3;
    short size2 = length2 * 3;
    char text1[3][size1] = {' '};
    char text2[3][size2] = {' '};
    unsigned char num1[length1] = {0};
    unsigned char num2[length2] = {0};
    for (size_t i = 0; i < 3; i++)
    {
        fgets(text1[i], 30 + 2, stdin);
    }
    for (size_t i = 0; i < 3; i++)
    {
        fgets(text2[i], 30 + 2, stdin);
    }
    size_t pointer = 0;
    for (size_t i = 1; i < size1; i += 4)
    {
        if (text1[0][i] == '_')
        { //&& text1[0][i - 1] == ' ' && text1[0][i + 1] == ' '
            if (text1[1][i + 1] == '|' && text1[1][i - 1] != '|')
            {
                if (text1[2][i - 1] == '|')
                {
                    num1[pointer] = 2;
                    pointer++;
                }
                else if (text1[2][i] == '_')
                {
                    num1[pointer] = 3;
                    pointer++;
                }
                else
                {
                    num1[pointer] = 7;
                    pointer++;
                }
            }
            else if (text1[1][i - 1] == '|' && text1[1][i + 1] != '|')
            {
                if (text1[2][i - 1] == '|')
                {
                    num1[pointer] = 6;
                    pointer++;
                }
                else
                {
                    num1[pointer] = 5;
                    pointer++;
                }
            }
            else
            {
                if (text1[2][i - 1] == ' ')
                {
                    num1[pointer] = 9;
                    pointer++;
                }
                else if (text1[1][i] == '_')
                {
                    num1[pointer] = 8;
                    pointer++;
                }
                else
                {
                    num1[pointer] = 0;
                    pointer++;
                }
            }
        }
        else
        {
            if (text1[1][i] == '_')
            {
                num1[pointer] = 4;
                pointer++;
            }
            else
            {
                num1[pointer] = 1;
                pointer++;
            }
        }
    }
    pointer = 0;
    for (size_t i = 1; i < size2; i += 4)
    {
        if (text2[0][i] == '_')
        {
            if (text2[1][i + 1] == '|' && text2[1][i - 1] != '|') //&& text2[0][i - 1] == ' ' && text2[0][i + 1] == ' '
            {
                if (text2[2][i - 1] == '|')
                {
                    num2[pointer] = 2;
                    pointer++;
                }
                else if (text1[2][i] == '_')
                {
                    num2[pointer] = 3;
                    pointer++;
                }
                else
                {
                    num2[pointer] = 7;
                    pointer++;
                }
            }
            else if (text2[1][i - 1] == '|' && text2[1][i + 1] != '|')
            {
                if (text2[2][i - 1] == '|')
                {
                    num2[pointer] = 6;
                    pointer++;
                }
                else
                {
                    num2[pointer] = 5;
                    pointer++;
                }
            }
            else
            {
                if (text2[2][i - 1] == ' ')
                {
                    num2[pointer] = 9;
                    pointer++;
                }
                else if (text2[1][i] == '_')
                {
                    num2[pointer] = 8;
                    pointer++;
                }
                else
                {
                    num2[pointer] = 0;
                    pointer++;
                }
            }
        }
        else
        {
            if (text2[1][i] == '_')
            {
                num2[pointer] = 4;
                pointer++;
            }
            else
            {
                num2[pointer] = 1;
                pointer++;
            }
        }
    }
    long long ans1 = format(num1, length1);
    long long ans2 = format(num2, length2);
    printf("%lli", ans1 + ans2);
    return 14717;
}