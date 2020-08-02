#include <bits/stdc++.h>
using namespace std;

map<vector<int>,int> m;

int main(){
    int t,n,temp_in,high = -1,cnt = 0;
    vector<int> temp;
        while(1){
        cin >> n;
        if(!n){ return 0; }
        while(n--){
            for(int i = 0; i < 5; i++) { cin >> temp_in; temp.push_back(temp_in);}
            sort(temp.begin(), temp.end());
            m[temp]++;
            temp.clear();
        }
        for(auto x : m) { if(x.second > high){ high = x.second; } }
        //cout << "max : " << high << endl;
        for(auto x : m) { if(x.second == high){ cnt+=x.second; } }
        //cout << "cnt : " << cnt << endl;
        if(cnt > 1) { cout << cnt << endl; }
        else{ cout << high << endl; }
        cnt = 0; high = -1;
        m.clear();
        }
}
