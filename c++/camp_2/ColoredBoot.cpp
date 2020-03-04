#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int ans = 0;
    scanf(" %d",&t);
    char left[t];
    char right[t];
    int l_qm = 0;
    int r_qm = 0;
    map < char,int > list; 
    scanf(" %s",left);
    scanf(" %s",right);
    for(int i = 0; i < t; i++){
        
        if(right[i] == '?'){
            r_qm++;
        }
        if(left[i] == '?'){
            l_qm++;
        }
        else{
            list[left[i]]++;
        }
    }
    int l_n = t - l_qm;
    int r_n = t - r_qm;
    for (int i = 0; i < t; i++)
    {
        if(list[right[i]] >= 1){
            ans++;
            list[right[i]]--;
            r_n--;
            l_n--;
        }
    }
    if(l_n <= 0){
        l_n = t;
    }
    if(r_n <= 0){
        r_n = t;
    }
    ans += (min(l_qm,r_n) + min(r_qm,l_n));
    printf("%d\n",ans);
}