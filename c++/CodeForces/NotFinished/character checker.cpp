#include <bits/stdc++.h>
using namespace std;

int main(){
    bool big = false,small = false;
    char string[10000] = { 0 };
    scanf(" %s",string);
    for (int i = 0; i < 10000; i++)
    {
        if(big && small){
            printf("Mix\n");
            break;
        }
        else if(big && string[i] == 0){
            printf("All Capital Letter\n");
            break;
        }
        else if (small && string[i] == 0)
        {
            printf("All Small Letter\n");
            break;
        }
        big = (string[i] >= 'A' && string[i] <= 'Z') ? true : big;
        small = (string[i] >= 'a' && string[i] <= 'z') ? true : small;
    }
    
}