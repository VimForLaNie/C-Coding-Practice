#include <bits/stdc++.h>
using namespace std;

char pa[50001][71];
int row,col,ncol;

int main(){
	srand(time(NULL));
	FILE* fp;
	FILE* fpo;
	for(int i = 0; i < 50001; i++){
		for(int j = 0; j < 71; j++){
			pa[i][j] = 'o';
		}
	}
	fp = fopen("input.txt","w+");
	int n = rand() % 50001;
	fprintf(fp,"%d\n",n);
	for(int i = 0; i < n; i++){
		row = i + 1; col = (rand() % 70) + 1; ncol = rand() % (72 - col);
		fprintf(fp,"%d %d %d\n",row,col,ncol);
		for(int j = col; j <= (col + ncol - 1); j++){
			if(pa[i + 1][j] == 'x'){continue;}
			pa[i + 1][j] = 'x';
		}
	}
	fclose(fp);
	fpo = fopen("output.txt","w+");
	for(int i = 1; i < n; i++){
		for(int j = 1; j < 71; j++){
			fprintf(fpo,"%c",pa[i][j]);
		}
		fprintf(fpo,"\n");
	}
	fclose(fpo);
	fcloseall();
	cout << n << endl;
	cout << "done!!" << endl;
}
