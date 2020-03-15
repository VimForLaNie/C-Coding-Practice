#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<pair<int, int>> q;
    int x, y;
    int count = 0;
    scanf("%d %d", &x, &y);
    vector < pair < int,int > > w_pos;
    int x_next[4] = {-1, 0, 1, 0};
    int y_next[4] = {0, 1, 0, -1};
    char map[x][y];
    char visited[x][y] = {0};
    memset(visited, 0, sizeof(visited));
    for (size_t i = 0; i < y; i++)
    {
        scanf(" %[^\n]s", map[i]);
    }
    q.push({0, 0});
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            if (map[i][j] == 'W')
            {
                w_pos.push_back( {i,j} );
            }
        }
    }
    
    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        if(map[curr_x][curr_y] == '*' && visited[curr_x][curr_y] == 0){
            count++;
        }
        if(map[curr_x][curr_y] == 'W' && visited[curr_x][curr_y] == 0){
            for (size_t i = 0; i < w_pos.size(); i++)
            {
                if(w_pos[i].first == curr_x && w_pos[i].second == curr_y){
                    continue;
                }
                q.push( {w_pos[i].first,w_pos[i].second} );
                visited[w_pos[i].first][w_pos[i].second] = 1;
            }
        }
        visited[curr_x][curr_y] = 1;
        q.pop();
        for (size_t i = 0; i < 4; i++)
        {
            if (curr_x + x_next[i] == -1 
            || curr_y + y_next[i] == -1 
            || curr_x + x_next[i] >= x 
            || curr_y + y_next[i] >= y) //ran out of map
            {
                continue;
            }
            if (visited[curr_x + x_next[i]][curr_y + y_next[i]] == 1) // have been visited
            {
                continue;
            }
            if (map[curr_x + x_next[i]][curr_y + y_next[i]] == '#') // ran into a wall
            {
                continue;
            }
            q.push({curr_x + x_next[i], curr_y + y_next[i]});
        }
    }
    for (size_t i = 0; i < y; i++)
    {
        for (size_t j = 0; j < x; j++)
        {
            printf("%d", visited[i][j]);
        }
        printf("\n");
    }
    printf("%d\t",count);

    return 0;
}