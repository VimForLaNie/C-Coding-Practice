#include <bits/stdc++.h>
using namespace std;

bool g[100001][100001];
int color[100001];
bool visited[100001];
vector<int> black;
vector<int> white;

void solve(int src){
    int cnt = 0;
    for(int i = 1; i <= 1e5; i++){ color[i] = -1; }
    color[src] = 1;

    stack<int> st;
    st.push(src);

    int t;
    while(!st.empty()){
        t = st.top();
        st.pop();
        visited[t] = true;

        for(int i = 1; i <= 1e5; i++){
            if(!g[t][i]) { continue; }
            if(visited[i]) { continue; }
            if(color[t] == color[i]) { cout << "???" << endl; return; }
            color[i] = 1 - color[t];
            //cout << "i : " << color[i] << endl;
            st.push(i);
        }
    }
    for(int i = 1; i <= 1e5; i++){
        if(color[i] == 1) { black.push_back(i); }
        else if( color[i] == 0) { white.push_back(i); }
    }
    int s1 = black.size();
    int s2 = white.size();
   // for(int i = 0; i < s1; i++){ cout << black[i] << " ";} cout << endl;
   // for(int i = 0; i < s2; i++){ cout << white[i] << " ";} cout << endl;
    for(int i = 0; i < s1; i++){
        for(int j = 0; j < s2; j++){
            if(g[black[i]][white[j]] == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    int n,a,b;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        g[a][b] = true;
        g[b][a] = true;
    }
    solve(1);
    return 0;
}
