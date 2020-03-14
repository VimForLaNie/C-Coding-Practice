#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int i,m,n;
char n_in[10000];
char input[10000];
string temp_name;
int temp_id,temp_day,temp_month,temp_year;
float temp_grade;
bool temp_sex;



struct student{
    int id,day,month,year;
    bool sex;//t => male f => female
    string name;
    float grade;
};

list<student> data;

int main(){
    fgets(n_in,10000,stdin); //use fgets() to avoid
    sscanf(n_in,"%d",&n);//leaving '\n' in stdin
    //for(i = 0; i < n; i++){
        fgets(input,10000,stdin);
    //}
    cout << temp_name << " " << temp_id << " " << temp_sex << " " << temp_day << "/" << temp_month << "/" << temp_year << " " << temp_grade << endl;
}
