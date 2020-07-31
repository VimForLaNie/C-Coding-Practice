#include <bits/stdc++.h>
using namespace std;

int n,s,e,h,high;
vector< pair<pair< int,int >,int> > queries;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&s,&h,&e);
        queries.push_back({{s,e},h});
        high = max(high,e);
    }
    int arr[high + 1] = { -1 };
    int seg_st,seg_ed;
    for(int i = 0; i < n; i++){
        seg_st = queries[i].first.first; seg_ed = queries[i].first.second;
        for(int j = seg_st; j < seg_ed; j++){
            arr[j] = max(queries[i].second,arr[j]);
        }
    }
    int curr_h = -1;
    for(int i = 0; i <= high; i++){
        if(arr[i] != curr_h){
            printf("%d %d ",i,arr[i]);
            curr_h = arr[i];
        }
    }
}
