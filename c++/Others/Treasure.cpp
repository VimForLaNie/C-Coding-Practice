#include <bits/stdc++.h>
using namespace std;
long long t,n,ans,ll,i;
long long mod = 987654321;

int main(){
	cin >> t;
	while(t--){
		ans = 1;
		cin >> n;
		ans += (2 * n);
		for(i = 2; i <= n; i++){
			ans += (2 * (2 * (n - i + 1)) - 1);
			cout << i << "-dot" << " : " << (2 * (2 * (n - i + 1)) - 1) << endl;
			cout << "total : " << ans << endl;
		}
		cout << (ans % mod) << endl;
	}
}
