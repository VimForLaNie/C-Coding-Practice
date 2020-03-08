#include <bits/stdc++.h>
using namespace std;

void mod(int k,char arr[],int arr_size){
    for (int i = 0; i < arr_size; i+=k)
    {
        for (int x = i; x < i + k - 1; x++)
        {
            arr[x + 1] = arr[x]; 
            if(x == 0){
                arr[x] = arr[i + k - 1];
                continue;
            }
        }
    }
    return;
}

bool isLow(int k,char str[],int str_size,char lowest_char){
    for (int i = 0; i < str_size; i+=k)
    {
        int holder = str[i];
        for (int x = i; x < i + k - 1; x++)
        {
            if(x == i){
                str[x] = str[i + k - 1];
                str[x + 1] = holder; 
                continue;
            }
            str[x + 1] = str[x]; 
            
        }
        if(str[0] == lowest_char){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    scanf(" %d",&t);
    int str_size[t];
    char str[t][5000];
    int ans[t];
    for (int i = 0; i < t; i++)
    {
        scanf(" %d",&str_size[i]);
        scanf(" %s",str[i]);
    }
    //find lowest char
    char lowest_char[t];
    for (int i = 0; i < t; i++)
    {
        int lowest = 255;
        for (int x = 0; x < str_size[i]; x++)
        {
            if(str[i][x] < lowest){
                lowest = str[i][x];
            }
        }
        lowest_char[i] = lowest;
    }
    //ans
    for (int i = 0; i < t; i++)
    {
        char temp_str[str_size[i]];
        
        for (int x = 1; x < str_size[i]; x++)
        {
            for (int j = 0; j < str_size[i]; j++)
            {
                temp_str[i] = str[i][j];
            }
            if(isLow(x,temp_str,str_size[i],lowest_char[i])){
                ans[i] = x;
                mod(x,str[i],str_size[i]);
                break;
            }
        }
    }
    //out
    for (int i = 0; i < t; i++)
    {
        for (int x = 0; x < str_size[i]; x++)
        {
            printf("%c",str[i][x]);
        }
        cout << endl;
        cout << ans[i] << endl;
    }
    
}