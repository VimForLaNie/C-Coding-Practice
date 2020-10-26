#include <bits/stdc++.h>
using namespace std;

#define LIM 200001

int arr[LIM];
int ans = INT_MAX;

int main(){
    int n; bool f = false;
    cin >> n;
    for(int i = 0; i < n; i++){ cin >> arr[i]; }
    for(int i = 0; i < n - 1; i++){
       if(arr[i] > arr[i + 1]){
            f = true;
            ans = min(ans,arr[i] - arr[i + 1]);
            arr[i] = arr[i + 1];
       }
    }

    if(f){cout << ans << endl;}
    else{cout << 0 << endl; }
    return 0;
}
