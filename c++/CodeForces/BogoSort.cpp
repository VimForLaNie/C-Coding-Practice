#include <bits/stdc++.h>
using namespace std;
int i,j,x,y,n;

int main(){
    
    int t;
    cin >> t;
    for (x = 0;x < t;x++)
    {
        cin >> n;
        int arr[n];
        for ( y = 0; y < n; y++)
        {
            cin >> arr[y];
        } 
        sort(arr,arr+n);
        reverse(arr,arr+n);
        for ( j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}