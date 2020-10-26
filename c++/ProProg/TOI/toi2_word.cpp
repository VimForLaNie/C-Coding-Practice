#include <bits/stdc++.h>
using namespace std;
 
#define modulo 1e7 + 9
#define pi acos(-1)
#define inf INT_MAX
 
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
 
#define pb push_back
#define fi first
#define se second
 
#define mid(x,y) (y > x) ? (x + (y - x) / 2) : (y + (x - y) / 2)
#define up_c(z) z = (z >= 'a' && z <= 'z') ? z - 'a' + 'A' : z
#define low_c(z) z = (z >= 'A' && z <= 'Z') ? z + 'a' - 'A' : z
#define mod(x) (x % modulo)
#define togg(x) (x = !x)
#define Fill(v,x) memset(v,x,sizeof(v))
#define foriX(x) for(int i = 0; i < x; i++)
#define forXi(x) for(int i = x - 1; i >= 0; i--)
#define forjX(x) for(int j = 0; j < x; j++)
#define forXj(x) for(int j = x - 1; j >= 0; j--)
#define forAB(a,b) for(int i = a; i <= b; i++) 
 
template <typename T> T sqr(T x) { return(x * x); }
template <typename T> T gcd (T a, T b){ return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm (T a, T b){ return a*b/gcd(a,b); }
template <typename T> T Pow (T a, T b){ T res = 1; while(b){ if(b & 1) {res*= a;} a *= a; b >>= 1; } return res;}

#define N 25
#define M 25
int n,m;
char board[N][M];

void solve(str word){
	str ans;
	
	int ptr = 0;
	foriX(n){
		forjX(m){
			if(word[ptr] == board[i][j]){
				ptr = 1;
				//left-up
					if(word[ptr] == board[i - x][j - x]){
						ptr++;
					}
					else{
						break;
					}
				//left-left
				//left-down
				//right-up
				//right-right
				//right-down
				//up-up
				//down-down
			}
		}
	}
	
	return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
	
 
    return 0;
}
