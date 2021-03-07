#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Point;

bool mst[15001];
int min_w[15001],curr_index,n,k,di,parent[15001],u,v;
long long ans;
Point house[15001];
vector< pair<int,pair<int,int>> > el;

int dist(int x, int y) { 
	return abs(house[x].first - house[y].first) + abs(house[x].second - house[y].second); ;
}

int _min_w(){
	int min_val = INT_MAX;
	int min_index = -1;
	
	for(int i = 0; i < n; i++){
		if(min_w[i] < min_val && !mst[i]){
			min_val = min_w[i];
			min_index = i;
		}
	}
	
	return min_index;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		parent[i] = i;
		min_w[i] = INT_MAX;
		cin >> house[i].first >> house[i].second; 
	}
	
	min_w[0] = 0;
	for(int i = 0; i < n; i++){
		curr_index = _min_w();
		mst[curr_index] = 1;
		//printf("-----------\n");
		for(int j = 0; j < n; j++){
			if(j == curr_index || mst[j]) {continue;}
			//printf("from %d -> %d \n",curr_index,j);
			di = dist(j,curr_index);
			//printf("di : %d min_w[j] : %d result : ",di,min_w[j]);
			if(di < min_w[j]){
				//printf("Yess \n");
				min_w[j] = di;
				parent[j] = curr_index;
			}
			//else {printf("No\n");}
		}
	}
	for(int i = 0; i < n; i++){
		//printf("parent of %d : %d \n",i,parent[i]);
		di = dist(i,parent[i]);
		el.push_back({ di , {i,parent[i]} });
	}
	sort(el.begin(),el.end());
	k--;
	while(k--) {el.pop_back();}
	for(auto x : el){
		di = x.first;
		u = x.second.first;
		v = x.second.second;
		//printf("edge : %d <-> %d = %d\n",u,v,di);
		if((u == v)){ continue; }
		//printf("Yes!\n");
		ans += (long long)di;
	}
	
	cout << ans << "\n";
	
	return 0;
}
