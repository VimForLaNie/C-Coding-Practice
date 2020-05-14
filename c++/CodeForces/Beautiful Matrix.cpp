#include <bits/stdc++.h>
using namespace std;

int main(){
    int map[5][5];
    int x,y;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                x = j;
                y = i;
            }
        }
    }
    int cnt = abs(x - 2) + abs(y - 2);
    cout << cnt << endl; 
}