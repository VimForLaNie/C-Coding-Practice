#include <stdio.h>
#include <cstdlib>

int main() {
    int array[100];
    for (int i = 0; i < 100; i++)
    {
        array[i] = rand() % 100;
        printf("Array @%d : %d\n",i,array[i]);
    }
    merge(array);
    scanf(" %c");
    return 0;
}

