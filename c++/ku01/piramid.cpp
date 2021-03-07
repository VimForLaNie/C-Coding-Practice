#include <bits/stdc++.h>
using namespace std;

long long orange[102],l,n;
long long *ptr;

int main(){
	cin >> l >> n;
	for(int i = l; i > 0; i--){
		orange[i] = (i * i) + orange[i + 1];
	}
	ptr = upper_bound(orange + 1, orange + 101, orange[1] - n) - 1;
	cout << ptr - orange << " | " << orange[l] - n << endl;
	
}
