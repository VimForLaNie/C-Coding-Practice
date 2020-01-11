#include <stdio.h>
int main(){
    const short value[] = {100,90,50,40,10,9,5,4,1};
    short count[9] = {0,0,0,0,0,0,0,0,0};
    short i;
    short input;
    scanf("%hd",&input);
    
    for (i = 0; i < 9; i++)
    {
        if(input <= 0){
            break;
        }
        count[i] = (input / value[i]);
        input -= (value[i]*(input / value[i]));
    }
    short result[] = {count[7] + count[6] + count[5],count[7] + count[6],count[5] + count[4] + count[3] + count[1],count[3] + count[2],count[1] + count[0]};
    for (i = 0; i < 5; i++)
    {
        printf("%hd ",result[i]);
    }
    return 0;
}