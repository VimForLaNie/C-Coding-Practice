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

bool check(int stt, int e,str s){
    bool one = false, two = false, three = false;
    for(int i = stt; i < e; i++){
        if(one && two && three) { return true; }
        if(s[i] == '1') { one = true; }
        if(s[i] == '2') { two = true; }
        if(s[i] == '3') { three = true; }
    }
    return (one && two && three);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--){
        str s;
        cin >> s;
        int size = s.size();
        int stt = 0,ed = size;
        while(ed - stt > 2){
            if(!check(stt,ed,s)) { ed++; break; }
            ed--;
        }
        while(ed - stt > 2){
            if(!check(stt,ed,s)) { stt--; break; }
            stt++;
        }
        cout << ed - stt << endl;
    }
    
    return 0;
}