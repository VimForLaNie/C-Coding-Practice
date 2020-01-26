#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue < pair< int,int > > pq;
    int num_node,num_conn;
    scanf(" %d %d",&num_node,&num_conn);
    vector < pair < int,int> > g[num_node];
    for (int i = 0; i < num_conn; i++)
    {
        int start,end,dist;
        scanf("%d %d %d",&start,&end,&dist);
        g[start].push_back({end,dist});
        g[end].push_back({start,dist});
    }
    pq.push({0,0});
    int min_dis[num_node];
    for(int i = 0; i < num_node; i++){
        min_dis[i] = 1e7; 
    }
    min_dis[0] = -1;
    while(!pq.empty()){
        int curr_node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        for (int i = 0; i < g[curr_node].size(); i++)
        {
            int next_node = g[curr_node][i].second;
            int new_dist = g[curr_node][i].first;
            if(new_dist + curr_dist < min_dis[next_node]){
                pq.push({new_dist + curr_dist,next_node});
                min_dis[next_node] = new_dist + curr_dist;
            }
        }
    }
    
}