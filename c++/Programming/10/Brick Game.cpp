#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	string in;
	int num;
	cin >> n >> m;
	string map[n];
	int brick[m];
	char col[n];
	int i,j;
	for(i = 0; i < n; i++){
		cin >> in;
		map[i] = in;
	}
	for(i = 0; i < m; i++){
		cin >> brick[i];
	}

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){//copy
			col[j] = map[j][i];
		//	cout << col[j];
		}
		//cout << endl;

		int x,y;
		int ptr;
		//cout << "brick_fall -> ::" << brick[i] << endl;
		for(x = 0; x < n; x++){
		//	cout << "*******looping @ " << x << endl;
			ptr = x;
			if(x + 1 == n && col[x] == '.'){
		//		cout << "====end of col" << endl;
				for(y = 0;y < brick[i]; y++){
					col[ptr - y] = '#';	
		//			cout << "++placing . . .@" << ptr - y << endl;
				}
			}
			if(col[x] == 'O'){
		//		cout << "====found stone" << endl;
				ptr = x - 1;
				for(y = 0;y < brick[i]; y++){
		//			cout << "++placing . . . @" << ptr - y << endl;
					col[ptr - y] = '#';
				}
				break;
			}
		}

		for(j = 0; j < n; j++){//paste
			map[j][i] = col[j];
		//	cout << map[j][i];
		}
		//cout << endl;
	}
	int s;
	for(i = 0; i < n; i++){
		s = map[i].size();
		for(j = 0; j < s; j++){
			cout << map[i][j];
		}
		cout << endl;
	}	
	return 0;
}
