#include <bits/stdc++.h>
using namespace std;

void Swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    int t;
    scanf("%d",&t);
    bool ans[t];
    for (int r = 0; r < t; r++)
    {
        ans[r] = true;
        int n,m;
        scanf(" %d %d",&n,&m);
        int arr[n];
        int pos[m];
        for (int i = 0; i < n; i++)
        {
            scanf(" %d",&arr[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf(" %d",&pos[i]);
        }
        bool done = false;
        int i = 0;
        int cnt = 0;
        while(cnt < n){
            if(i == n){
                cnt = 0;
                i = 0;
            }
            if(arr[i] > arr[i + 1]){
                for (int x = 0; x < m; x++)
                {
                    if(pos[x] - 1 == i){
                        Swap(arr,i,i+1);
                        break;
                    }
                    if(x == m - 1){
                        ans[r] = false;
                        done = true;
                        break;
                    }
                }
            }
            else
            {
                cnt++;
            }
            i++;
            if(done){
                break;
            }
        }
    }
    for (int r = 0; r < t; r++)
    {
        if(ans[r]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}