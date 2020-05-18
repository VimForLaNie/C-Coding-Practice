#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define vec vector
#define que queue
#define st stack
#define str string
#define p_q priority_queue
#define d_q dequeue

#define Pi acos(-1)
//const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
#define modulo 123456789

#define mod(x) (x % modulo)
#define bool_tog(bool_x) bool_x = !bool_x
#define up_c(c) c -= ((c >= 'a' && c <= 'z') ? 32 : 0)
#define low_c(c) c += ((c >= 'A' && c <= 'Z') ? 32 : 0)

#define fi first
#define se second


ll i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll list[8] = { 0 };

    cin >> n;
    ll arr[n];
    vec <str> ans;
    for(ll i = 0; i < n; i++) { cin >> arr[i]; list[arr[i]]++; }
    if(list[5] > 0 && list[7] > 0) { cout << "-1" << endl; return 0;}

    while(list[1] > 0 && list[2] > 0 && list[4] > 0 
        || list[1] > 0 && list[3] > 0 && list[6] > 0
        || list[1] > 0 && list[2] > 0 && list[6] > 0) {

        if(list[1] > 0 && list[2] > 0 && list[4] > 0){
            ans.push_back("1 2 4");
            list[1]--; list[2]--; list[4]--;
        }
        if(list[1] > 0 && list[3] > 0 && list[6] > 0){
            ans.push_back("1 3 6");
            list[1]--; list[3]--; list[6]--;
        }
        if(list[1] > 0 && list[2] > 0 && list[6] > 0){
            ans.push_back("1 2 6");
            list[1]--; list[2]--; list[6]--;
        }

    }
    for(ll i = 0; i < 8; i++){
        if(list[i] > 0){
            cout << "-1" << endl;
            return 0;
        }
    }

    ll size = ans.size();
    for(ll i = 0; i < size; i++){ cout << ans[i] << endl; }
    
    return 0;
}