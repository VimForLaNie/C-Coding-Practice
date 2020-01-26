#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a;
    scanf("%d",&n);
    int min = 2000000000;
    int max = -2000000000;
    for (int i = 0; i < n; i++)
    {
        scanf(" %d",&a);
        if(a <= min){
            min = a;
        }
        else if (a >= max)
        {
            max = a;
        }   
    }
    printf("%d\n%d",min,max);
}