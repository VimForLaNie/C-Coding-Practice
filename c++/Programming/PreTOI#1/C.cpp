#include <bits/stdc++.h>
using namespace std;

int n,k,q,i,l,r,j;

int main(){
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&q);
    int candy[n];
    bool check[k];
    for(i = 0; i < n; i++){
        scanf("%d",&candy[i]);
    }
    for(i = 0; i < q; i++){
        for(j = 0; j < k; j++){
            check[j] = 0;
        }
        scanf("%d",&l);
        scanf("%d",&r);
        l--;
        r--;
        for(j = l; j <= r; j++){
            if(candy[j] > k){
                continue;
            }
            check[candy[j] - 1] = true;
        }
        for(j = 0; j < k; j++){
            if(!check[j]){
                printf("NO\n");
                break;
            }
            if(j == k - 1){
                printf("YES\n");
            }
        }

    }
}