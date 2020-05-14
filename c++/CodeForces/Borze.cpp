#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans;
    int size = s.size();
    for(int i = 0; i < size; i++){
        if(i + 1 == size){
            if(s[i] == '.'){
                ans += '0';
            }
        }
        else{
            if(s[i] == '.'){
                ans += '0';
            }
            else if(s[i] == '-' && s[i + 1] == '.'){
                i++;
                ans += '1';
            }
            else if(s[i] == '-' && s[i + 1] == '-'){
                i++;
                ans += '2';
            }
        }
    }
    cout << ans;
}