#include <bits/stdc++.h>
using namespace std;

int main(){
	bool out = true;
	int n;
	FILE* check = fopen("output.txt","r+");
	FILE* ans = fopen("answer.txt","r+");
	
	cin >> n;
	char la[100],lc[100];
	while(n--){
		fscanf(check,"%s",lc);
		fscanf(ans,"%s",la);
		for(int i = 0 ; i < 100; i++){
			if(la[i] == lc[i]) { continue; }
			out = false;
		}
	}
	if(out) { cout << "NO" << endl; }
	else { cout << "YES" << endl; }
}
