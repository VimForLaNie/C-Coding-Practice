#include <bits/stdc++.h>
using namespace std;
int ans_stu,ans_score;

void ans(){
    cout << ans_stu << " " << ans_score;
}

int main(){
    //input
    int num_ques,num_stu,num_rank,total_score;
    cin >> num_ques >> num_stu;
    pair <int,int> ques[num_ques];
    int lower_bound = 0;
    int upper_bound = 0;
    for (int i = 0; i < num_ques; i++)
    {
        cin >> ques[i].first >> ques[i].second;
        lower_bound += ques[i].first;
        upper_bound += ques[i].second;
    }
    cin >> num_rank;
    pair <int,int> rank[num_rank];
    for (int i = 0; i < num_rank; i++)
    {
        cin >> rank[i].first >> rank[i].second;
    }
    cin >> total_score;
    //solution
    int rem = 0;
    int poss_score = total_score;
    int poss_stu = num_stu;
    if(total_score > upper_bound || total_score < lower_bound){
        ans_stu = -1;
        ans_score = -1;
        ans();
        return 0;
    }
    for (int i = 0; i < num_rank; i++)
    {
        poss_score -= rank[i].second;
        poss_stu--;
    }
    int point = (poss_stu - 1)/2;
    while(ans_score * ans_stu != poss_score){
        if(poss_score % point > 0){
            rem = 1;
        }
        ans_score = (poss_score / point) + rem;
        ans_stu = poss_score / ans_score ;
        point = (point - 1)/2;  
    }
    ans();
}