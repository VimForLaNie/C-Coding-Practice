#include <bits/stdc++.h>
using namespace std;
#define ll long long

int i,t,n,j,input,ans;


int main(){
    cin >> t;
    for(i = 0;i < t;i++){
        map <int,bool> m;
        ans = 0;
        cin >> n;
        for(j = 0;j < n;j++){
            cin >> input;
            if(!m[input]){
                m[input] = true;
                ans++;
            }
            else{
                continue;
            }
        }
        cout << ans << endl;
    }
}