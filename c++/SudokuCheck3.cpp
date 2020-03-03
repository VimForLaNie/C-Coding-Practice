#include <bits/stdc++.h>
using namespace std;
int board[9][9];
bool row[9][10];
bool col[9][10];
int start_row[9] = {0,0,0,3,3,3,6,6,6};
int start_col[9] = {0,3,6,0,3,6,0,3,6};
int end_row[9] = {2,2,2,5,5,5,8,8,8};
int end_col[9] = {2,5,8,2,5,8,2,5,8};

bool inBox(int row, int col, int num){
    for(int i = 0;i < 9; i++){
        if(row <= end_row[i] && col <= end_col[i]){
            for(int x = 0; x < 3; x++){
                for (int y = 0; y < 3; y++)
                {
                    if(board[start_row[i] + x][start_col[i] + y] == num){
                        return true;
                    }
                }
            }
            return false;
        }
    }
    return false;
}

int main(){
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf(" %d",&board[i][j]);
            row[i][board[i][j]] = true;
            col[j][board[i][j]] = true;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            bool ans[10] = { 0 };
            if(board[i][j] != 0){
                continue;
            }       
            else{
                printf("%d %d ",i+1,j+1);
            }
            for(int x = 1; x <= 9; x++){
                if(row[i][x] || col[i][x] || inBox(i,j,x)){
                    continue;
                }
                else{
                    printf("%d ",x);
                }
            }
            printf("\n");
        }
    }
}