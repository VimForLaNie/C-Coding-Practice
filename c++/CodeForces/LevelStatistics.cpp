#include <bits/stdc++.h>
using namespace std;

int i,t,n;
bool ans;

int main(){
    cin >> t;
    while(t--){
        ans = true;
        cin >> n;
        pair <int,int> rec[n];
        for(i = 0; i < n; i++){
            cin >> rec[i].first >> rec[i].second;
            if(i){
                if(rec[i].first < rec[i - 1].first //play decreased
                || rec[i].second < rec[i - 1].second //clear decreased
                || rec[i].first < rec[i].second //clear more than play
                || (rec[i].second > rec[i - 1].second && rec[i].first <= rec[i-1].first)){ // play -- clear ^^
                    ans = false;
                }
            }
        }
        if(ans){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}