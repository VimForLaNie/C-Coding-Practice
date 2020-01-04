#include <stdio.h>
#include <cstring>
#include <math.h>

int global_min;

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

int Count(int arr[],int pivot,int k,char key){

    int min = 99999999;
    int adder;
    int count = 0;
    int d[pivot] = { 0 };
    for (int i = 0; i < pivot; i++)
    {
        adder = arr[i];
        for (int x = 0; x <= i; x++)
        {
            d[x] += adder;
            if(d[x] == k){
                count++;
                if(min > x){
                    min = x;
                }
            }
        }
    }
    switch (key)
    {
    case 'c':
        return count;
        break;
    case 'm':
        return min;
    default:
        break;
    }
    return count;
}

int main() 
{
    char c = 'c';
    char m = 'm';
    int n;
    long k;
    scanf(" %i %li",&n,&k);
    char rawInput[1000000] = { 0 };
    scanf(" %[^\n]s",rawInput);
    int array[n] = { 0 };

    format(rawInput, array,100000,n);

    printf("%i %i",Count(array,n,k,c),Count(array,n,k,m));
    return 0;
}