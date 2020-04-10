#include <bits/stdc++.h>
using namespace std;

int n,i;

int main(){
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        if(i == 0){
            cout << "I hate ";
        }
        else{
            if(i % 2 == 0){
                cout << "that I hate ";
            }
            else{
                cout << "that I love ";
            }
        }
    }
    cout << "it";
    
}