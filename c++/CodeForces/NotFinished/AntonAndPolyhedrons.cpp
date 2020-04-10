#include <bits/stdc++.h>
using namespace std;

int n,face,i;
string input;

int main(){
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> input;
        if(input == "Icosahedron"){
            face += 19;
        } 
        else if(input == "Cube"){
            face += 6;
        }
        else if(input == "Tetrahedron")
        {
            face += 5;
        }
        else if(input == "Dodecahedron")
        {
            face += 12;
        }
        else{
            face += 8;
        }
    }
    cout << face;
}