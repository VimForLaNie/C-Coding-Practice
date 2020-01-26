#include <bits/stdc++.h>
using namespace std;

int main(){
    long double a,b;
    scanf(" %Lf %Lf",&a,&b);
    long double result =  sqrt((a*a) + (b*b));
    printf("%.6Lf",result);
    return 0;
}