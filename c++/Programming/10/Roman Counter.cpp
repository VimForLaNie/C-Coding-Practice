#include <bits/stdc++.h>
using namespace std;

int num;
int arr[5];

void cal(int n){
        if(n / 100 > 0){
            arr[4] += n / 100;
            n -= (n / 100) * 100;
        }
        if(n / 90 > 0){
            arr[4]++;
            arr[2]++;
            n -= 90;
        }
        if(n / 50 > 0){
            arr[3] += (n/50);
            n -= (n / 50) * 50;
        }
        if(n / 40 > 0){
            arr[3]++;
            arr[2]++;
            n -= 40;
        }
        if(n / 10 > 0){
            arr[2] += n / 10;
            n -= (n / 10) * 10;
        }
        if(n / 9 > 0){
            arr[2]++;
            arr[0]++;
            n -= 9;
        }
        if(n / 5 > 0){
            arr[1] += n / 5;
            n -= (n / 5) * 5;
        }
        if(n / 4 > 0){
            arr[1]++;
            arr[0]++;
            n -= 4;
        }
        if(n / 1 > 0){
            arr[0] += n;
            n -= n;
        }
}

int main(){
    scanf("%d",&num);
    for(int i = 1; i <= num; i++){
        cal(i);
    }
    for(int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }
}
