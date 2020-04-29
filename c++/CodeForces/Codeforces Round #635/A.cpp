
// Problem : C. Linova and Kingdom
// Contest : Codeforces - Codeforces Round #635 (Div. 2)
// URL : https://codeforces.com/contest/1337/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

vector < int > g[200001];
vector < bool > arr(200001);
stack< int > st;
int n,k,i,st,en,ss,cnt,j;

void dfs(int c){
	int curr,sss;
	if(!st.empty()){
		curr = st.top();
		if(arr[curr]){
			cnt += c;
		}
		st.pop();
		sss = g[curr].size();
		int x;
		for(x = 0; x < sss; x++){
			st.push(g[curr][x]);
		}
	}
	dfs(c + 1);
}

int main(){
	cin >> n >> k;
	for(i = 0; i < n - 1; i++){
		cin >> st >> en;
		cout << st << " " << en << endl;
		g[st].push_back(en);
	}
	for(i = 1;i <= n && k; i++){
		ss = g[i].size();
		if(ss == 0){
			arr[i] = true;
			k--;
			cout << i << endl; 
		}
	}
	dfs(0);
	cout << cnt;
	for(i = 1;i <= n;i++){
		ss = g[i].size(); 
		cout << i << " : ";
		for(j = 0;j < ss; j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}