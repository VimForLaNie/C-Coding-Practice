#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    //variable
    char input[5];
    char number[5];
    int a = 0;
    int b = 0;
    char high = 0;
    bool king = false;
    bool queen = false;
    bool jack = false;
    int max = 0;
    int location = 0;
    int count = 0;
    int slocation = 0;
    //input
    for (int i = 0; i < 5; i++)
    {
        printf("Please Insert Your %d card : ",i + 1);
        scanf(" %c",&input[i]);
        //formatting input
        for(char i = 0; i < 5; i++){
            input[i] = toupper(input[i]);
            if(input[i] == 'K'){
                input[i] = 'R';
            }
            if(input[i] == 'A'){
                input[i] = 'S';
            }
        }
    }
    //filling number[]
    for (char i = 0; i < 5; i++)
    {
        for (int x = 0; x < 5; x++)
        {
            if(input[i] != 0 && i != x && input[i] == input[x]){
                number[i]++;
                input[x] = 0;
            }
        }
    }
    //find max and location in location
    for (char i = 0; i < 5; i++)
    {
        if(number[i] > max){
            location = i;
            max = number[i];
        }
        if(number[i] <= max && number[i] > 0){
            slocation = i;
        }
    }
    //debugger
    // printf("location : %d\n",location);
    // printf("second location : %d\n",slocation);
    // printf("number value @ location : %d\n",number[location]);
    // printf("number value @ second location : %d\n",number[slocation]);
    //output
    switch (max + 1)
    {
    case 1://high card
        for (char i = 0; i < 5; i++)
        {
            if(input[i] > high){
                high = input[i];
            }
        }
        if(high == 'R'){
            high = 'K';
        }
        if(high == 'S'){
            high == 'A';
        }
        printf("It's a high Card : %c",high);
        break;
    case 2:
        //two pair
        if(input[location] > input[slocation] ){
            if(input[location] == 'R'){
                input[location] = 'K';
            }
            if(input[location] == 'S'){
                input[location] = 'A';
            }
            printf("It's a pair of %c!",input[location]);
        }else if(input[location] < input[slocation]){
            if(input[slocation] == 'R'){
                input[slocation] = 'K';
            }
            if(input[slocation] == 'S'){
                input[slocation] = 'A';
            }
            printf("It's a pair of %c!",input[slocation]);
        }
        //one pair
        else{
            if(input[location] == 'R'){
                input[location] = 'K';
            }
            if(input[slocation] == 'S'){
                input[slocation] = 'A';
            }
            printf("It's a pair of %c!",input[location]);
        }    
        break;
    case 3://triple
        //check for fullhouse
        if(number[location] == 2 && number[slocation] >= 1 && (input[slocation] == 'R' || input[slocation] == 'Q' || input[slocation] == 'J' || input[slocation] == 'S')){
            printf("It's a full house !!!");
        }else{
            if(input[location] == 'R'){
                input[location] = 'K';
            }
            if(input[location] == 'S'){
                input[location] = 'A';
            }
            printf("It's a triple of %c",input[location]);
        }
        break;
    case 4://four card
            if(input[location] == 'R'){
                input[location] = 'K';
            }
            if(input[location] == 'S'){
                input[location] = 'A';
            }
        printf("It's a four card of %c",input[location]);
        break;
    default:
        printf("Your case is stupid. . . ");
        break;
    }
    scanf(" %c");
    return 0;
}