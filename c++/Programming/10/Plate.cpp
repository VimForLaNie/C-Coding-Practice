#include <bits/stdc++.h>
using namespace std;

int c,n,cl,id;
map <int,int> st;
vector <int> arr;
queue <int> ans;
bool done = false;

int main(){
    scanf("%d %d",&c,&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&cl,&id);
        st[id] = cl;
    }
    char input;
    int arr_s;
    int last_index;
    while(1){
        scanf("%c",&input);
        switch(input){
        case 'E':
            arr_s = arr.size();
            last_index = -1;
            scanf("%d",&id);
            for(int i = 0; i < arr_s; i++){
                if(st[arr[i]] == st[id]){
                    last_index = i;
                }
            }
            if(last_index == -1) { arr.push_back(id); }
            else{ arr.insert(arr.begin() + last_index + 1,id); }
            break;
        case 'D':
            ans.push(arr[0]);
            arr.erase(arr.begin());
            break;
        case 'X':
            ans.push(0);
            done = true;
            break;
        }
        if(done) { break; }
    }
    while(!ans.empty()) { printf("%d\n",ans.front()); ans.pop(); }
    return 0;
}
