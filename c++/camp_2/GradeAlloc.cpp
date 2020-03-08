#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int my_score[t];
    for (int i = 0; i < t; i++)
    {
        int num_stu,max_score;
        cin >> num_stu >> max_score;
        int stu_score[num_stu];
        int sum = 0;
        int avg = 0;
        for (int x = 0; x < num_stu; x++)
        {
            cin >> stu_score[x];
            sum += stu_score[x];
        }
        int index = 1;
        my_score[i] = stu_score[0];
        while(my_score[i] < max_score){
            if(index == num_stu){
                break;
            }
            if(my_score[i] + stu_score[index] <= max_score){
                my_score[i] += stu_score[index];
                stu_score[index] = 0;
                index++;
            }
            else{
                my_score[i] = max_score;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout << my_score[i] << endl;
    }
}