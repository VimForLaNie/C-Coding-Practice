#include <bits/stdc++.h>
using namespace std;

#define LIM 1001

char board[LIM][LIM];
bool warp[LIM][LIM];
int dy[LIM][LIM];
int n,m,st_i,st_j,en_i,en_j,n_i,n_j;
bool reach = 0;

const int i_off[] = {-1,0,1,0};
const int j_off[] = {0,1,0,-1};

void walk(int curr_i,int curr_j,int cnt){
    if(curr_i == en_i && curr_j == en_j) { reach = 1; return; }
    if(dy[curr_i][curr_j] <= cnt){ return; }
    dy[curr_i][curr_j] = cnt;
    for(int i = 0; i < 4; i++){
        n_i = curr_i + i_off[i];
        n_j = curr_j + j_off[i];
        if(n_i <= 0 || n_i > n || n_j <= 0 || n_j > m){ continue; }
        if(board[n_i][n_j] == '#'){ continue; }
        //cout << "walking to : " << n_i << " , " << n_j << endl;
        walk(n_i,n_j,cnt);
        dy[n_i][n_j] = min(dy[n_i][n_j],cnt);
        //cout << "setting dy[" << n_i << "][" << n_j << "]" << " : " << min(dy[n_i][n_j],cnt) << endl;
    }
}

void dfs(int curr_i,int curr_j,int cnt){
    walk(curr_i,curr_j,cnt);
    dy[curr_i][curr_j] = min(dy[curr_i][curr_j],cnt);
    if(curr_i == en_i && curr_j == en_j) { reach = 1; return; }
    if(warp[curr_i][curr_j]){ return ;}
    warp[curr_i][curr_j] = true;
    //cout << "============== warp # " << cnt + 1 << " ====================" << endl;
    cnt = dy[curr_i][curr_j];
    for(int i = -2; i <= 2; i++){
        n_i = curr_i + i;
        for(int j = -2; j <= 2; j++){
            n_j = curr_j + j;
            if(i == 0 && j == 0) { continue; }
            if(n_i <= 0 || n_i > n || n_j <= 0 || n_j > m){ continue; }
            if(board[n_i][n_j] == '#'){ continue; }
            if(dy[n_i][n_j] < cnt) {continue;}
            //cout << "search on : " << n_i << "," << n_j << endl;
            dfs(n_i,n_j,cnt + 1);
            //cout << "setting dy[" << n_i << "][" << n_j << "]" << " : " << min(dy[n_i][n_j],cnt + 1) << endl;
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> st_i >> st_j;
    cin >> en_i >> en_j;
    string read;
    for(int i = 1; i <= n; i++){
        cin >> read;
        for(int j = 0; j < m; j++){
            board[i][j + 1] = read[j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == '.'){ dy[i][j] = INT_MAX; }
            else{dy[i][j] = -1;}
        }
    }

    dfs(st_i,st_j,0);
//    cout << "---------------------------------" << endl;
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= m; j++){
//            cout << dy[i][j] << " ";
//        }
//        cout << endl;
//    }

    if(reach){ cout << dy[en_i][en_j] << endl;}
    else{cout << "-1" << endl;}
}
