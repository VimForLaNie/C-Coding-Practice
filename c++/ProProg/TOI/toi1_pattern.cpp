#include <bits/stdc++.h>
using namespace std;

int pa[50001][72];
int n,row,col,ncol,maxr = -INT_MAX;
int sum;

int main (){
	ios::sync_with_stdio(0);
    cin.tie(0);
  
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> row >> col >> ncol;
		maxr = max(row,maxr);
		pa[row][col] += 1;
		pa[row][col + ncol] -= 1;
	}
	for(int i = 1; i <= maxr; i++){
		for(int j = 1; j <= 71; j++){
			sum += pa[i][j];
			if(j == 71) { break; }
			if(sum >= 1){
				cout << "x";
			}
			else{
				cout << "o";
			}
		}
		cout << "\n";
	}
}
