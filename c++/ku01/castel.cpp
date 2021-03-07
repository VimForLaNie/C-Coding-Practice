#include <bits/stdc++.h>
using namespace std;

vector<int> fl;
int cnt = 1,f,num,ans;
bool p;

int main(){
	while(cnt * cnt <= 100000){		
		fl.push_back(cnt*cnt);
		cnt++;
	}
	//for(auto x : fl) { cout << x << " ";} cout << endl;
	cin >> num;
	auto upp = upper_bound(fl.begin(),fl.end(),num);
	f = distance(fl.begin(),upp) + 1;
	//cout << "fl -- : " << fl[f - 1] << endl;
	if(fl[f - 2] == num) { f--; }
	if(num == 1) { f = 1; }
	if(num & 1) { p = 0; } else { p = 1; }
	//cout << "parity : " << p << endl;
	
	while(f > 1){
		if(!(f & 1)) {
			//cout << "floor : even\n";
			if(p){
				//cout << "exp : false\n";
				ans += 2; f--;
				p = !p;
			}
			else{
				//cout << "exp : true\n";
				ans += 1; f--;
			}
		}
		else{
			if(!p){
				//cout << "exp : true\n";
				ans += 2; f--;
				p = !p;
			}
			else{
				//cout << "exp : false\n";
				ans += 1; f--;
			}
		}
		
	}
	
	cout << ans << endl;
}
