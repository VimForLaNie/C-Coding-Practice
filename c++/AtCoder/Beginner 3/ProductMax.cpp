#include <bits/stdc++.h>
using namespace std;
template<typename T> T abs(T x){ return ((x < 0) ? -x : x);}

int main(){
	long long int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << max(max(a*c,a*d),max(b*c,b*d)) << endl;
}
