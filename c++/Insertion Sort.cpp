#include <stdio.h>
#include <cstdlib>

int main(){
    //variables
    int count = 0;
    int pointer = 1;
    int size;
    //input
    printf("Insert size of Array : ");
    scanf("%d",&size);
    printf("size : %d\n",size);
    int array[size];
    for (int i = 0; i < size; i++){
        array[i] = rand();
        printf("Array @%d : %d\n",i,array[i]);
    }
    //sorting
    for(int P = 1; P <= size; P++){
        while(pointer <= P && pointer != 0){
            if(array[pointer] < array[pointer - 1]){
                count++;
                printf("Comparing. . . [%d]\n",count);
                int holder = array[pointer];
                array[pointer] = array[pointer - 1];
                array[pointer - 1] = holder;
            }
            pointer--;
        }
        pointer = P;
    }
    printf("Sorted Array : ");
    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}