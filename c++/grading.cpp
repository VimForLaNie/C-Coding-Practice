#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a + b + c >= 80){
        printf("%c",'A');
    }
    else if (a + b + c >= 75)
    {
        printf("%s","B+");
    }
    else if (a + b + c >= 70)
    {
        printf("%c",'B');
    }
    else if (a + b + c >= 65)
    {
        printf("%s","C+");
    }
    else if (a + b + c >= 60)
    {
        printf("%c",'C');
    }
    else if (a + b + c >= 55)
    {
        printf("%s","D+");
    }
    else if (a + b + c >= 50)
    {
        printf("%c",'D');
    }
    else if (a + b + c <= 49)
    {
        printf("%c",'F');
    }
    return 0;
}