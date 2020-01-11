#include <bits/stdc++.h>
using namespace std;

int main(){
    short energy,nFloor;
    int nStair;
    
    scanf("%hd %hd %d",&energy,&nFloor,&nStair);

    short floor_stair[nStair][2];
    memset(floor_stair, 0, sizeof(floor_stair));
    int Onecount = 0;
    int index[nStair] = { 0 };
    for (int i = 0; i < nStair; i++)
    {
        short start,end;
        scanf("%hd %hd",&start,&end);
        if(start == 1){
            index[Onecount] = i;
            Onecount++;
        }
        floor_stair[i][0] = start;
        floor_stair[i][1] = end;
    }

    short count[Onecount] = { 0 };
    short chain[Onecount][nStair];
    memset(chain, 0 , sizeof(chain));
    for (int i = 0; i < Onecount; i++)
    {
        chain[i][count[i]] = floor_stair[index[i]][1];
        count[i]++;
    }

    for (int i = 0; i < Onecount; i++)
    {
        for (int j = 0; j < nStair; j++)
        {
            if(count[i] >= energy){
                break;
            }
            if(chain[i][count[i] - 1] == floor_stair[j][0]){
                chain[i][count[i]] = floor_stair[j][1];
                count[i]++;
            }
        }
    }
    int max = 1;
    for (int i = 0; i < Onecount; i++)
    {
        if(energy == 0){
            break;
        }
        if(max < chain[i][count[i] - 1]){
            max = chain[i][count[i] - 1];
        }
    }
    
    printf("%d",max);
    
    
    
    // printf("%d",ans);
    return 0;
}