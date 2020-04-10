#include <bits/stdc++.h>
using namespace std;

int i,j,n,m,cnt;

int sub_array(int arr[], int size) { 
    int ans = 0;
    bool good = true;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i + 1; j++)
        {
            int sum = 0;
            for (int k = j; k < j + i; k++)
            {
               sum += arr[k];
               if(sum == 0){
                   good = false;
               }  
            }
            if(sum != 0 && good){
                ans++;    
            }
        }   
    }
    return ans;
} 

int main(){
    cin >> n;
    int a[n];
    for ( i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cnt = sub_array(a,n);
    cout << cnt;
}