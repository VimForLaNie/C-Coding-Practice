#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = (a + b) xor (a + c);
    int ans_z = a + (b xor c) + c;
    cout << ans << endl << ans_z;
}