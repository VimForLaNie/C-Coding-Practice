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


int i,j,k,n,m,t,cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int,int> list;

    char s[300];
    fgets(s,300,stdin);
    for(int i = 0; i < 300; i++){
        if(s[i] == '\n') { break; }
        if(s[i] == ' ') { continue; }
        list[s[i]]++;
    }
    fgets(s,201,stdin);
    for(int i = 0; i < 300; i++){
        if(s[i] == '\n') { break; }
        if(s[i] == ' ') { continue; }
        if(list[s[i]] == 0){ 
            cout << "NO" << endl; 
            return 0;
        }
        list[s[i]]--;
    }
    cout << "YES" << endl;
    return 0;
}