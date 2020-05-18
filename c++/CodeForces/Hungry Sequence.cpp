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

void print_first_N_primes(int N) 
{ 
    // Declare the variables 
    ll i, j;
    bool flag; 
  
    // Traverse each number from 1 to N 
    // with the help of for loop 
    for (i = 1; i <= 1e7; i++) { 
        // Skip 0 and 1 as they are 
        // niether prime nor composite 
        if (i == 1 || i == 0) 
            continue; 
        // flag variable to tell 
        // if i is prime or not 
        flag = 1; 
        for (j = 2; j <= i / 2; ++j) { 
            if (i % j == 0) { 
                flag = 0; 
                break; 
            } 
        } 
        // flag = 1 means i is prime กกกก
        // and flag = 0 means i is not prime 
        if(cnt >= N){
            return;
        }
        if (flag == 1 && cnt < N){
            cnt++;
            cout << i << " "; 
        }
    } 
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    print_first_N_primes(n);
    
    return 0;
}