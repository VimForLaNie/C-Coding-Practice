#include <bits/stdc++.h>
using namespace std;
int i,j,k;
int n,m;
int cnt[26];


int main(){
    int t;
    cin >> t;
    for(i = 0; i < t; i++){
        cin >> n >> m ;
        char mystr[n];
        int rep[m];
        int s[m];
        for(j = 0; j < n; j++){
            cin >> mystr[j];
            cnt[mystr[j] - 'a']++;
        }
        for(j = 0; j < m; j++){
            cin >> s[j];
            for(k = 0; k < s[j];k++){
                rep[k]++;
            }
        }
        for(j = 0; j < m; j++){
            cnt[mystr[j] - 'a'] += rep[j];
        }
        for(j = 0; j < 26; j++){
            cout << cnt[j] << " ";
        }
        cout << endl;
        for(j = 0; j < 26;j++){
            cnt[j] = 0;
        }
    }
}