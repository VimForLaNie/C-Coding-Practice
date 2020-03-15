#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,t,n;

bool palin(int arr[],int size,int l,int r,int ml,int mr){
    if(l == r){
        return true;
    }
    if(mr - ml < 2){
        return false;
    }
    if(l > r){
        if(arr[l] == arr[r]){
            return true;
        }
        if(arr[l] != arr[r]){
            return false;
        }
    }
    if(arr[l] == arr[r]){
        palin(arr,size,l+1,r-1,ml,mr);
    }
    else
    {
        if(arr[l + 1] == arr[r]){
            palin(arr,size,l + 1,r,l + 1,r);
        }
        else if(arr[r + 1] == arr[l]){
            palin(arr,size,l,r + 1,l,r + 1);
        }
        else if(arr[l] == arr[r - 1]){
            palin(arr,size,l,r - 1,l,r - 1);
        }
        else if(arr[l - 1] == arr[r]){
            palin(arr,size,l - 1,r,l - 1,r);
        }
        else{
            palin(arr,size,l + 1,r - 1,l + 1,r - 1);
        }
    }
}

int main(){
    cin >> t;
    for ( i = 0; i < t; i++)
    {
        cin >> n;
        int arr[n];
        for ( j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        if(palin(arr,n,0,n-1,0,n-1)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}
