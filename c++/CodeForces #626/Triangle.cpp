#include <bits/stdc++.h>
using namespace std;
int i,n,m;

int main(){
    int t;
    cin >> t;
    bool ans[t];
    for ( i = 0; i < t; i++)
    {
        cin >> n >> m;
        if(n % m == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}