#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
long long arr[100001];
stack < pair<int,int> > st;

int main(){
    int n,m;
    cin >> n >> m;
    int a,b;
    for(int i = 2; i <= n; i++){
        cin >> a;
        g[a].push_back(i);
    }
    int s,v_i,val;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        st.push({a,b});
        while(!st.empty()){
            v_i = st.top().first;
            val = st.top().second;
            s = g[v_i].size();

            arr[v_i] += val;

            st.pop();
            for(int i = 0; i < s; i++){
                st.push({g[v_i][i],val});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
}
