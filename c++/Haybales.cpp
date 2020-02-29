#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int ans[t];
    for (int i = 0; i < t; i++)
    {
        int n_hay,n_day;
        scanf("%d %d",&n_hay,&n_day);
        int arr[n_hay];
        for (int j = 0; j < n_hay; j++)
        {
            scanf(" %d",&arr[j]);
        }
        int x = 1;
        int move = 0;
        while(move < n_day){
            if(x >= n_hay){
                break;
            }
            if(arr[x] > 0){
                if(move + x > n_day){
                    break;
                }
                else{
                    move += x;
                    arr[x]--;
                    arr[0]++;
                }
            }
            else if(arr[x] == 0){
                x++;
            }         
        }
        ans[i] = arr[0];
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n",ans[i]);
    }
    
}