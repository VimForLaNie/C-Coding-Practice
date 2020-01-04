#include <stdio.h>
#include <cstring>
#include <math.h>

void format(char arr[],int out[], int arr_size, int out_size)
{
    char count = 0;
    int pointer = 0;
    int num = 0;

    for (int i = arr_size - 1; i >= 0; i--)
    {
        if(arr[i] >= '0' && arr[i] <= '9')
        {
            num += (arr[i] - '0') * pow(10,count);
            if(arr[i - 1] == ' ' || i == 0)
            {
                out[pointer] = num;
                num = 0;
                pointer++;
                count = 0;
            }
            else if(arr[i - 1] >= '0' && arr[i - 1] <= '9')
            {
                count++;
            }
        } 
    }
}

int main() 
{
    int n;
    long k;
    scanf(" %i %li",&n,&k);
    char rawInput[1000000] = { 0 };
    scanf(" %[^\n]s",rawInput);
    int array[n] = { 0 };

    format(rawInput, array,100000,n);
    
    int adder;
    int output[n] = { 0 };
    int count = 0;
    int d[n] = { 0 };
    int min = 999999999;

    for (size_t i = 0; i < n; i++)
    {
        adder = array[i];
        for (size_t x = 0; x <= i; x++)
        {
            d[x] += adder;
            if(d[x] == k){
                output[count] = (n - 1) - x;
                count++;
            }
            if(output[x] < min && i == n - 1 && x < count){
                min = output[x];
            }
        }
    }
    if(d[0] == k){
        min = 0;
    }
    printf("%i %i",count,min);
    main();
    return 0;
}