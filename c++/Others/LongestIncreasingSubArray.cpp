#include <bits/stdc++.h>
using namespace std;

int n,i;

int main(){
    cin >> n;
    int length = 0;
    int a[n];
    int dy[n];
    for(i = 0; i < n; i++){
        cin >> a[i];
        dy[i] = 0;
    }
    for(i = 1; i < n;i++){
        if(a[i] > a[i - 1]){
            dy[i] = dy[i - 1] + 1;
            if(dy[i] > length){
                length = dy[i];
            }
        }
    }
    cout << length + 1;
}