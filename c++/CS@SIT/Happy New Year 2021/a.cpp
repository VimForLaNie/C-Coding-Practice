#include <bits/stdc++.h>
using namespace std;

int t;
long long n;

void solve(){
	int total = 0;
	for(int i = 1; total <= n; i++){
		if(total == n) { cout << i - 1 << "\n"; return; }
		total += (i / 10) + 1;
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--){
		cin >> n;
		solve();
	}
	
	return 0;
}
