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
    
    map<char,int> list;
    get(k);
    str s;
    get(s);
    int size = s.size();
    rep(i,0,size - 1,1){ list[s[i]]++; }
    for(auto &x : list){
        if(x.se % k != 0){
            print("-1");
            return 0;
        }
        else{
            x.se = x.se / k;
        }
    }   
    rep(j,1,k,1){
        for(auto &x : list){
            rep(i,0,x.se - 1,1){
                print(x.fi);
            }
        }
    }
    return 0;
}