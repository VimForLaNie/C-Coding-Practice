#include <bits/stdc++.h>
using namespace std;
 
int hb,hw,bw,bb,x,y,m,n,diff;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
	cin >> hw >> hb >> bw >> bb;
	cin >> x >> y;
	
	m = min(hb,bb); n = min(hw,bw);
	hb -= m; bb -= m; hw -= n; bw -= n;
	diff = max(min(hw,bb),min(hb,bw));
	//cout << "initial diff : " << diff << endl;
	while(m + n > x){
		//cout << "m , n , x  : " << m << " | " << n << " | " << x << endl;
		m--; n--; diff += 2;
	}
	diff = min(diff,y);
	
	cout << m + n + diff << "\n";
	
    return 0;
}
