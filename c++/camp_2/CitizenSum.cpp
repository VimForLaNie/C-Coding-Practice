#include <bits/stdc++.h>
using namespace std;

int main(){
    char mystr[11];
    scanf(" %s",mystr);
    int sum = 0;
    for(int i = 0; i < 10; i++){
        if(mystr[i] >= 'A' && mystr[i] <= 'Z'){
            sum += (mystr[i] + 1 - 'A');
        }
        if(mystr[i] >= '0' && mystr[i] <= '9'){
            sum += (mystr[i] - '0');
        }
    }
    if(sum % 11 <= 1){
        if(mystr[10] - '0' == (1 - (sum % 11))){
            printf("T ");
        }
        else{
            printf("F ");
        }
    }else{
        if(mystr[10] - '0' == (11 - (sum % 11))){
            printf("T ");
        }
        else{
            printf("F ");
        }
    }
    printf("%d\n",sum);
}