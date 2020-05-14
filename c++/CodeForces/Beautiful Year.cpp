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
//if broke
//#define int long long

int i,j,k,n,m,t;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
    get(n);
    n++;
    int digit_1;
    int digit_2;
    int digit_3;
    int digit_4;
    while(true){
        digit_1 = n % 10;
        digit_2 = (n % 100) / 10;
        digit_3 = (n % 1000) / 100;
        digit_4 = (n % 10000) / 1000;
        if(digit_1 != digit_2 && digit_1 != digit_3 && digit_1 != digit_4
        && digit_2 != digit_3 && digit_2 != digit_4
        && digit_3 != digit_4){
            print_l(n);
            break;
        }
        n++;
    } 
  return 0;
}