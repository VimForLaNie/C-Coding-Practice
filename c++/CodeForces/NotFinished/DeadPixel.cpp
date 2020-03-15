#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int ans[t];
    for(int i = 0; i < t ; i++){
        int a,b,dx,dy;
        scanf("%d %d %d %d",&a,&b,&dx,&dy);
        dx++;
        dy++;
        a++;
        b++;
        if(a == b){
            int width = max(max(a - dx,dx),max(b - dy,dy));
            ans[i] = --width * --a;
        }
        else if(a > b){
            int width = max(b - dy,dy);
            ans[i] = --width * --a;
        }
        else if(b > a){
            int width = max(a - dx,dx);
            ans[i] = --width * --b;
        }
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n",ans[i]);
    }
}