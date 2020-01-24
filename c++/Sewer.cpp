#include <bits/stdc++.h>
using namespace std;

int main(){
    queue < pair < pair<int,int>,int> > q;
    int a,b;
    scanf("%d %d ",&a,&b);
    char Map[a][b];
    int count[a][b];
    memset(count, 0, sizeof(count));
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
        {
            scanf(" %c",&Map[i][j]);
        }
    }
    q.push({{0,0},0});
    int ans_x = 0;
    int ans_y = 0;
    int ans_e = 0;
    while(!q.empty()){
        int curr_row = q.front().first.first;
        int curr_col = q.front().first.second;
        int curr_e = q.front().second;
        count[curr_row][curr_col]++;
        q.pop();
        if(count[curr_row][curr_col] == 2){
            ans_x = curr_row;
            ans_y = curr_col;
            ans_e = curr_e;
            break;
        }
        if(curr_row >= a || curr_col >= b || 
           curr_row < 0 || curr_col < 0){
            continue;
        }
        if(Map[curr_row][curr_col] == 'B'){
            q.push({{curr_row + 1,curr_col},curr_e + 1});
            q.push({{curr_row,curr_col + 1},curr_e + 1});
            continue;
        }
        if(Map[curr_row][curr_col] == 'D'){
            q.push({{curr_row + 1,curr_col},curr_e + 1});
            continue;
        }
        if(Map[curr_row][curr_col] == 'R'){
            q.push({{curr_row,curr_col + 1},curr_e + 1});
            continue;
        }
    }
    printf("%d\n%d %d",ans_e + 1,ans_x + 1,ans_y + 1);
    return 0;
}