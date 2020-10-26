#include <bits/stdc++.h>
using namespace std;

int n,i,j;
int a[200000];
int b[200000];

int main(){
	cin >> n;
	for(i = 0; i < n; i++){ cin >> a[i]; }
	for(i = 0; i < n; i++){ cin >> b[i]; }
	i = 0; j = n-1;
	while(i <= j){
		if(a[i] == b[i]){
			//cout << a[i] << " " << b[i] << endl;
			swap(a[i],a[j]);
			//cout << a[j] << " " << a[i] << endl;
			if(a[i] == b[i]) { cout << "No" << endl; return 0;}
		}
		i++; j--;
	}
	cout << "Yes" << endl;
	for(i = 0; i < n; i++){cout << a[i] << " ";}
	cout << endl;
}
