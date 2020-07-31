#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int num){
    num -= (num / 20) * 20;
    num -= (num / 9) * 9;
    num -= (num / 6) * 6;
    if(num > 0) { return false; }
    return true;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        if(check(i)) { printf("%d\n",i); }
    }
}
