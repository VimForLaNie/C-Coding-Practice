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

int i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    get(n);
    pair<int,int> point[n];
    rep(i,0,n - 1,1){
        get(point[i].fi); get(point[i].se);
    }
    bool up = 0,down = 0,left = 0,right = 0;
    cnt = 0;
    rep(i,0,n - 1,1){
        up = 0; left = 0; right = 0; down = 0;
        rep(j,0,n - 1,1){
            if(j == i) { continue; }
            if(point[j].fi > point[i].fi && point[i].se == point[j].se){
                right = true;
            }
            if(point[j].fi < point[i].fi && point[i].se == point[j].se){
                left = true;
            }
            if(point[j].fi == point[i].fi && point[i].se < point[j].se){
                down = true;
            }
            if(point[j].fi == point[i].fi && point[i].se > point[j].se){
                up = true;
            }
        }
        if(up && down && left && right){
            cnt++;
        }
    }
    print_l(cnt);
    // main();
    return 0;
}