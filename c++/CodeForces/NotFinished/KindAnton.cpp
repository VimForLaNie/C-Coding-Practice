#include <bits/stdc++.h>
using namespace std;

int i,t,m,n,j;
bool ans,found;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        int b[n];
        for ( i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for ( i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ans = true;
        for(i = 0; i < n; i++){
            if(a[i] == b[i]){
                continue;
            }
            else{
                if(b[i] - a[i] > 0){
                    for ( j = i -1; j >= 0; j--)
                    {
                        if(a[j] == 0){
                            continue;
                        }
                        if((b[i] - a[i]) % a[j] == 0 && a[j] > 0){
                            found = true;
                            break;
                        }
                    }
                    if(found){
                        a[j] = b[j];
                    }
                    else{
                        ans = false;
                        break;
                    }
                    found = false;
                }
                else{
                    for ( j = i - 1; j >= 0; j--)
                    {
                        if(a[j] == 0){
                            continue;
                        }
                        if((b[i] - a[i]) % a[j] == 0 && a[j] < 0){
                            found = true;
                            break;
                        }
                    }
                    if(found){
                        a[j] = b[j];
                    }
                    else{
                        ans = false;
                        break;
                    }
                    found = false;
                }
            }
        }
        if(ans){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}