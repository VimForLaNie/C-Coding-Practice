#include <bits/stdc++.h>
using namespace std;
#define ll long long
int i,n,m,k,c,j,input,x,curr_width,curr_length;

int main(){
    cin >> n >> m >> k;
    int a[n],b[m];
    vector < pair<int,int> >v;
    int ans = 0;
    for ( i = 0; i < n; i++)
    {
        cin >> input;
        if(input){
            c++;
            a[i] = c;
        }
        else{
            c = 0;
            a[i] = c;
        }
    }
    c = 0;
    for ( i = 0; i < m; i++)
    {
        cin >> input;
        if(input){
            c++;
            b[i] = c;
        }
        else{
            c = 0;
            b[i] = c;
        }
    }
    for(i = 1;i <= k;i++){
        if(k % i == 0){
            v.push_back({i,k/i});
            //cout << i  << " " << k/i << endl;
        }
    }
    int arr_size = v.size();
    for ( x = 0; x < arr_size; x++)
    {
        curr_width = v[x].first;
        curr_length = v[x].second;
        for ( i = 0; i < n; i++)
        {
            if(a[i] >= curr_width){
                for ( j = 0; j < m; j++)
                {
                    if(b[j] >= curr_length){
                        //cout << "++++ l = " << b[j] << " r = " << a[i] << endl;
                        ans++;
                    }
                }
            }
            else{
                continue;
            }
        }
    }
    cout << ans;
}
