#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t,d,ans,it;
	cin >> t;
	while(t--){
		cin >> d;
		ans = 1; it = 1;
		it += d;
		ans *= it;
		it += d;
		ans *= it;
		cout << ans << "\n";
	}
	
	return 0;
}
