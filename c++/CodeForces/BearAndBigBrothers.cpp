#include <bits/stdc++.h>
using namespace std;

int i,n,m;
int x = 1;

int main(){
    cin >> n >> m;
    while(n <= m){
        n = n * 3;
        m = m * 2;
        i++;
    }
    if(i == 0){
        cout << "1";
    }else{
        cout << i;
    }
}