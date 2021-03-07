#include <bits/stdc++.h>
using namespace std;

#define num(x) (x - '0')
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string rs;
	int t,n;
	int ans[100005];
	int sum[100005];
	cin >> t;
	while(t--){
		cin >> n;
		cin >> rs;
		ans[0] = 1;
		for(int i = 1; i < n; i++){
			sum[i - 1] = ans[i - 1] + num(rs[i - 1]);
			switch(sum[i - 1]){
				case 2:
					ans[i] = (rs[i] == '0') ? 1 : 0;
					break;
				case 1:
					ans[i] = (rs[i] == '0') ? 0 : 1;
					break;
				default:
					ans[i] = 1;
					break;
			}
		}
		for(int i = 0; i < n; i++){ cout << ans[i]; }
		cout << "\n";
	}
	return 0;
}

