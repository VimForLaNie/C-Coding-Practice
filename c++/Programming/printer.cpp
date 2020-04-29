#include <bits/stdc++.h>
using namespace std;

int main(){
	string char_array;
	string word;
	bool mode;
	int i;
	vector< int > range;
	vector< int > m[26];
	vector< int >::iterator it; 
	
	cin >> mode;
	cin >> char_array;
	cin >> word;
	
	long long cost = 0;
	int w_size = word.size();
	int c_a_size = char_array.size();
	int offset = 0;
	int r_size;

	for(i = 0; i < c_a_size; i++){
		cout << "alloc [" << char_array[i] - 'a' << "] : " << i + 1 << endl;
		m[char_array[i] - 'a'].push_back(i + 1);
	}

	if(!mode){
	/*-*/	cout << "NO" << endl;
		for(i = 0; i < w_size; i++){
/*-*/			cout << "looping . . ." << endl;
			if(m[word[i]-'a'].size() == 0){
				cout << "-1" << endl;
				return 0;
			}
			cost += m[word[i] - 'a'][0];
    		it = m[word[i] - 'a'].begin(); 
			m[word[i] - 'a'].erase(it);
		}
		cout << cost << endl;
	}
	else{	
		/*-*/cout << "YES" << endl;
		int j;
		for(i = 0; i < w_size; i++){
			/*-*/cout << "__-next char-___" << endl;
			r_size = range.size();
			offset = 0;
			if(m[word[i]-'a'].size() == 0){
				cout << "-1" << endl;
				return 0;
			}
			for(j = 0; j < r_size; j++){
				/*-*/cout << "@" << j << endl;
				cout << "****->" << m[word[i] - 'a'][0] << " && " <<  range[j] << endl;
					if(m[word[i] - 'a'][0] > range[j]){
					/*-*/cout << "offset - - - -" << endl;
					offset--;
				}
			}
			cost += m[word[i] - 'a'][0] + offset;
			range.push_back(m[word[i] - 'a'][0]);
			cout << "range + + +" << endl;
			it = m[word[i] - 'a'].begin();
			m[word[i] - 'a'].erase(it);
		}
		cout << cost << endl;
	}
	/*-*//*-*/int v_size;
	int j;
	char de;
	for(i = 0; i < 26; i++){
		v_size = m[i].size();
		de = 'a' + i;
		cout << de << " : ";
		for(j = 0; j < v_size; j++){
			cout << m[i][j] << " ";
		}
		cout << "size : " << v_size << endl;
	/*-*//*-*/}
	cout << "range : ";
	r_size = range.size();
	for(i = 0;i < r_size; i++){
		cout << range[i] << " ";
	}
	cout << endl;
}
