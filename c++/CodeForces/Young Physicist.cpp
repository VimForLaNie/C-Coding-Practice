#include <bits/stdc++.h>
using namespace std;

int x,y,z;
int sx,sy,sz;

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> x >> y >> z;
        sx += x; sy += y; sz += z;
    }
    if(sx == 0 && sy == 0 && sz == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}