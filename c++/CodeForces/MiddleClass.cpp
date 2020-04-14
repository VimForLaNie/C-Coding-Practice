#include <bits/stdc++.h>
using namespace std;

int t,n,x,i,j,high;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        int arr[n];
        int s[n];
        int sum[n];
        for ( i = 0; i < n; i++)
        {
            s[i] = 0;
            sum[i] = 0;
            cin >> arr[i];
            if(i){
                sum[i] = sum[i - 1] + arr[i];
                s[i] = sum[i] / (i + 1);
                // if(s[i] % (i + 1)){
                //     s[i]--;
                // }
                if(s[i] >= x){
                    high = i + 1;
                }
            }
            else{
                sum[i] += arr[i];
                s[i] = arr[i];
            }
        }
        cout << high << endl;
        high = 0;
    }
}