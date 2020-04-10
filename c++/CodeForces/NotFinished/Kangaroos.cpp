#include <bits/stdc++.h>
using namespace std;

int i,n,high,ans;


int main(){
    priority_queue <int> holder;
    priority_queue <int> holded;
    cin >> n;
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > high){
            high = arr[i];
        }
    }
    for(i = 0; i < n; i++)
    {
        if(2 * arr[i] <= high){
            holded.push(arr[i]);
        }
        else{
            if(!holder.empty()){
                if(2 * arr[i] <= holder.top()){
                    ans++;
                    holder.pop();
                }
            }
            else{
                holder.push(arr[i]);
            }
        }
    }
    while(!holder.empty() && !holded.empty()){
        if(holder.top() > holded.top() * 2){
            holder.pop();
            holded.pop();
            ans++;
        }
        else{
            holder.push(holded.top());
            holded.pop();
        }
        if(holder.empty() && !holded.empty()){
            holder.push(holded.top());
            holded.pop();
        }
    }
    while(!holder.empty()){
        ans++;
        holder.pop();
    }
    while(!holded.empty()){
        ans++;
        holded.pop();
    }
    cout << ans << endl;
}