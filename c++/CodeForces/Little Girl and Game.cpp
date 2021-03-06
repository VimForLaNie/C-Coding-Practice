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
    
    str s;
    get(s);   
    int odd_occur = 0;
    int size = s.size();
    map <char,int> occur;
    rep(i,0,size - 1,1){ occur[s[i]]++; }
    for(auto &x : occur){ odd_occur += (x.se % 2 == 1) ? 1 : 0; }

    if(odd_occur <= 1){
        if((odd_occur - 1) % 2 == 1){ print("Second"); }
        else{ print("First"); }
        return 0;
    }
    if(odd_occur % 2 == 0) { print("Second"); }
    else{ print("First"); }

    return 0;
}