#include <bits/stdc++.h>
using namespace std;

int w,h,m,n;
int x[1002],y[1002];
int height[1002];
int width[1002];
int ans1,ans2;
priority_queue <int> pq;

int main(){
	cin >> w >> h >> m >> n;
	for(int i = 0; i < m; i++){
		cin >> x[i];
	}
	x[m] = w;
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}
	y[n] = h;
	
	height[0] = x[0];
	for(int i = 1; i < m + 1; i++){
		height[i] = x[i] - x[i - 1];
	}
	width[0] = y[0];
	for(int i = 1; i < n + 1; i++){
		width[i] = y[i] - y[i - 1];
	}
	
	ans1 = -1;
	for(int i = 0;i < m + 1; i++){
		for(int j = 0; j < n + 1; j++){
			cout << "height : " << height[i] << " width : " << width[j] << endl;
			pq.push(width[j] * height[i]);
		}
	}
	ans1 = pq.top();
	pq.pop();
	if(!pq.empty()) {ans2 = pq.top();} else { ans2 = 0; }
	cout << ans1 << " " << ans2 << endl;
}
