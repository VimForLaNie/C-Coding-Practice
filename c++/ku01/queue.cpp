#include <bits/stdc++.h>
using namespace std;
	
int height[100001];
int customer[101];
int mH[100001];
int best[100001];
int n,l;

int main(){
	cin >> n >> l;
	for(int i = 0 ; i < n; i++){
		cin >> height[i];
	}
	for(int i = 0; i < l; i++){
		cin >> customer[i];
	}
	mH[0] = height[0];
	best[0] = 0;
	for(int i = 1; i < n; i++){
		mH[i] = max(mH[i - 1],height[i]);
		if(height[i] > height[best[i - 1]]){
			best[i] = i;
		}
		else{
			best[i] = best[i - 1];
		}
		cout << "mH : " << mH[i] << " best : " << best[i] << endl;
	}
	for(int i = 0; i < l; i++){
		if(customer[i] - 1 == best[customer[i] - 1]){
			cout << "0++" << endl;
			continue;
		}
		else if(height[customer[i] - 1] <= mH[customer[i] - 1]){
			cout << mH[customer[i] - 1] - height[customer[i] - 1] + 1 << endl;
		}
	}
}
