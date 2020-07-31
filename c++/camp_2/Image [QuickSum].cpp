#include <bits/stdc++.h>
using namespace std;

int sum[64][64];
int ans = 0;

void solve(int n,int i ,int j){
    cout << "@ " << i << " : " << j << " :: " << n << endl;
    if(n == 1){ ans += 2; cout << "++++2" << endl; return; }

    int ss = 0;
    for(int x = 0; x < n; x++){
        ss += sum[i + x][j + n - 1] - n;
    }
    cout << ss << endl;

    if(ss == -n * n || ss == 0 || ss == n * n) { ans += 2; cout << "++++2" << endl; return;}
    else { ans += 1; cout << "++++" << endl; solve(n / 2, i ,j + (n / 2)); solve(n / 2,i,j); solve(n / 2, i + (n / 2),j + (n / 2)); solve(n / 2, i + (n / 2),j);}

    return;
}

int main(){
    int n;
    cin >> n;
    int temp;
    int s = 0;
    for(int i = 0; i < n; i++){
        s = 0;
        for(int j = 0; j < n; j++){
            cin >> temp;
            s += temp;
            sum[i][j] = s;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    solve(n,0,0);
    cout << ans << endl;
}
