#include <bits/stdc++.h>
using namespace std;

int i,j;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans = ans xor arr[i];
    }
    if(n > 2){
        cout << 2 * ans;
    }
    else{
        cout << ans;
    }
}