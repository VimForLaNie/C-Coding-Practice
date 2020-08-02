#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,j;
    scanf("%d %d",&n,&m);
    char board[m][n];
    int brick = 0;
    int bricks[m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c",&board[j][i]);
        }
    }
    for(int i = 0; i < m; i++){ scanf(" %d",&bricks[i]); }

    for(int i = 0; i < m; i++){
        brick = bricks[i];
        j = 0;
        while(brick > 0 && (j < n && j > -1)){
            if((board[i][j] == 'O' || board[i][j] == '#') && j > 0) { board[i][j - 1] = '#'; j-=2; brick--;}
            if(j == n - 1) { board[i][j] = '#'; j-=2; brick--; }
            j++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%c",board[j][i]);
        }
        printf("\n");
    }
    return 0;
}
