#include <bits/stdc++.h>

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
    int size;
    scanf("%d",&size);
    int arr[size];
    for (size_t i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,size - 1);
    for (size_t i = size - 1; i > 0 ; i--)
    {
        if((arr[i] - arr[0]) - (arr[i - 1] - arr[0]) <= 1){
            continue;
        }
        else{
            printf("%d\t",arr[i - 1] + 1);
//            return arr[i - 1] + 1;
        }
    }
}