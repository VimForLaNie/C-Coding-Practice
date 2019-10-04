#include <stdio.h>
#include <time.h>

int main(){
    double time_spent = 0.0;
    const short value[] = {100,90,50,40,10,9,5,4,1};
    short count[9] = {0,0,0,0,0,0,0,0,0};
    short i;
    short input;
    scanf("%hd",&input);
    if (input >= 400)
    {
        printf("Invalid Input . . .\n");
        return 0;
    }
    
    clock_t start = clock();
    for (i = 0; i < 9; i++)
    {
        if(input <= 0){
            break;
        }
        count[i] = (input / value[i]);
        input -= (value[i]*(input / value[i]));
    }
    short result[] = {count[7] + count[6] + count[5],count[7] + count[6],count[5] + count[4] + count[3] + count[1],count[3] + count[2],count[1] + count[0]};
    clock_t end = clock();
    time_spent += (double)(end - start)/CLOCKS_PER_SEC;
    printf("Result : ");
    for (i = 0; i < 5; i++)
    {
        printf("\t%hd",result[i]);
    }
    printf("\ntime used in calculation : %f",time_spent);
    scanf(" %c");
    return 0;
}