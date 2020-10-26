#include <bits/stdc++.h>
using namespace std;

int main(){
    string read;
    cin >> read;
    int cnt = 0;

    int s_read = read.size();
    for(int i = 0; i < s_read; i++){
        cnt += (read[i] - '0');
        cout << "cnt : " << cnt << endl;
    }
    cout << "cnt : " << cnt << endl;
    if(cnt % 9 == 0) {cout << "Yes" << endl;}
    else { cout << "No" << endl; }
    return 0;
}
