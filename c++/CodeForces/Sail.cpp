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

ll i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    get(t);
    ll s_x,s_y,e_x,e_y;
    get(s_x); get(s_y); get(e_x); get(e_y);
    str s;
    get(s);
    int size = s.size();
    bool r = 0,u = 0;
    ll d_x,d_y;
    d_x = e_x - s_x; d_y = e_y - s_y;
    if(d_x > 0){ r = 1;}
    else{r = 0;}
    if(d_y > 0){ u = 1; }
    else{u = 0;}
    int ans;
    rep(i,0,size - 1, 1){
        if(d_x == 0 && d_y == 0) { ans = i; break;}

        if(r && s[i] == 'E' && d_x != 0){ d_x--; }
        if(!r && s[i] == 'W' && d_x != 0) { d_x++; }
        if(u && s[i] == 'N' && d_y != 0) { d_y--; }
        if(!u && s[i] == 'S' && d_y != 0) { d_y++; }
    }
    if(d_x != 0 || d_y != 0) { print("-1"); }
    else{ print(ans); }

    return 0;
}