#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    scanf("%d",&n);
    set <int> s;
    for(int i = 0; i < 20; i++){
    for(int j = 0; j < 12; j++){
    for(int k = 0; k < 5; k++){
        if((i * 6) + (j * 9) + (k * 20) <= n && (i * 6) + (j * 9) + (k * 20) != 0) { s.insert( (i * 6) + (j * 9) + (k * 20) ); }
    }
    }
    }
    for (auto x : s){
        printf("%d\n",x);
    }
    if(s.empty()) { printf("no");}
}
