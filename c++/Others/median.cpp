#include <bits/stdc++.h>
using namespace std;

vector<int> arr(3);

int main(){
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	
  	cin >> arr[0] >> arr[1] >> arr[2];
  	sort(arr.begin(),arr.end());
  	cout << arr[1] << "\n";
  
  	return 0;
}
