#include <bits/stdc++.h>
using namespace std;

int main(){
    char temp;
    int n,t;
    cin >> n >> t;
    string q;
    cin >> q;
    for(int j = 0; j < t;j++){
        for (int i = 1; i < n; i++)
        {
            if(q[i] == 'G' && q[i-1] == 'B'){
                temp = q[i];
                q[i] = q[i - 1];
                q[i - 1] = temp;
                i++;
            }
        }
    }
    cout << q;
}