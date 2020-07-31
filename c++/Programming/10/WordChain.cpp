#include <bits/stdc++.h>

using namespace std;

int s,n,diff;
bool flag = false;

int main(){
    scanf("%d",&s);
    scanf("%d",&n);
    char word[n][s];
    for(int i = 0; i < n; i++){
        scanf("%s",word[i]);
    }
    for(int i = 0; i < n - 1; i++){
        diff = 0;
        for(int j = 0; j < s; j++){
            if(word[i][j] != word[i + 1][j]){
                diff++;
            }
        }
        if(diff > 2){
            for(int j = 0; j < s; j++){
                printf("%c",word[i][j]);
            }
            printf("\n");
            flag = true;
            break;
        }
    }
    if(!flag) {
        for(int j = 0; j < s; j++){
            printf("%c",word[n - 1][j]);
        }
        printf("\n");
    }
}
