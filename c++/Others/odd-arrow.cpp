#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	cin >> n;
	for(int cnt = 0; cnt < n; cnt++){
		for(i = 0; i < cnt * (cnt <= n / 2);i++){ cout << " "; }
		for(i = 0; i < (cnt + 1) * (cnt <= n / 2);i++){ cout << "*"; }
		for(i = 0; i < (n - cnt - 1) * (cnt > n/2); i++){ cout << " "; }
		for(i = 0; i < (n - cnt) * (cnt > n/2); i++){ cout << "*"; }
		cout << endl;
	}
}
