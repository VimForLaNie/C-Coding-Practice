#include <stdio.h>

int main(){
    //variables
    int P,pointer = 1;
    int size;
    //input
    printf("Insert size of Array : ");
    scanf("%d",&size);
    
    int array[size];

    for (int i = 0; i < size; i++){
        printf("Insert The %d element of array : ");
        scanf("%d",array[i]);
    }
    printf("\n");
    //sorting
    while(P < size){
        while(pointer <= P){
            if(array[pointer] > array[pointer - 1]){
                int holder = array[pointer];
                array[pointer] = array[pointer - 1];
                array[pointer - 1] = holder;
            }
            pointer--;
        }
        P++;
        pointer = P;
    }
    //printing
    printf("Your Array : ");
    for(int i = 0; i < size; i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
    printf("Sorted Array : ");
    for(int i = 0; i < size; i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
}