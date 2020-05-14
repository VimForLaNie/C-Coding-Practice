#include <bits/stdc++.h>
using namespace std;

int main(){
	int size;
	int cnt;
	int t;
	string num;
	cin >> t;
	while(t--){
		cnt = 0;
		cin >> num;
		size = num.size();
		int arr[size];
		int i = 0;
		for(i = 0; i < size; i++){
			arr[i] = 0;
			if(num[i] != '0'){
				arr[i] = num[i] - '0';
				cnt++;
			}
		}
		cout << cnt << endl;
		for(i = 0; i < size; i++){
			if(arr[i]){
				cout << arr[i] * pow(10,size - i - 1) << " ";
			}
		}
		cout << endl;
	}
}