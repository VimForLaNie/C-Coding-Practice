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
    
    int hap[6][6];
    rep(i,1,5,1){
        rep(j,1,5,1){
            get(hap[i][j]);
        }
    }
    int a,b,c,d,e;
    int ans = 0;
    rep(a,1,5,1){
        rep(b,1,5,1){
            if(b == a) { continue; }
            rep(c,1,5,1){
                if(c == a) { continue; }
                if(c == b) { continue; }
                rep(d,1,5,1){
                    if(d == a) { continue; }
                    if(d == b) { continue; }
                    if(d == c) { continue; }
                    rep(e,1,5,1){
                        if(e == a) { continue; }
                        if(e == b) { continue; }
                        if(e == c) { continue; }
                        if(e == d) { continue; }
                        ans = max( (hap[a][b] + hap[b][a] + hap[c][d] + hap[d][c] + 
                                    hap[b][c] + hap[c][b] + hap[d][e] + hap[e][d] +
                                    hap[c][d] + hap[d][c] +
                                    hap[d][e] + hap[e][d]),ans);
                    }
                }
            }
        }
    }
    print(ans);
    return 0;
}