#include <bits/stdc++.h>
using namespace std;

void Food(int no[],int m,int arr[],int n,int count){
    int temp[n] = { 0 };
    for (int j = 0; j < count; j++)
        {
            if(arr[j] != 0){
                temp[arr[j] - 1] = 1;
            }
        }
    if(count == n){
        
        for (int i = 0; i < n; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) 
    {
        if(count == 0){
            for (int x = 0; x < m; x++)
            {
                if(i == no[x]){
                    i++;
                    continue;
                }
                if(i != no[x] && i <= n)
                {
                    arr[count] = i;
                }
            }
        }
        if(temp[i - 1] == 0 && i <= n){
            arr[count] = i;
            temp[i - 1] = 1;
            // printf("arr : ");
            // for (int i = 0; i < n; i++)
            // {
            //     printf("%d ",arr[i]);
            // }
            // printf("\n");
            Food(no,m,arr,n,count + 1);
            if(count + 1 == n){
                return;
            }
        }
        else
        {
            continue;
        }
    }
}

int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int forbidden[m];
    for (int i = 0; i < m; i++)
    {
        scanf(" %d",&forbidden[i]);
    }
    int arr[n] = { 0 };
    sort(forbidden,forbidden + m);
    Food(forbidden,m,arr,n,0);
    return 0;
}