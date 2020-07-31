#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int sum = -INT_MAX;
    int s,e;
    int dy[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < i) { dy[i][j] = 0; continue;}
            if(j == 0) {dy[i][j] = arr[j];}
            else{dy[i][j] = dy[i][j - 1] + arr[j];}
            if(dy[i][j] >= sum) { sum = dy[i][j]; s = i; e = j; }
        }
    }
    if(sum <= 0) { printf("Empty Sequence\n"); return 0;}
    for(int i = s; i <= e; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d\n",sum);
}
