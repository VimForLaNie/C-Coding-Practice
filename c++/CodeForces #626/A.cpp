#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin >> t;
    int ans[t];
    vector <int> ans_index[t];
    for (int i = 0; i < t; i++)
    {
        next:
        ans[i] = -1;
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        for (int size = 1; size <= n; size++)
        {
            for (int index = 0; index <= n - size; index++)
            {
                int sum = 0;
                for (int pointer = index; pointer < index + size; pointer++)
                {
                    sum += arr[pointer];
                    
                    if(sum % 2 == 0){
                        ans[i] = size;
                        for (int c = index; c < index + size; c++)
                        {
                            ans_index[i].push_back(c + 1);
                        }
                        i++;
                        if(i == t){
                            goto ans;
                        }
                        goto next;
                    }
                }
            }
        }
    }
    ans:
    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << endl;
        int arr_size = ans_index[i].size();
        if(arr_size > 0){
            for (int x = 0; x < arr_size; x++)
            {
                printf("%d ",ans_index[i][x]);
            }
            cout << endl;
        }  
    }
    
}