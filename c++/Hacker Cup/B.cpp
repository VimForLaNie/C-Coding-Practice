#include <bits/stdc++.h>
using namespace std;
ifstream inf ("B-in.txt");
ofstream outf ("B-out.txt");
string rstr;

void solve(int c_n, string str, int s){
    outf << "Case #" << c_n << ":" << " ";
    cout << "Case #" << c_n << endl;
    cout << str << endl;
    int n_a = 0,n_b = 0;
    for(int i = 0; i < s; i++){ if(str[i] == 'A') {n_a++;} else {n_b++;} }
    if(n_a < n_b){
        for(int i = 0; i < s; i++){
            cout << "s = " << s << endl;
            if(str[i] == 'A') {
                if(i > 1) {
                    cout << "cs 1a" << endl;
                    if(str[i] != str[i - 1] || str[i] != str[i - 2] && str[i] - 'A' + str[i - 1] - 'A' + str[i - 2] - 'A' == 1){
                        str.erase(str.begin()+ (i - 2), str.begin() + (i - 1));
                        str[i - 2] = 'A';
                        cout << "looping" << endl;
                        i = 0; s-= 2;if(s == 1) { outf << "Y" << endl; return; } continue;
                    }
                }
                if(i > 0 && i < s - 1){
                    cout << "cs 2a" << endl;
                    if(str[i] != str[i - 1] || str[i] != str[i + 1] && str[i] - 'A' + str[i + 1] - 'A' + str[i - 1] - 'A' == 1){
                        str.erase(str.begin()+ i + 1);
                        str.erase(str.begin()+ i - 1);
                        str[i - 1] = 'A';
                        cout << "looping" << endl;
                        i = 0; s-= 2;if(s == 1) { outf << "Y" << endl; return; } continue;
                    }
                }
                if(i < s - 2){
                    cout << "cs 3a" << endl;
                    if(str[i] != str[i + 1] || str[i] != str[i + 2] && str[i] - 'A' + str[i + 1] - 'A' + str[i + 2] - 'A' == 1){
                        str.erase(str.begin()+ (i + 1), str.begin() + (i + 2));
                        str[i] = 'A';
                        cout << "looping" << endl;
                        i = 0; s-= 2;if(s == 1) { outf << "Y" << endl; return; } continue;
                    }
                }
            }
        }
        outf << "N" << endl;
    }
    else{
        for(int i = 0; i < s; i++){
            cout << "s = " << s << endl;
            s = str.size();
            if(s == 1) { outf << "Y" << endl; cout << "N"; return;}
            if(str[i] == 'B') {
                if(i > 1) {
                    cout << "cs 1" << endl;
                    if(str[i] != str[i - 1] || str[i] != str[i - 2] && str[i] - 'A' + str[i - 1] - 'A' + str[i - 2] - 'A' == 2){

                        str.erase(str.begin() + i - 2, str.begin() + i - 1);
                        str[i - 2] = 'B';
                        cout << "looping" << endl;
                        i = 0; s-= 2;if(s == 1) { outf << "Y" << endl; return; } continue;
                    }
                }
                if(i > 0 && i < s - 1){
                    cout << "cs 2" << endl;
                    if(str[i] != str[i - 1] || str[i] != str[i + 1] && str[i] - 'A' + str[i + 1] - 'A' + str[i - 1] - 'A' == 2){
                        cout << "here" << endl;
                        cout << i << endl;
                        str.erase(str.begin()+ i + 1);
                        str.erase(str.begin()+ i - 1);
                        str[i - 1] = 'B';
                        cout << "looping" << endl;
                        i = 0; s-= 2;if(s == 1) { outf << "Y" << endl; return; } continue;
                    }
                }
                if(i < s - 2){
                    cout << "cs 3" << endl;
                    if(str[i] != str[i + 1] || str[i] != str[i + 2] && str[i] - 'A' + str[i + 1] - 'A' + str[i + 2] - 'A' == 2){
                        str.erase(str.begin()+ (i + 1), str.begin() + (i + 2));
                        str[i] = 'B';
                        cout << "looping" << endl;
                        i = 0; s-= 2;if(s == 1) { outf << "Y" << endl; return; } continue;
                    }
                }
            }
        }
        outf << "N" << endl;
    }
}

int main(){
    int t,n,ca = 1;
    if(inf.is_open()){
        getline(inf,rstr);
        t = stoi(rstr);
        if(outf.is_open()){
            while(ca <= t){
                getline(inf,rstr);
                n = stoi(rstr);
                getline(inf,rstr);
                cout << "solving . . ." << endl;
                solve(ca++,rstr,n);
            }
        } else { cout << "Can't Open output file" << endl; }
        outf.close();
    } else { cout << "Can't Open input file" << endl;}
    inf.close();

    return 0;
}
