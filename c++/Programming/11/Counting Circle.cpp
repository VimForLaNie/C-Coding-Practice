#include <bits/stdc++.h>
using namespace std;

int n,k;

int solve(){
    int arr[n];
    for(int i = 0; i < n; i++){ arr[i] = i + 1;}
    int s = n,cnt = 0,i = 0;
    while(s){
        cnt++;
        //for(auto x: arr) { cout << x << " ";} cout << endl;
        // cout << "cnt : " << cnt << endl;
        if(arr[i % n] == -1) { i++; continue;}
        if(s == 1){ return arr[i % n]; }
        if(cnt == k){ s--; cnt = 0; arr[i % n] = -1; }
        i++;
    }
    return -1;
}

int main(){
    //printf("Input : (int n) (int k)\n");
    scanf("%d %d",&n,&k);
    int ans = solve();
    printf("%d\n",ans);
}