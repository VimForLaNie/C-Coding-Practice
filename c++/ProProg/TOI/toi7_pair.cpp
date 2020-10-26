#include <bits/stdc++.h>
using namespace std;

#define block 317
pair<int,int> arr[100001];
int aa[100001];
int ab[100001];
long long qs[block][100001];
long long cnter[100001];
long long gg[block];
long long int n,sum,ca,cb;
int* up;

long long solve(int st, int ed, int con,int pooh){
	//printf("____from %d -> %d \n",st,ed - 1);
	long long res = 0;
	int x = st / block, y = ed / block;
	if(x == y){
		for(int i = st; i < ed; i++){
			res += (pooh + aa[i]) * (ab[i] < con);
		}
	}
	else{
		for(int i = st; i < (x * block) && i < 100001 - 1;i++){
			res += (pooh + aa[i]) * (ab[i] < con); 
		}
		
		for(int i = x + 1; i < y && i < 100001; i++){
			res += gg[i] - qs[i][con + 1] + ((long long)pooh * block) - ((long long)pooh - cnter[con + 1]);
		}
		for(int i = y * block; i < ed && i < 100001; i++){
			res += (pooh + aa[i]) * (ab[i] < con);
		}
	}
	//cout << "----res :" << res << endl;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){ cin >> arr[i].first >> arr[i].second; }
	sort(arr,arr + n);
	for(int i = 0; i < n; i++){ aa[i] = arr[i].first; ab[i] = arr[i].second; }
	
	//pre calc
	for(int i = 0; i < block; i++){
		for(int j = 0; j < n; j++){
			gg[j / block] += aa[j];
			qs[i][ab[j] + 1] += aa[j];
			cnter[ab[j] + 1]++;
		}
		for(int j = 100000; j > 0; j--){
			qs[i][j - 1] += qs[i][j];
		}
	}
	
	//calc
	for(int i = 0; i < n; i++){
		//printf("%f %% completed . . \n",(float)i / n * 100);
		ca = aa[i]; cb = ab[i];
		up = upper_bound(aa, aa + n, ca);
		if(up == aa + n) { continue; }
		sum += solve(up - aa, n, cb, ca);
	}
	cout << sum << "\n";
	

	return 0;
}
