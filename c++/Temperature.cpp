#include <bits/stdc++.h>
using namespace std;

void format(char arr[],int out[], int arr_size, int out_size)
{
    char count = 0;
    int pointer = out_size - 1;
    int num = 0;

    for (int i = arr_size - 1; i >= 0; i--)
    {
        if(arr[i] >= '0' && arr[i] <= '9')
        {
            num += (arr[i] - '0') * pow(10,count);
            count++;
        }
        else if(arr[i] == ' ' && count > 0){
            out[pointer] = num;
            num = 0;
            count = 0;
            pointer--;
        }
        else if(arr[i] = '-' && count > 0){
            out[pointer] = -num;
            num = 0;
            count = 0;
            pointer--;
        }
        if(i == 0)
        {
            out[pointer] = num;
        }
    }
}

int main() {
    queue < pair < int,int > > q;
    int size;
    scanf("%d",&size);
    int map[size][size];
    char visited[size][size];
    memset(visited, 0, sizeof(visited));
    int start_Y,start_X;
    scanf("%d %d",&start_Y,&start_X);
    for (size_t i = 0; i < size; i++)
    {
        char temp[4 * size];
        memset(temp, ' ',sizeof(temp));
        scanf(" %[^\n]s",&temp);
        format(temp,map[i],4 * size,size);
    }
    /*
20
1 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33
16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34
17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36
19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37
20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 100
21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 100 100
    */
    q.push({start_X - 1,start_Y - 1});
    const int x_next[4] = {-1,0,1,0};
    const int y_next[4] = {0,1,0,-1};
    int max = -6;
    while(!q.empty()){
        int curr_X = q.front().first;
        int curr_Y = q.front().second;
        // printf("Currently On : %d %d \n",curr_X,curr_Y);
        if(max < map[curr_X][curr_Y]){
            max = map[curr_X][curr_Y];
        }
        visited[curr_X][curr_Y] = 1;
        q.pop();
        for (size_t i = 0; i < 4; i++)
        {
            if(curr_X + x_next[i] == size 
            || curr_Y + y_next[i] == size
            || curr_X + x_next[i] == -1
            || curr_Y + y_next[i] == -1){
                continue;
            }
            if(map[curr_X + x_next[i]][curr_Y + y_next[i]] == 100){
                continue;
            }
            if(visited[curr_X + x_next[i]][curr_Y + y_next[i]] == 1){
                continue;
            }
            if(map[curr_X + x_next[i]][curr_Y + y_next[i]] <= map[curr_X][curr_Y]){
                continue;
            }
            q.push({curr_X + x_next[i],curr_Y + y_next[i]});
        }
        /*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
        */
    }
    printf("%d\n",max);
    printf("visited :\n");
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            printf("%d ",visited[i][j]);
        }
        printf("\n");
    }
    return 0;
}