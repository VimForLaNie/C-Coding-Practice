#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int ans[t];
    for (int i = 0; i < t; i++)
    {
        char str[100];
        scanf(" %s",str);
        bool jue = false;
        int cnt = 0;
        int t_cnt = 0;
        for (int x = 0; x < 100; x++)
        {
            if(str[x] != '0' && str[x] != '1'){
                break;
            }
            if(str[x] == '0' && !jue){
                continue;
            }
            if(str[x] == '1'){
                jue = true;
                cnt += t_cnt;
                t_cnt = 0;
            }
            if(str[x] == '0'){
                t_cnt++;
            }
        }
        ans[i] = cnt;
    }
    for(int i = 0; i < t; i++){
        printf("%d\n",ans[i]);
    }
}