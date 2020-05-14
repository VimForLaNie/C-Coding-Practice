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
    
    str a,b;
    get(a); get(b);
    int sb = b.size();
    int sum_a = 0;
    int sum_b = 0;
    rep(i,0,sb - 1,1){
        a[i] = low_c(a[i]);
        b[i] = low_c(b[i]);
        sum_a += a[i];
        sum_b += b[i];
    }
    if(sum_a < sum_b){
        int check_a = 0;
        int check_b = 0;
        rep(i,0,sb - 1, 1){
            check_a += a[i];
            check_b += b[i];
            if(check_a < check_b){
                print_l("-1");
                return 0;
            }
            else if(check_a > check_b){
                print_l("1");
                return 0;
            }
        }
        print_l("-1");
    }
    else if(sum_b == sum_a){
        int check_a = 0;
        int check_b = 0;
        rep(i,0,sb - 1, 1){
            check_a += a[i];
            check_b += b[i];
            if(check_a < check_b){
                print_l("-1");
                return 0;
            }
            else if(check_a > check_b){
                print_l("1");
                return 0;
            }
        }
        print_l("0");
    }
    else{
        int check_a = 0;
        int check_b = 0;
        rep(i,0,sb - 1, 1){
            check_a += a[i];
            check_b += b[i];
            if(check_a < check_b){
                print_l("-1");
                return 0;
            }
            else if(check_a > check_b){
                print_l("1");
                return 0;
            }
        }
        print_l("1");
    }
    // main();
    return 0;
}