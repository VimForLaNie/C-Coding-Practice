#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,t,n,h;
bool done = false;

int main(){
    cin >> t;
    for ( i = 0; i < t; i++)
    {
        h = 0;
        done = false;
        cin >> n;
        int field[n];
        for ( j = 0; j < n; j++)
        {
            cin >> field[j];
            if(field[j] > h){
                h = field[j];                            
            }
        }
        for ( j = 0; j < n; j++)
        {
            if((h - field[j]) % 2 != 0){
                cout << "NO" << endl;
                done = true;
                break;
            }
        }
        if(!done){
            cout << "YES" << endl;
        }
    }
}