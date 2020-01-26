#include <bits/stdc++.h>
using namespace std; 

int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for (size_t i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr + size);
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