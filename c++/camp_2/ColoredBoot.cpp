#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int ans = 0;
    scanf(" %d",&t);
    char left[t];
    char right[t];
    int l_qm = 0;
    int r_qm = 0;
    map < char,int > list;
    scanf(" %s",left);
    scanf(" %s",right);
    for(int i = 0; i < t; i++){
        if(right[i] == '?'){
            r_qm++; //count right question mark
        }
        if(left[i] == '?'){
            l_qm++; //count left question mark
        }
        else{
            list[left[i]]++; //count how many pair can left[i] make
        }
    }
    int l_n = t - l_qm; //get normal left shoe
    int r_n = t - r_qm; // get normal right shoe
    for (int i = 0; i < t; i++)
    {
        if(list[right[i]] >= 1){ //if can make pair
            ans++; //add number of pairs answer  
            list[right[i]]--;
            r_n--;
            l_n--; //remove shoes from the pairing
        }
    }
    if(l_n <= 0){//if there are no normal left shoes left
        l_n = t; 
    }
    if(r_n <= 0){//if there are no normal right shoes left
        r_n = t; 
    }
    ans += (min(l_qm,r_n) + min(r_qm,l_n)); //pairing with all the question marks
    printf("%d\n",ans);
}