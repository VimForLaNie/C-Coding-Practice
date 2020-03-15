#include <bits/stdc++.h>
using namespace std;

int i,start_vertex,end_vertex,dist,num_vertex,num_edge;

int main(){
    priority_queue < pair<int,int> >pq;
    stack <int>path;
    cin >> num_vertex >> num_edge;
    vector< pair<int,int> > g[num_vertex + 1];
    long long min_dist[num_vertex + 1];
    bool visited[num_vertex + 1] = { 0 };
    int bt[num_vertex + 1] = { -1 };
    for (i = 0; i <= num_vertex; i++)
    {
        min_dist[i] = 1e10;
    }
    for (i = 0; i < num_edge; i++)
    {
        cin >> start_vertex >> end_vertex >> dist;
        g[start_vertex].push_back({dist,end_vertex});
        g[end_vertex].push_back({dist,start_vertex});
    }
    pq.push({0,1});
    int curr_dist,curr_vertex,next_vertex,next_dist;
    while(!pq.empty()){
        curr_vertex = pq.top().second;
        curr_dist = -pq.top().first;
        pq.pop();
        visited[curr_vertex] = true;
        int arr_size = g[curr_vertex].size();
        for(i = 0; i < arr_size; i++){
            next_vertex = g[curr_vertex][i].second;
            next_dist = g[curr_vertex][i].first;
            if(curr_dist + next_dist <= min_dist[next_vertex] && !visited[next_vertex]){
                min_dist[next_vertex] = curr_dist + next_dist;
                pq.push({-(curr_dist + next_dist),next_vertex});
                bt[next_vertex] = curr_vertex;
            }
        }
    }
    if(min_dist[num_vertex] == 1e10){
        cout << "-1";
        return 0;
    }
    i = num_vertex;
    while(bt[i] != -1){
        path.push(i);
        i = bt[i];
    }
    while(!path.empty()){
        cout << path.top() << " ";
        path.pop();
    }
}