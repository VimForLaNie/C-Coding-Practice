#include <bits/stdc++.h>
using namespace std;

int seg_tree(int data[], int start_i, int end_i, int seg[], int index){
    if(start_i == end_i) {
        seg[index] = data[start_i];
         cout << "seg[" << index << "] = " << seg[index] << " -single node-" << endl;
        return data[start_i];
    }

    int mid = start_i + (end_i -start_i) / 2;
    seg[index] = seg_tree(data,start_i, mid, seg, 2*index + 1) + seg_tree(data,mid + 1, end_i, seg, 2*index + 2);
    cout << "seg[" << index << "] = " << seg[index] << " -range node- @ " << start_i << " " << end_i << endl;
    return seg[index];
}

void seg_update(int seg[] ,int data[],int pos, int start_i, int end_i, int val,int index){
    if(pos < start_i || pos > end_i) { return; }
    seg[index] += val;
    cout << val << endl;
    cout << "seg[" << index << "] = " << seg[index] << endl;

    if(start_i != end_i){
        int mid = start_i + (end_i - start_i) / 2;
        seg_update(seg,data,pos,start_i,mid,val,2 * index + 1);
        seg_update(seg,data,pos,mid + 1,end_i,val,2 * index + 2);
    }
}

int getsum(int start_i,int end_i,int seg[],int start_tree, int end_tree,int index){
    if(start_i <= start_tree && end_i >= end_tree){ cout << "found the range : " << seg[index] << endl; return seg[index]; }
    if(end_tree < start_i || start_tree > end_i) { cout << "out of bound : " << start_i << " " << end_i << " : " << start_tree << " " << end_tree << endl; return 0; }

    int mid = start_tree + (end_tree -start_tree) / 2;
    cout << "computing . . ." << endl;
    return  getsum(start_i,end_i,seg,start_tree,mid,2*index + 1) +
            getsum(start_i,end_i,seg,mid + 1,end_tree,2*index + 2);
}

int main(){
    int n,m;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int seg[100];
    for(int i = 0; i < 100; i++){ seg[i] = 0; }
    seg_tree(arr,0,n-1,seg,0);
    for(int i = 0; i < 100; i++){ cout << seg[i] << " ";} cout << endl;
    cin >> m;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cout << getsum(a,b,seg,0,n-1,0) << endl;
    }
    int x;
    cin >> x;
    for(int i = 0; i < x; i++){
        cin >> a >> b;
        seg_update(seg,arr,a,0,n - 1,b - arr[a],0);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cout << getsum(a,b,seg,0,n-1,0) << endl;
    }
}
