#include <bits/stdc++.h>
using namespace std;

vector<char> v;

int main(){
    int ss = -1;
    string str;
    int n;
    cin >> n;
    while(n--){
        cin >> str;
        for(auto x : str){
            v.push_back(x);
            ss++;
            //for(auto c : v) { cout << c;} cout << endl;
            if(ss < 1) { continue; }
            if(v[ss] - v[ss - 1] == 1 || v[ss] - v[ss - 1] == 2 ){ v.pop_back(); v.pop_back(); ss-=2; }
        }
        if(v.empty()){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
        v.clear();
        ss = -1;
    }
    return 0;
}
