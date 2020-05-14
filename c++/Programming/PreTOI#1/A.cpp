#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,r,cnt = 0;
    scanf("%d",&n);
    scanf("%d",&m);
    char in[m];
    r = min(n,m);
    int map[n][m];
    int ans[r];
    memset(ans,0,sizeof(ans));
    int i,j;
    for(i = 0; i < n;i++){
        scanf("%s",in);
        for(j = 0; j < m; j++){
            if(in[j] == '0'){ map[i][j] = 0; }
            else if(in[j] == '1'){ map[i][j] = (j - 1 < 0) ? 1 : (map[i][j - 1] + 1); cnt++; }
        }
    }
    printf("%d\n",cnt);
    int k,q;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < m - 1;j++){
            if(map[i][j] == 0){ continue; }
            for(k = 1; k <= (n - i) - 1;k++){
                for(q = 0; q <= k; q++){
                    if(map[i + q][j + k] < k + 1){ 
                        break; 
                    }
                    if(map[i + q][j + k] >= k + 1 && q == k){
                        ans[k] += 1; 
                    }
                }
            }
        }
    }
    for(i = 1; i < r; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
