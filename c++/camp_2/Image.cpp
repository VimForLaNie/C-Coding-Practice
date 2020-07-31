#include <bits/stdc++.h>
using namespace std;

int img[64][64];
deque <char> ans;
bool one;
bool zero;

void sol(int n,int i,int j){
    cout << "sol : " << n << " " << i << " " << j << endl;
    one = false;
    zero = false;
    if(n == 1) {
        cout << "returning . . . + 2" << endl;
        if(img[i][j] == 0){ ans.push_back('0'); ans.push_back('0'); }
        else if(img[i][j] == 1){ ans.push_back('0'); ans.push_back('1'); }
        return;
    }
    for(int x = i; x < i + n; x++){
        for(int y = j; y < j + n; y++){
            cout << "@" << x << " : " << y << " == " << img[x][y] << endl;
            if(img[x][y] == 1){ one = true; }
            else if(img[x][y] == 0){ zero = true;}
        }
    }
    cout << one << " " << zero << endl;
    if(one && zero) { ans.push_back('1'); cout << "recurse =========== +1" << endl; sol(n / 2, i ,j + (n / 2)); sol(n / 2,i,j); sol(n / 2, i + (n / 2),j + (n / 2)); sol(n / 2, i + (n / 2),j);}
    else if(one && !zero) { ans.push_back('0'); ans.push_back('1'); cout << "one no zero + 2" << endl;}
    else if(!one && zero) { ans.push_back('0'); ans.push_back('0'); cout << "zero no one + 2" << endl;}
    return;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> img[i][j];
        }
    }
    sol(n,0,0);
    cout << "Ans : " << ans.size() << endl;
    for(auto x : ans) { cout << x;}
}
