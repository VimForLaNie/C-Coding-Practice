#include <bits/stdc++.h>
using namespace std;

bool in[51];
bool out[51];
bool ans[51][51];
ofstream outf ("A-out.txt");
ifstream inf ("A-in.txt");
string rstr;

void solve(int n_c, int arr_size){
    outf << "Case #" << n_c << ":" << endl;

    for(int i = 1; i <= arr_size; i++){
        for(int j = i; j <= arr_size; j++){
            if(i == j) { ans[i][j] = 1; continue;}
            if(!out[i] || !in[j]) { ans[i][j] = 0; continue;}
            if(ans[i][j - 1] && out[j-1]) { ans[i][j] = 1; continue; }
        }
        for(int j = i - 1; j >= 1; j--){
            if(!out[i] || !in[j]) { ans[i][j] = 0; continue;}
            if(ans[i][j + 1] && out[j+1]) { ans[i][j] = 1; continue; }
        }
    }

    for(int i = 1; i <= arr_size; i++){
    for(int j = 1; j <= arr_size; j++){
        if(ans[i][j]) {outf << "Y";}
        else { outf << "N";}
    }
    outf << endl;
    }
    cout << "Done with Case#" << n_c << endl;
}

int main(){
    int t,n,ca = 1,s;
    if(inf.is_open()){
        cout << "input file open. . ." << endl;
        getline(inf,rstr);
        t = stoi(rstr);
        cout << "T = " << t << endl;
        if(outf.is_open()){
            cout << "output file open. . ." << endl;
            while(ca <= t){
                getline(inf,rstr);
                n = stoi(rstr);
                cout << "n = " << n << endl;

                getline(inf,rstr);
                cout << "rstr1 = " << rstr << endl;
                for(int i = 0; i < n; i++) {if(rstr[i] == 'Y') { in[i + 1] = true; } else { in[i + 1] = false; }}
                getline(inf,rstr);
                cout << "rstr2 = " << rstr << endl;
                for(int i = 0; i < n; i++){ if(rstr[i] == 'Y') { out[i + 1] = true; } else { out[i + 1] = false; }}
                cout << "Solving . . ." << endl;
                solve(ca++,n);
            }
        } else { cout << "Can't open output file" << endl; }
        outf.close();
    } else { cout << "Can't open input file" << endl; }
    inf.close();
    return 0;
}
