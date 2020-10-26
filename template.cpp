#include <bits/stdc++.h>
using namespace std;
 
#define modulo 199999991
#define pi acos(-1)
 
#define ll long long
#define lli long long int
#define ld long double
#define pii pair<int,int>
#define vec vector
#define stk stack
#define que queue
#define deq deque
#define str string
#define p_q priority_queue
#define adj_list(x) __typeof(x) adj_list[x][x]
 
#define pb push_back
#define fi first
#define se second
 
#define graph(x) vec<__typeof(x)>g [x + 1]
#define mid(x,y) (y > x) ? (x + (y - x) / 2) : (y + (x - y) / 2)
#define up_c(z) z = (z >= 'a' && z <= 'z') ? z - 'a' + 'A' : z
#define low_c(z) z = (z >= 'A' && z <= 'Z') ? z + 'a' - 'A' : z
#define mod(x) (x % modulo)
#define togg(x) (x = !x)
#define Fill(v,x) memset(v,x,sizeof(v))
 
template <typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template <typename T> T Sqr(T x) { return(x * x); }
template <typename T> T gcd (T a, T b){ return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm (T a, T b){ return a*b/gcd(a,b); }
template <typename T> T Pow (T a, T b){ T res = 1; while(b){ if(b & 1) {res*= a;} a *= a; b >>= 1; } return res;}
 
const int inf = INT_MAX;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    
 
    return 0;
}