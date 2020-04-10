#include <bits/stdc++.h>
using namespace std;

int i,n,temp;
bool ans = true;

int main(){
    cin >> n;
    for(i = 0;i < n; i++){
        cin >> temp;
        if(temp){
            ans = false;
        }
    }
    if(ans){
        cout << "EASY";
    }
    else{
        cout << "HARD";
    }
}