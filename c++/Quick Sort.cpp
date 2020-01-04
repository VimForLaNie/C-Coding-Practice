#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int a,int b, int arr[]){
    int h = arr[a];
    arr[a] = arr[b];
    arr[b] = h;
}
int partition(int arr[], int start, int end) 
{ 
    int pivot = arr[end];
    int i = (start - 1); 
    for (int j = start; j <= end - 1; j++) { 
        if (arr[j] <= pivot) { 
            i++;
            swap(i,j,arr); 
        } 
    } 
    swap(i + 1,end,arr); 
    return (i + 1); 
} 
int partition_r(int arr[], int start, int end) 
{ 
    srand(time(NULL)); 
    int random = start + rand() % (end - start); 
    swap(random,end,arr); 
    return partition(arr, start, end); 
} 

void quickSort(int arr[], int start, int end) 
{ 
    if (start < end) { 
        int pi = partition_r(arr, start, end); 
        quickSort(arr, start, pi - 1); 
        quickSort(arr, pi + 1, end); 
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
    quickSort(array,0,array_size - 1);
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