#include <bits/stdc++.h>
using namespace std;

#define modulo 10000007
#define mod(x) (x % modulo)
long long int n;

template <typename T> T Pow (T a, T b){ 
	T res = 1; 
	while(b){ if(b & 1) {res = mod(mod(res) * mod(a));} 
		a = mod(mod(a) * mod(a)); 
		b >>= 1; 
	} 
	return mod(res);
}

int main(){
	cin >> n;
	cout << Pow((long long int)2,n-1) * (n > 1) << endl;
}
