#include <bits/stdc++.h>
using namespace std;

vector <int> queries;
int high = -INT_MAX;

int main(){
    int in;
    while(1){
        scanf("%d",&in);
        if(in == -1) { break; }
        queries.push_back(in);
        high = max(high,in);
    }
    pair <int,int> arr[high + 1];
    pair <int,int> ans[high + 1];
    arr[0].first = 1; arr[0].second = 0;
    for(int i = 1; i <= high; i++){
        arr[i].first = arr[i - 1].first + arr[i - 1].second + 1;
        arr[i].second = arr[i - 1].first;
        ans[i] = {arr[i].first,arr[i].first + arr[i].second + 1};
    }
    //for(int i = 0; i <= high; i++) { cout << arr[i].first << " " << arr[i].second << endl;}
    for(auto x : queries){ printf("%d %d\n",ans[x].first,ans[x].second);}
}
