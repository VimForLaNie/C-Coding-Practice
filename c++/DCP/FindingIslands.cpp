#include <bits/stdc++.h>
using namespace std;

int i,j,n,m,input,cnt;
int check_x[] = {-1,-1,-1,0,1,1,1,0};
int check_y[] = {1,0,-1,-1,-1,0,1,1};

bool isIsland(vector <int> map[],int x,int y){
    for (int c = 0; c < 8; c++)
    {
        if(map[x][y] == 1){
            if(x + check_x[c] < 0 || x + check_x[c] >= n || y + check_y[c] < 0 || y + check_y[c] >= m){
                continue;
            }
            if(map[x + check_x[c]][y + check_y[c]] == 0){
                continue;
            }
            else{
                return false;
            }
        }
    }
    return true ? map[x][y] : false;
}

int main(){
    cin >> n;
    cin >> m;
    vector <int> map[n];
    for(i = 0; i < n; i++){
        for ( j = 0; j < m; j++)
        {
            cin >> input;
            map[i].push_back(input);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << i << " " << j << ":";
            if(isIsland(map,i,j)){
                cout << "yes" << endl;
                cnt++;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    cout << cnt;
}