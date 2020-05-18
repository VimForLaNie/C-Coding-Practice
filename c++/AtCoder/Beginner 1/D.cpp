#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define vec vector
#define que queue
#define st stack
#define str string
#define p_q priority_queue
#define d_q dequeue

#define Pi acos(-1)
//const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
#define modulo 123456789

#define mod(x) (x % modulo)
#define bool_tog(bool_x) bool_x = !bool_x
#define up_c(c) c -= ((c >= 'a' && c <= 'z') ? 32 : 0)
#define low_c(c) c += ((c >= 'A' && c <= 'Z') ? 32 : 0)

#define fi first
#define se second

    int min_dist[100001];
    bool visited[100001];
    int bt[100001];
    vec <int> g[100001];
    int ans[100001];

int i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size;
    int curr_node,curr_dist,next_node;
    int x;
    st <int> path;
    p_q < pair<int,int> > pq;

    int num_nodes,num_edges;
    int start_node,end_node;
    cin >> num_nodes >> num_edges;

    for(int i = 0; i < num_edges; i++){
        cin >> start_node >> end_node;
        g[start_node].push_back(end_node);
        g[end_node].push_back(start_node);
    }
    // for(int i = 0; i <= num_nodes; i++){
    //     size = g[i].size();
    //     cout << i << " : ";
    //     for(int j = 0; j < size; j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i = 2; i <= num_nodes; i++){
        // cout << "Starting from : " << i << endl;
        for(int j = 0; j <= num_nodes; j++){ min_dist[j] = 1111111; visited[j] = 0;}
        // cout << "Yay " << endl;
        bt[i] = -1;
        pq.push({0,i});
        while(!pq.empty()){
            // cout << "Yay lllll " << endl;
            curr_dist = -pq.top().fi;
            curr_node = pq.top().se;
            if(curr_node == 1) { break; }
            // cout << "Current : " << curr_node << " " << curr_dist << endl;
            if(visited[curr_node]) { pq.pop(); continue; }
            visited[curr_node] = 1;
            pq.pop();
            size = g[curr_node].size();
            // cout << "size : " << size << endl;
            for(int j = 0; j < size; j++){
                // cout << "Looping  . . ." << endl;
                next_node = g[curr_node][j];
                if(visited[next_node]) { continue; }
                if(curr_dist + 1 < min_dist[next_node]){
                    min_dist[next_node] = curr_dist + 1;
                    bt[next_node] = curr_node;
                    pq.push({-curr_dist - 1,next_node});
                    // cout << "push : " << -curr_dist-1 << " " << next_node << endl;
                }
            }
        }
        // cout << "BT : ";
        // for(int j = 0; j <= num_nodes; j++){ cout << bt[j] << " "; }
        // cout << endl;
        if(min_dist[1] == 1111111) {ans[i] = -1; continue; }
        x = 1;
        while(1){
            if(bt[x] == -1){ path.push(x); break; }
            // cout << "x : " << x << endl; 
            path.push(x);
            x = bt[x];
        }
        // x = path.top(); path.pop();
        // ans[x] = path.top();
        cout << "Path : ";
        while(!path.empty()){
            cout << path.top() << "->";
            path.pop();
        }
        cout << endl;
    }
    for(int i = 2; i <= num_nodes; i++){ if(ans[i] == -1) { cout << "NO" << endl; return 0;} }
    cout << "YES" << endl;
    for (int i = 2; i <= num_nodes; i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}