
// Problem : A. Road To Zero
// Contest : Codeforces - Educational Codeforces Round 86 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1342/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long t,x,y,a,b,cnt,temp;
	cin >> t;
	while(t--){
		cnt = 0;
		cin >> x >> y;
		if(x > y){
			temp = x;
			x = y;
			y = temp;
		}
		cin >> a >> b;
		if(b > 2 * a){
			cout << (x + y) * a << endl;
		}
		else{
			cnt += x * b;
			cnt += (y - x) * a;
			cout << cnt << endl;
		}
	} 
}