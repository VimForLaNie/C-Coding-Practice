#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> li;
    string in;
    int ans;
    int ss,num;
    int diff;
    cin >> ss >> num;
    for(int i = 0; i < num; i++){
        cin >> in;
        li.push_back(in);
    }
    for(auto x : li){ cout << x << endl;}
    for(int i = 1; i < num; i++){
        diff = 0;
        for(int j = 0; j < ss; j++){
            if(li[i][j] != li[i - 1][j]) {diff++;}
            if(diff > 2) { ans = i - 1; }
        }
    }
    cout << li[ans] << endl;
}
