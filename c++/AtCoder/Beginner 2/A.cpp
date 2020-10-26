#include <bits/stdc++.h>
using namespace std;

int n,x,t,cnt;

int main(){

    cin >> n >> x >> t;

    cnt += n / x;
    if(n % x != 0){
        cnt++;
    }

    cout << cnt * t << endl;

    return 0;
}
										
