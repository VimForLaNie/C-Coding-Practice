#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops{
    int num;
    Workshops* avai = new Workshops[num];
};

Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops* res = new Available_Workshops();
    res->num = n;
    for(int i = 0; i < n; i++){
        Workshops temp;
        temp.duration = duration[i];
        temp.start_time = start_time[i];
        temp.end_time = start_time[i];
        res->avai[i] = temp;
    }
    return res;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int n = ptr->num;
    int a[n] = { 0 };
    Workshops* array = ptr->avai;
    int start_index = array->start_time;
    int end_index = array->end_time;
    for(int i = 0; i < n; i++){
        a[start_index] += 1;
        a[end_index + 1] -= 1;
    }
    int sum = 0;
    int cnt = 0;
    // for(int i = 0; i < n; i++){
    //     sum += a[i];
    //     if(a[i] == 1){
    //         cnt++;
    //     }
    // }
    return cnt;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
