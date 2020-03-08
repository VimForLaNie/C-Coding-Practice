#include <bits/stdc++.h>
using namespace std;

int main(){
    int o_cnt = 0;
    int c_cnt = 0;
    int n;
    int ans;
    cin >> n;
    char arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] == ')'){
            c_cnt++;
        }
        else if (arr[i] == '(')
        {
            o_cnt++;
        }
    }
    if(c_cnt != o_cnt){
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 2; i <= n; i+=2)
    {
        for (int j = 0; j < n - i; j++)
        {
            for (int x = 0; x < i; x++)
            {
                if(arr[x] == arr[x + 1]){
                    
                }
            }
        }
    }
}