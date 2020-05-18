#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define vec vector
#define que queue
#define st stack
#define str string
#define p_q priority_queue

#define Pi acos(-1)
//const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
#define modulo 123456789

#define mod(x) (x % modulo)
#define rep(i,start,end,incre) for(__typeof(end) i = start; i <= end; i+=incre)
#define bool_tog(bool_x) bool_x = !bool_x
#define up_c(c) c -= ((c >= 'a' && c <= 'z') ? 32 : 0)
#define low_c(c) c += ((c >= 'A' && c <= 'Z') ? 32 : 0)

#define fi first
#define se second

#define get(x) cin >> x
#define print_l(x) cout << x << endl
#define print_(x) cout << x << " "
#define print(x) cout << x
#define newline() cout << endl;

int i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    get(n);
    deque < pair<int,int> > arr;
    map <int,int> count_occur;
    map <int,int> ans;
    rep(i,0,n-1,1){ get(m); arr.push_back({m,i}); count_occur[m]++;}
    sort(arr.begin(), arr.end());

    while(!arr.empty()){
        if(count_occur[arr[0].fi] == 1){ ans[arr[0].fi] == 0; arr.pop_front(); continue; }
        if(arr[0].fi == arr[1].fi){
            if(ans[arr[0].fi] == 0) { ans[arr[0].fi] = arr[1].se - arr[0].se; arr.pop_front(); continue; } 
            else if(ans[arr[0].fi] == arr[1].se - arr[0].se && ans[arr[0].fi] != -1){ arr.pop_front(); continue; }
            else if(ans[arr[0].fi] != arr[1].se - arr[0].se) { ans[arr[0].fi] = -1; arr.pop_front(); continue; }
        }
        else{ arr.pop_front(); continue; }
    }
    int offset = 0;
    for(auto const& x : ans) { if(x.se == -1) {offset++;}}
    print_l(ans.size() - offset);
    for(auto const& x: ans){
        if(x.se != -1){ print_(x.fi); print_l(x.se); }
    }
    // main();
    return 0;
}