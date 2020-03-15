#include <stdio.h>
#include <math.h>
#include <time.h>

void quicksort(int arr[],short arr_size){
    if(arr_size > 31){
        short m = rand() % arr_size;
        int temp_arr_l[arr_size] = { 0 };
        int temp_arr_r[arr_size] = { 0 };
        short Lpointer = 0,Rpointer = 0;
        for (size_t i = 0; i < arr_size; i++)
        {
            if(arr[i] <= arr[m]){
                temp_arr_l[Lpointer] = arr[i];
                Lpointer++;
            }
            else if(arr[i] > arr[m]){
                temp_arr_r[Rpointer] = arr[i];
                Rpointer++;
            }
        }
        int arr_l[Lpointer] = { 0 };
        int arr_r[Rpointer] = { 0 };
        for (size_t i = 0; i < Lpointer; i++)
        {
            arr_l[i] = temp_arr_l[i]; 
        }
        for (size_t i = 0; i < Rpointer; i++)
        {
            arr_r[i] = temp_arr_r[i]; 
        }
        quicksort(arr_l,Lpointer);
        quicksort(arr_r,Rpointer);
        for (size_t i = 0; i < Lpointer; i++)
        {
            arr[i] = arr_l[i];
        }
        for (size_t i = Lpointer; i < arr_size; i++)
        {
            arr[i] = arr_r[i - Lpointer];
        }
    }
    else{
        short pointer = 0;
        size_t P;
        for(P = 1; P <= arr_size; P++){
            while(pointer <= P && pointer != 0){
                if(arr[pointer] < arr[pointer - 1]){
                    int holder = arr[pointer];
                    arr[pointer] = arr[pointer - 1];
                    arr[pointer - 1] = holder;
                }
                pointer--;
            }
        pointer = P;
        }   
    }
}

int main(){
    short array_size;
    printf("Insert your array size : ");
    scanf("%hd",&array_size);
    int array[array_size] = { 0 };  
    printf("Array :");
    for (size_t i = 0; i < array_size; i++)
    {
        array[i] = rand();
        printf(" %d",array[i]);
    }
    printf("\n\n");
    clock_t start = clock();
    quicksort(array,array_size);
    clock_t end = clock();
    double timespent = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Sorted Array :");
    for (size_t i = 0; i < array_size; i++)
    {
        printf(" %d",array[i]);
    }
    printf("\n");
    printf("time used in sorting : %f",timespent);
    return 0;
}