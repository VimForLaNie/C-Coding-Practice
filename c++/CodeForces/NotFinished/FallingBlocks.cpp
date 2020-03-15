#include <bits/stdc++.h>
using namespace std;
int cnt;

void Merge(vector <int>st, pair <int,int> b[],int arr[]){
    if(st.size() < 2){
        return;
    }
    else if(b[st.back()].first <= b[st[st.size() - 2]].first && b[st.back()].second <= b[st[st.size() - 2]].first
    || b[st.back()].first >= b[st[st.size() - 2]].second && b[st.back()].second >= b[st[st.size() - 2]].second){
        b[st.back()].first = min(b[st.back()].first,b[st[st.size() - 2]].first);
        b[st.back()].second = max(b[st.back()].second,b[st[st.size() - 2]].second);
        b[st[st.size() - 2]].first = b[st.back()].first;
        b[st[st.size() - 2]].second = b[st.back()].second;
        st.pop_back();
        arr[st.size() - 2] = 1;
        arr[st.back()] = 1;
        cnt++;
        return;
    }
    else{
        return;
    }
}

bool isCover(vector < int > st, pair <int,int> b[]){
    if(st.size() <= 1){
        return false;
    }
    if(b[st.back()].first <= b[st[st.size() - 2]].first && b[st.back()].second >= b[st[st.size() - 2]].second){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    vector <int> st;
    queue < int > ans;
    int n,d;
    scanf("%d %d",&n,&d);
    pair <int,int> block[n];
    int merge_i[n] = { 0 };
    for(int r = 0; r < n; r++){
        scanf("%d %d",&block[r].first,&block[r].second);
        st.push_back(r);
        Merge(st,block,merge_i);
        while(isCover(st,block)){
            int top = st.back();
            st.pop_back();
            st.pop_back();
            st.push_back(top);
            
        }
        int l = st.size();
        for (int x = 0; x < l; x++)
        {
            if(merge_i[st[x]] == 1){
                merge_i[st[x]] == 0;
                cnt--;
            }
        }
        ans.push(st.size() + cnt);
        
    }
    while(!ans.empty()){
        printf("%d\n",ans.front());
        ans.pop();
    }
}