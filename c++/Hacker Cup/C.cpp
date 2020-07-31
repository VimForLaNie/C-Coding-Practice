#include <bits/stdc++.h>
using namespace std;
ofstream outf ("C-out.txt");
ifstream inf ("C-in.txt");

priority_queue< pair < pair<long long , long long>, long long> > iv;

void solve(int c_n){
    cout << "Case #" << c_n << ":" << endl;
    long long st_iv,ed_iv,id;
    vector<pair<long,long>> ans_iv;
    long long a = -1,b = -1,l_id = 0;
        st_iv = -iv.top().first.first;
        ed_iv = iv.top().first.second;
        id = iv.top().second;
        iv.pop();
    a = st_iv; b = ed_iv; l_id = id;
    cout << "start pos : " << st_iv << " " << ed_iv << endl;
    while(!iv.empty()){
        st_iv = -iv.top().first.first;
        ed_iv = iv.top().first.second;
        id = iv.top().second;
        cout << "next : " << st_iv << " " << ed_iv << endl;

        if(st_iv > ed_iv) { continue; iv.pop(); }
        if(st_iv < b){ ans_iv.push_back({st_iv,ed_iv}); cout << "pushing. . ." << endl; iv.pop(); continue;}
        if(b == st_iv && id != l_id) { b = ed_iv; l_id = id; cout << "connecting. . ." << endl; continue; }
        if(st_iv > b) { ans_iv.push_back({a,b}); cout << "pushing. . ." << endl; a = st_iv; b = ed_iv; l_id = id;}
    }
    if(a < b) { ans_iv.push_back({a,b}); cout << "pushing. . . ." << endl; }
    long long ans = -1;
    long long s = ans_iv.size();
    for(long long i = 0; i < s; i ++){
        cout << "ans_iv : " << ans_iv[i].first << " " << ans_iv[i].second << endl;
        if(ans_iv[i].second - ans_iv[i].first > ans){
            ans = (ans_iv[i].second - ans_iv[i].first);
        }
    }
    cout << "ans : " << ans << endl;
    return;
}

int main(){
    long long t,ca = 1,n,a,b;
    cin >> t;
    while(ca <= t){
        cin >> n;
        while(n--){
            cin >> a >> b;
            iv.push({{-a,a + b},n});
            iv.push({{-a + b,a},n});
        }
        solve(ca++);
    }

    return 0;
}

