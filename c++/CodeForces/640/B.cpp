#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	int n,k,i;
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(n % 2 == 0){
			if(2 * k < n){
				cout << "YES" << endl;
				for(i = 1; i <= k; i++){
					if(i == k){
						cout << n << " ";
					}
					else{
						cout << "2 ";
						n -= 2;
					}
				}
				cout << endl;
			}
			else if(k == n){
				cout << "YES" << endl;
				for(i = 1; i <= k; i++){
					cout << "1" << " ";
				}
				cout << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		else{
			if(k % 3 == 0){
				cout << "YES" << endl;
				for(i = 1; i <= k; i++){
					if(i == k){
						cout << n << " ";
					}
					else{
						cout << "1 ";
						n--;
					}
				}
				cout << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}
}