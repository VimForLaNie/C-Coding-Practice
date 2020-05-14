#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k,i,cnt,ans;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cnt = 0;
		if(k < n){
			cout << k << endl;
		}
		else{
			for(i = 1; i <= k; i++){
				if(i % n == 0){
					cnt++;
					continue;
				}
				ans = i + cnt;
			}
			cout << ans << endl;
		}
	}
}