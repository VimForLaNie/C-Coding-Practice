#include <bits/stdc++.h>
using namespace std;

int board[2001][2001];
map< pair<int,int>,pair<int,int> > p;
int n,m,cnt = 0;
int ioffset[] = {-1,0,1,1,1,0,-1,-1};
int joffset[] = {-1,-1,-1,0,1,1,1,0};
string read;
//stack< pair<int,int> > st;
//int ci,cj;
pair<int,int> hu;
pair<int,int> hv;

pair<int,int> findset(pair<int,int> a){
	if(p[a] == a){ return a; }
	return p[a] = findset(p[a]);
}



int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	//cin >> m >> n;
	//for(int i = 0; i < m; i++){
		//cin >> read;
		//for(int j = 0; j < n; j++){
			//board[i][j] = read[j] - '0';
			//p[{i,j}] = {i,j};
		//}
	//}
	n = 2000,m = 2000;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			board[i][j] = rand() % 2;
			p[{i,j}] = {i,j};
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			hu.first = i; hu.second = j;
			hu=findset(hu);
			for(int x = 0; x < 8; x++){
				hv.first = i + ioffset[x]; hv.second = j + joffset[x];
				hv=findset(hv);
				if (hu!=hv){ p[hu]=hv; }	
			}
			//if(board[i][j] == 1){ st.push({i,j}); cnt--;}
			//while(!st.empty()){
				//ci = st.top().first;
				//cj = st.top().second;
				//st.pop();
				//board[ci][cj] = cnt;
				//for(int x = 0; x < 8; x++){
					//if(ci + ioffset[x] >= n || ci + ioffset[x] < 0
					 //|| cj + joffset[x] >= m || cj + joffset[x] < 0){
						// continue;
					//}
					//if(board[ci + ioffset[x]][cj + joffset[x]] == 1){
						//st.push({ci + ioffset[x],cj + joffset[x]});
					//}
				//}
			//}
			
		}
	}
	cout << "yay" << endl;
    return 0;
}
