#include <bits/stdc++.h>
using namespace std;

int main(){
    stack <int> bt_path;
    priority_queue < pair< int,int > > pq;
    int num_node,num_conn;
    scanf(" %d %d",&num_node,&num_conn);
    vector < pair < int,int> > g[num_node];
    for (int i = 0; i < num_conn; i++)
    {
        int start,end,dist;
        scanf("%d %d %d",&start,&end,&dist);
        g[start - 1].push_back({dist,end - 1});
        g[end - 1].push_back({dist,start - 1});
    }
    pq.push({0,0});
    vector < long long > min_dis;
    int bt[num_node + 1] = { -1 };
    for(int i = 0; i < num_node; i++){
        min_dis.push_back(1e11); 
    }
    min_dis[0] = 0;
    while(!pq.empty()){
        int curr_node = pq.top().second;
        int curr_dist = -pq.top().first;
        pq.pop();
        for (int i = 0; i < g[curr_node].size(); i++)
        {
            int next_node = g[curr_node][i].second;
            int new_dist = g[curr_node][i].first;
            if(new_dist + curr_dist < min_dis[next_node]){
                pq.push({-(new_dist + curr_dist),next_node});
                bt[next_node + 1] = curr_node + 1;
                min_dis[next_node] = new_dist + curr_dist;
            }
        }
        if(curr_node == num_node){
            continue;
        }
    }
    if(min_dis[num_node - 1] != 1e11){
        int i = num_node;
        while(bt[i] != -1){
            bt_path.push(i);
            i = bt[i];
        }
        while(!bt_path.empty()){
            printf("%d ",bt_path.top());
            bt_path.pop();
        }
    }
    else{
        printf("-1");
    }
}