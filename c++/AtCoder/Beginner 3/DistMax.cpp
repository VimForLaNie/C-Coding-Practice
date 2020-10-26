#include <bits/stdc++.h>
using namespace std;

int abs(int x){ return ((x < 0) ? -x : x);}

int xpos[200000];
int ypos[200000];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d %d",&xpos[i],&ypos[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) {continue;}
			ans = max(abs(xpos[i] - xpos[j]) + abs(ypos[i] - ypos[j]),ans);
		}
	} 
	printf("%d\n",ans);
}
