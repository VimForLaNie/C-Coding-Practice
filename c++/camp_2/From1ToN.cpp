#include <bits/stdc++.h>
using namespace std;

int main(){
    stack <int> path;
    priority_queue < pair<int , int > > pq;
    vector < pair<int,int> > g[100];
    int num_vertices,num_edges;
    cin >> num_vertices >> num_edges;
    int min_dist[num_vertices];
    int bt[num_vertices + 1] = { -1,0 };
    for(int i = 0; i < num_vertices;i++){
        min_dist[i] = 1e9;
    }
    for (int i = 0; i < num_edges; i++)
    {
        int start_vertex,end_vertex,dist;
        cin >> start_vertex >> end_vertex >> dist;
        g[start_vertex - 1].push_back({dist,end_vertex - 1});
        g[end_vertex - 1].push_back({dist,start_vertex - 1});
    }
    pq.push({0,0});
    bool visited[num_vertices] = { 0 };
    while(!pq.empty()){
        int curr_dist,curr_vertex,next_vertex,next_dist;
        curr_dist = -pq.top().first;
        curr_vertex = pq.top().second;
        if(curr_vertex == num_vertices - 1){
            break;
        }
        if(visited[curr_vertex]){
            pq.pop();
            continue;
        }
        visited[curr_vertex] = true;
        int arr_size = g[curr_vertex].size();
        for(int i = 0; i < arr_size; i++){
            next_vertex = g[curr_vertex][i].second;
            next_dist = g[curr_vertex][i].first;
            if(visited[next_vertex]){
                continue;
            }
            int total_dist = next_dist + curr_dist;
            if(total_dist < min_dist[next_vertex]){
                pq.push({-(total_dist),next_vertex});
                min_dist[next_vertex] = total_dist; 
                bt[next_vertex + 1] = curr_vertex + 1;
            }
        }
        pq.pop();
    }
    int i = num_vertices;
    path.push(num_vertices);
    if(min_dist[i - 1] != 1e9){
        while(bt[i] != 0){
            i = bt[i];
            path.push(i);
        }
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
    else{
        cout << "-1" << endl;
    }
    return 0;
}