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
//if broke
//#define int long long

int i,j,k,n,m,t;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
    int off_i[4] = {0,-1,0,1};
    int off_j[4] = {-1,0,1,0};
    int count[3][3];
    int sum[3][3];
    rep(i,0,2,1){
        rep(j,0,2,1){
            sum[i][j] = 0;
            get(count[i][j]);
        }
    }
    rep(i,0,2,1){
        rep(j,0,2,1){
            sum[i][j] += count[i][j];
            rep(k,0,3,1){
                if(i + off_i[k] < 0 || i + off_i[k] > 2 || j + off_j[k] < 0 || j + off_j[k] > 2){
                    continue;
                }
                sum[i][j] += count[i + off_i[k]][j + off_j[k]]; 
            }
            sum[i][j] = (sum[i][j] % 2) ? 0 : 1;
        }
    }
    rep(i,0,2,1){
        rep(j,0,2,1){
            print(sum[i][j]);
        }
        newline();
    }
  return 0;
}