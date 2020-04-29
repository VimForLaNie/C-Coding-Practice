#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,m,i,a,b,cnt;
    cin >> a >> b;
    // bool ans[m-n];
    cnt = 0;
    for(i = 0; i <= 1e18;i++){
        // ans[i - n] = false;
        if((i % a) % b != (i % b) % a){
            // cout << "Happy @ " << i << endl;
            // ans[i-n] = true;
            cnt++;
        }
    }
    // for(i = 0; i <= (m - n);i++){
    //     if(ans[i]){
    //         cout << "-";
    //     }
    //     else{
    //         cout << "v";
    //     }
    // }
    cout << cnt;
    cout << endl;
    //leap max(a,b)
    //range max(a,b) * (min(a,b) - 1)
    //start max(a,b) + n(leap+range)
    //end (a * b * n) - 1
    //cycle leap + range
    main();
}