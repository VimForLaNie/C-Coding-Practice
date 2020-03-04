#include <bits/stdc++.h>
using namespace std;

int main(){
    int board[9][9]; //row col
    int start_row[9] = {0,0,0,3,3,3,6,6,6};
    int start_col[9] = {0,3,6,0,3,6,0,3,6};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf(" %d",&board[i][j]);
        }
    }
    int n;
    scanf(" %d",&n);
    int command[n];
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %d %d",&command[i],&num[i]);
    }
    for (int i = 0; i < n; i++)
    {
        num[i]--;
        switch (command[i])
        {
        case -1:
        {
            for(int x = 0; x < 9; x++){
                if(board[num[i]][x] == 0){
                    continue;
                }
                printf("%d ",board[num[i]][x]);
            }
            printf("\n");
            break;
        }
        case 1:
        {
            for(int x = 0; x < 9; x++){
                if(board[x][num[i]] == 0){
                    continue;
                }
                printf("%d ",board[x][num[i]]);
            }
            printf("\n");
            break;
        }
        case 0:
        {
            int row_sec = start_row[num[i]];
            int col_sec = start_col[num[i]];
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if(board[row_sec + x][col_sec + y] == 0){
                        continue;
                    }
                    printf("%d ",board[row_sec+ x][col_sec + y]);
                }
            }
            printf("\n");
            break;
        }
        default:
        {
            break;
        }
        }   
    }
}