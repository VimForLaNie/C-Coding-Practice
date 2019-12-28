#include <stdio.h>

void format(char input[],short output[]){
    short num = 0;
    short pointer = 0;
    for (size_t i = 0; i < (sizeof(input)/sizeof(input[0])); i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            if(input[i + 1] == ' '){
                num += input[i];
                output[pointer] = num;
                i++;
                pointer++;
                num = 0;
            }
            else{
                num += (input[i] * 10) + (input[i + 1]);
                output[pointer] = num;
                i += 2;
                pointer++;
                num = 0;
            }
        }
        
    }
    
}

int main(){
    char rawInput[(3  * 100)] = {'/'};
    fgets(rawInput,300 + 2,stdin);
    short array[100] = { 0 };
    format(rawInput,array);
}