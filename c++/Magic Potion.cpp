#include <stdio.h>
#include <math.h>

void Potion(int arr[],int l, int r, int arr_size)
{
    int Lpointer = 0;
    int Rpointer = arr_size - 1;
    while (l > 0)
    {
        arr[Lpointer] = 0;
        l--;
        Lpointer++;
    }
    while (r > 0)
    {
        arr[Rpointer] = 0;
        r--;
        Rpointer--;
    }
}

int Sum(int arr[])
{
    int result = 0;
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        result += arr[i];
    }
    return result;
}

void format(char arr[],int out[],int arr_size,int out_size)
{
    char count = 0;
    int pointer = out_size - 1;
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
                pointer--;
                count = 0;
            }
            else if(arr[i - 1] >= '0' && arr[i - 1] <= '9')
            {
                count++;
            }
        } 
    }
}

void nPotion(int arr[], int out[], int count, int arr_size,int k)
{
    int max_nPotion = arr_size - 1;
    int curr_nPotion = max_nPotion / 2;
    int left_nPotion = 0;
    int potion_arr[arr_size];
    int k_arr[curr_nPotion];
    int k_pointer = 0;
    repeat:
    if(left_nPotion > curr_nPotion)
    {
        if(Sum(k_arr) / max_nPotion > k){
            curr_nPotion = (curr_nPotion + max_nPotion) / 2;
        }
        else{
            curr_nPotion *= 0.5;
        }
        int k_arr[curr_nPotion] = { 0 };
    }
    for (size_t i = 0; i < arr_size; i++)
    {
        potion_arr[i] = arr[i];
    }
    Potion(potion_arr,left_nPotion,curr_nPotion - left_nPotion,arr_size);
    k_arr[k_pointer] = Sum(potion_arr);
    k_pointer++;
    if(k_arr[k_pointer - 1] == k)
    {
        left_nPotion++;
        out[count] = curr_nPotion;
        count++;
    }
    else
    {
        left_nPotion++;
    }
    goto repeat;
}

int main() 
{
    int n,k;
    scanf(" %d %d",&n,&k);
    char rawInput[2*n - 1] = { 0 };
    scanf(" %[^\n]s",rawInput);
    int array[n] = { 0 };
    format(rawInput, array,2*n - 1,n);
    int output[n] = { 0 };
    int count = 0;
    nPotion(array,output,count,n,k);
    for (size_t i = 0; i < sizeof(output)/sizeof(output[0]); i++)
    {
        printf("%d ",output[i]);
    }
    printf("break");
    return 0;
}