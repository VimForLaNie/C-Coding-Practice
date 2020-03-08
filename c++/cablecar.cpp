#include <bits/stdc++.h>
using namespace std;
vector <pair <int,int> >g[2500];
int i,j;

int cap(int v1,int v2){
    int arr_size = g[v1].size();
    for ( i = 0; i < arr_size; i++)
    {
        int cap = g[v1][i].first;
        if(g[v1][i].second == v2){
            return cap;
        }
    }
    return 0;
}

int main(){
    priority_queue < pair < int,int > > pq;
    vector <int> path;

    int num_vertex,num_edge,start_vertex,end_vertex,people;
    cin >> num_vertex >> num_edge;
    int bt[num_vertex + 1] = { -1 };
    for ( i = 0; i < num_edge; i++)
    {
        int start,end,capacity;
        cin >> start >> end >> capacity;
        g[start].push_back({capacity,end});
        g[end].push_back({capacity,start});
    }
    cin >> start_vertex >> end_vertex >> people;
    pq.push({0,start_vertex});
    bool visited[num_vertex + 1] = { 0 };
    while(!pq.empty()){
        int curr_cap = pq.top().first;
        int curr_vertex = pq.top().second;
        pq.pop();
        int arr_size = g[curr_vertex].size();
        if(visited[curr_vertex]){
            continue;
        }
        if(curr_vertex == end_vertex){
            break;
        }
        for (i = 0; i < arr_size; i++)
        {
            if(!visited[g[curr_vertex][i].second]){
                pq.push(g[curr_vertex][i]);
            }
        }
        visited[curr_vertex] = true;
        bt[pq.top().second] = curr_vertex;
    }
    int min_cap = 1000000;
    j = num_vertex;
    while(bt[j] != -1){
        path.push_back(j);
        j = bt[j];
    }
    int path_size = path.size();
    for (int x = 0; x < path_size - 1; x++)
    {
        int curr_cap = cap(path[x],path[x + 1]);
        if(curr_cap < min_cap){
            min_cap = curr_cap;
        }
    }
    int ans;
    if(path_size < 2){
        ans = -1;
    }else{
        ans = people/(min_cap - 1);
        ans += 1 ? (people % (min_cap - 1) != 0) : 0;
    }
    printf("%d\n",ans);
}