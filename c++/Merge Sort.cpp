#include <stdio.h>
#include <cstdlib>
#include <time.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k = 0; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    } 
    for (j = 0; j < n2; j++){ 
        R[j] = arr[m + 1+ j];
    } 
    i = 0;
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int Lpointer, int Rpointer) 
{ 
    if (Lpointer < Rpointer) 
    { 
        int m = Lpointer+(Rpointer-Lpointer)/2; 
        mergeSort(arr, Lpointer, m); 
        mergeSort(arr, m+1, Rpointer); 
        merge(arr, Lpointer, m, Rpointer); 
    } 
} 

int main() {
    //input
    int size;
    printf("Insert size of Array : ");
    scanf("%d",&size);
    printf("size : %d\n",size);
    int array[size];
    int arr_size = sizeof(array)/sizeof(array[0]);
    printf("sizeof(array) : %d\n arr_size : %d\n ",sizeof(array),arr_size);
    for (int i = 0; i < arr_size; i++)
    {
        array[i] = rand();
        printf("Array @%d : %d\n",i,array[i]);
    }
    //sort
    clock_t start = clock();
    mergeSort(array, 0, arr_size - 1);
    clock_t end = clock();
    //print
    printf("Sorted Array : ");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    double timespent = (double)(end - start)/CLOCKS_PER_SEC;
    printf("time used in sorting : %f",timespent);
    return 0;
}