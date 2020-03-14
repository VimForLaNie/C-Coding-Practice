#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt_ask = 0;
    char n_arr[10];
    int n;
    fgets(n_arr, 10, stdin);
    sscanf(n_arr,"%d ",&n);
    vector <int> arr;
    char rawInput[n][20];
    pair <int, pair <int,int> > input[n];
    for(int i = 0; i < n; i++){
        fgets(rawInput[i], 20, stdin);
        sscanf(rawInput[i],"%d %d %d",&input[i].first,&input[i].second.first,&input[i].second.second);
        if(input[i].first == 2){
            cnt_ask++;
        }
    }
    int i_ques = 0;
    int ans_wantnum_rep[cnt_ask] = { 0 };
    vector <int> ans_wantrep_num[cnt_ask];
    vector <int> ans_most_rep[cnt_ask];

    map <int,int> rep;
    map <int,int>::iterator it = rep.begin();

    for (int i = 0; i < n; i++)
    {
        int arr_size = arr.size();
        if(input[i].first == 1){
            arr.push_back(input[i].second.first);
            rep[arr.back()]++;
        }
        else if (input[i].first == 2)
        {
            if(arr_size == 0){
                continue;
            }
            int wantnum = input[i].second.first;
            int wantrep = input[i].second.second;
            ans_wantnum_rep[i_ques] = rep[wantnum];
            int max = 0;
            for (auto const& x : rep)
            {
                if(x.second >= max){
                    max = x.second;
                }
                if(x.second == wantrep){
                    ans_wantrep_num[i_ques].push_back(x.first);
                }

            }
            for (auto const& x : rep)
            {
                if(x.second == max && max != 0){
                    ans_most_rep[i_ques].push_back(x.first);
                }
            }
            int wantrep_size = ans_wantrep_num[i_ques].size();
            int mostrep_size = ans_most_rep[i_ques].size();
            printf("%d\n",ans_wantnum_rep[i_ques]);
            printf("%d ",wantrep_size);
            if(wantrep_size <= 5){
                for (int i = 0; i < wantrep_size ; i++)
                {
                    printf("%d ",ans_wantrep_num[i_ques][i]);
                }
            }
            printf("\n");
            printf("%d ",mostrep_size);
            if(mostrep_size <= 5){
                for (int i = 0; i < mostrep_size; i++)
                {
                    printf("%d ",ans_most_rep[i_ques][i]);
                }
            }
            printf("\n");
            i_ques++;
        }
    }
}
