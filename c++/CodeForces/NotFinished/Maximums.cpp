#include <bits/stdc++.h>
using namespace std;
int n,i,roof;

int main(){
    cin >> n;
    int b[n],a[n];
    for(i = 0; i < n; i++){
        cin >> b[i];
    }
    roof = b[0];
    a[0] = b[0];
    for ( i = 1; i <= n; i++)
    {
        if(b[i] > 0){
            roof += b[i];
            a[i] = roof;
        }
        else if(b[i] == 0)
        {
            a[i] = roof;
        }
        else if (b[i] < 0){
            a[i] = roof + b[i];
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    
}