#include <bits/stdc++.h>
using namespace std;
#define modulo 123456789
#define mod(x) (x % modulo)
#define ll long long
#define lli long long int
#define rep(i,start,end,incre) for(__typeof(end) i = start; i <= end; i+=incre)
#define foreach(v) ll vector_size = v.size(); rep(ll i,0,vector_size - 1,1)
#define Pi acos(-1)
#define fi first
#define se second
#define vec vector
#define que queue
#define st stack
#define str string
#define p_q priority_queue
#define get(x) cin >> x
#define print_l(x) cout << x << endl
#define print_(x) cout << x << " "
#define print(x) cout << x
#define newline() cout << endl;
#define bool_tog(bool_x) bool_x = !bool_x
#define up_c(c) c - ((c >= 'a' && c <= 'z') ? 32 : 0)
#define low_c(c) c + ((c >= 'A' && c <= 'Z') ? 32 : 0)
//const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
//if broke
//#define int long long

ll i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<ll,ll> list;
    pair<ll,ll> ans;
    ans.fi = 100000000000;
    get(n);
    rep(i,1,n,1){
        get(t);
        list[t]++;
        if(t < ans.fi){
            ans.fi = t;
            ans.se = i;
        }
    }
    if(list[ans.fi] > 1){ print_l("Still Rozdil");}
    else{ print_l(ans.se); }
    
    return 0;
}