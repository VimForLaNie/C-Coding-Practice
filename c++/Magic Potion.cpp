#include <stdio.h>
#include <cstring>
#include <math.h>

void format(char arr[],long int out[],long int arr_size,long int out_size)
{
    char count = 0;
    long int pointer = 0;
    long int num = 0;

    for (long int i = arr_size - 1; i >= 0; i--)
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

long int FindCount(long int start,long int arr[],long long k,const short key){
    long int adder;
    long int output[start] = { 0 };
    long int count = 0;
    int d[start] = { 0 };
    int min = 999999999;

    for (size_t i = 0; i < start; i++)
    {
        adder = arr[i];
        for (size_t x = 0; x <= i; x++)
        {
            d[x] += adder;
            if(d[x] == k){
                output[count] = start - x - 1;
                count++;
            }
            if(output[count - 1] < min && x == i){
                min = output[count - 1];
            }
        }
    }
    if(output[count] < min && d[start - count] == k){
        min = output[count];
    }
    if(key == 1){
        return count;
    }
    else if (key == 0)
    {
        return min;
    }
}

int main() 
{
    long int n;
    long long k;
    scanf(" %lli %lli",&n,&k);
    char rawInput[1000000] = { 0 };
    scanf(" %[^\n]s",rawInput);
    long int array[n] = { 0 };

    format(rawInput, array,100000,n);
    
    long int x = n / 2;
    while (FindCount(x,array,k,1) > 0)
    {
        x = (x + n)/ 2;
        if(x == n - 1){
            x++;
            goto end;
        }     
    }
    while (FindCount(x,array,k,1) == 0)
    {
        x = x - (x / 2);
        if(x == 1){
            x = (n + (n /2)) / 2;
            break;
        }
    }
    while (FindCount(x,array,k,1) >= 0)
    {
        x = (x + n)/ 2;
        if(x == n - 1){
            x++;
            goto end;
        }   
    }
    end:
    long int c = FindCount(x,array,k,1);
    long int m = FindCount(x,array,k,0);
    printf("%i %i",c,m);
    return 0;
}