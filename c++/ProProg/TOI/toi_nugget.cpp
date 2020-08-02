#include <bits/stdc++.h>
using namespace std;

int main(){
    int out = 1;
    const int nugget[] = {6,9,20};
    int num;
    cin >> num;
    for(int i = 0; i <= 20; i++){
        for(int j = 0; j <= 20; j++){
            for(int k = 0; k <= 20; k++){
                if(i == 0 && j == 0 && k == 0) { continue; }
                out = i * nugget[2] + j * nugget[1] + k * nugget[0];
                if(out > num) { continue; }
                cout << out << endl;
            }
        }
    }
}
