#include <bits/stdc++.h>
using namespace std;

vector<int> g[10000];
bool visited[10000];
int color[10000];

bool isBi(int src){
    for(int i = 0; i < 10000; i++){ color[i] = -1; }

    stack<int> st;
    st.push(src);
    color[src] = 1;

    int next_n = -1;
    int ss = 0;
    while(!st.empty()){
        next_n = st.top();
        st.pop();

        if(visited[next_n]) { return false; }
        ss = g[next_n].size();
        for(int i = 0; i < ss; i++){
            if(color[g[next_n][i]] == -1) { color[g[next_n][i]] = 1 - color[next_n]; st.push(g[next_n][i]); }
            else if (color[g[next_n][i]] == color[next_n]){ return false; }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int start,stop;
    for(int i = 1; i < n; i++){
        cin >> start >> stop;
        g[start].push_back(stop);
        g[stop].push_back(start);
    }
    int a;
    cin >> a;
    if(isBi(a)) { cout << "YES" << endl; }
    else{ cout << "NO" << endl; }
}
