#include <bits/stdc++.h>
using namespace std;

int joffset[] = {1991,-1,1,0};

int m,start,n;
int board[41][101];
bool done = false;

void dfs(int lane, int time, vector<int> p){
	if(done) return;
	//cout << "@time : " << time << endl;
	if(time == n){ for(auto x : p){ cout << x << endl; } done = true; return;}
	//cout << "pushing . . ." << endl;
	for(int q = 1; q <= 3; q++){
		if(lane + joffset[q] > m || lane + joffset[q] <= 0){ continue; }
		//cout << "time : " << time << "no out of bound : " << q << endl;
		//cout << "checking : " << lane + joffset[q] << ";" << time + 1 << "|";
		//cout << board[lane + joffset[q]][time + 1] << endl;
		if(board[lane + joffset[q]][time + 1] == 0){
			//cout << "time : " << time << ", " << q << endl;
			p.push_back(q);
			dfs(lane + joffset[q],time + 1,p);
			if(!done){ p.pop_back(); }
		}
	}
}

int main(){
	vector<int> path;
	cin >> m >> start >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> board[j][i];
		}
	}
	//for(int i = 0; i <= n + 1; i++){
		//for(int j = 1; j <= m; j++){
			//cout << board[j][i];
		//}
		//cout << endl;
	//}
	dfs(start,0,path);
	return 0;
}
