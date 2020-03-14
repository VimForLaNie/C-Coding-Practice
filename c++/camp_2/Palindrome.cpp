#include <bits/stdc++.h>
using namespace std;
#define ll long long
int i,n,str_size;
string mstr;

string get_s(){ //implement string receiver with string size
    str_size = 0;
    string s = "";
    char c = getchar();
    if(c == '\n'){
        c = getchar(); //if there is '\n' left in stdin ignore it
    }
    while(c != '\n'){
        s += c;
        str_size++;
        c = getchar();
    }
    return s;
}

bool palin(string str,int l, int r){ //recursive palindrome function
    if(l == r){
        return true;
    }
    else if(l > r){
        return true ? (str[l] == str[r]) : false;
    }
    if(str[l] == ' '){ //skip spaces
        palin(str,l + 1,r);
    }
    if(str[r] == ' '){
        palin(str,l,r - 1);
    }
    if(str[l] == str[r]){
        palin(str,l + 1, r- 1);
    }
    else{
        return false;
    }
}

int main(){
    cin >> n;
    for(i = 0; i < n; i++){
        mstr = get_s();
        if(palin(mstr,0,str_size - 1)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}
