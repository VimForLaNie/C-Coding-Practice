#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    int req_sleep,fi_alarm,next_alarm,wait_time;
    ll ans = 0;
    ll cnt = 0;

    cin >> t;
    while(t--){
        cin >> req_sleep >> fi_alarm >> next_alarm >> wait_time; ans = 0;

        if(fi_alarm >= req_sleep) {cout << fi_alarm << endl; continue;}
        if(next_alarm < wait_time) { cout << "-1" << endl; continue; }

        req_sleep -= fi_alarm; ans += fi_alarm;

        cnt = (req_sleep / (next_alarm - wait_time));
        cnt += (req_sleep % (next_alarm - wait_time) > 0) ? 1 : 0;

        ans += (ll)next_alarm * cnt;

        cout << ans << endl;
    }
}