#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > g[10001];
int n,m,st,ed,p,t,u,v,w,next_node,next_weight;

int dfs(int root,int cost,int max_weight,bool visited[]){
	if(cost > p || visited[root]) {return -2;}
	if(root == ed) { 
		//printf("	ed ---%d\n",max_weight);
		return max_weight; 
	}
	//printf("@ node : %d , cost : %d , mw : %d\n",root,cost,max_weight);
	visited[root] = 1;
	
	int ans = -1;
	for(size_t i = 0; i < g[root].size(); i++){
		next_node = g[root][i].first;
		next_weight = g[root][i].second;
		//printf("= = = next n : %d  | w : %d\n",next_node,next_weight);
		ans = max(ans,dfs(next_node,cost + next_weight,max(max_weight,next_weight),visited));
	}
	//printf("	root : %d ---(%d)\n",root,ans);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--){
		cin >> n >> m >> st >> ed >> p;
		bool visited[n + 1];
		for(int i = 0; i < 10001; i++){
			g[i].clear();
			if(i <= n){ visited[i] = 0; }
		}
		for(int i = 0; i < m; i++){
			cin >> u >> v >> w;
			g[u].push_back({v,w});
			//g[v].push_back({u,w});
		}
		cout << dfs(st,0,-1,visited) << "\n";
	}
	
	return 0;
}
