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

lli i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    get(n);
    lli arr[n];
    rep(i,0,n-1,1){ get(arr[i]); }
    sort(arr, arr + n);
    lli dif = arr[n - 1] - arr[0];   
    if(n == 2) { print_(dif); print_l("1"); return 0;}
    lli left = 0; lli right = n - 1;
    lli cnt_high = 0; lli cnt_low = 0;
    lli high = arr[n - 1]; lli low = arr[0];
    if(low == high) { print_(dif); print_l(n * (n - 1) / 2); return 0;}
    rep(i,0,n-1,1){ if(arr[i] == high){cnt_high++;} if(arr[i] == low) {cnt_low++;} }
    
    print_(dif); print_l(cnt_low * cnt_high);
    // main();
    return 0;
}