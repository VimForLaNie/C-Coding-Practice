#include <bits/stdc++.h>
using namespace std;

int i,j,n,m,t,b,w;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n % 2 == 0){
            b = m * (n/2);
            w = b;
        }
        else{
            b = (m * ((n/2) + 1)) - (m/2);
            w = (m * (n/2)) + (m/2);
        }
        // cout << b << " " << w << endl;
        if(b == w + 1){
            for ( i = 0; i < n; i++)
            {
                if(i % 2 == 0){
                    for(j = 0; j < m; j++){
                        if(j % 2 == 0){
                            cout << "B";
                        }
                        else{
                            cout << "W";
                        }
                    }
                }
                else{
                    for(j = 1; j <= m; j++){
                        if(j % 2 == 0){
                            cout << "B";
                        }
                        else{
                            cout << "W";
                        }
                    }
                }
                cout << endl;
            }
        }
        else{
            int cnt = b - w + 1;
            for ( i = 0; i < n; i++)
            {
                if(i % 2 == 0){
                    for(j = 0; j < m; j++){
                        if(j % 2 == 0){
                            cout << "B";
                        }
                        else{
                            if(cnt != 0){
                                cout << "B";
                                cnt--;
                            }
                            else{
                                cout << "W";
                            }
                        }
                    }
                }
                else{
                    for(j = 1; j <= m; j++){
                        if(j % 2 == 0){
                            cout << "B";
                        }
                        else{
                            if(cnt != 0){
                                cout << "B";
                                cnt--;
                            }
                            else{
                                cout << "W";
                            }
                        }
                    }
                }
                cout << endl;
            }
        }
    }
}