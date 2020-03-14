#include <bits/stdc++.h>
using namespace std;
int n,s,d;
int i;
string num;
bool err = false;

int read(string number,int base){
    int ans = 0;
    int str_size = number.length();
    int val = 0;
    for(i = 0; i < str_size; i++){
        switch (number[i])
        {
        case '1':
            val = 1;
            break;
        case '2':
            val = 2;
            break;
        case '3':
            val = 3;
            break;
        case '4':
            val = 4;
            break;
        case '5':
            val = 5;
            break;
        case '6':
            val = 6;
            break;
        case '7':
            val = 7;
            break;
        case '8':
            val = 8;
            break;
        case '9':
            val = 9;
            break;
        case '0':
            val = 0;
            break;
        case 'a':
        case 'A':
            val = 10;
            break;
        case 'b':
        case 'B':
            val = 11;
            break;
        case 'c':
        case 'C':
            val = 12;
            break;
        case 'd':
        case 'D':
            val = 13;
            break;
        case 'e':
        case 'E':
            val = 14;
            break;
        case 'f':
        case 'F':
            val = 15;
            break;
        default:
            cout << "ERROR" << endl;
            err = true;
            return 0;
            break;
        }
        if(val >= base){
            cout << "ERROR" << endl;
            err = true;
            return 0;
        }
        ans += val * pow(base,(str_size - i) - 1);
    }
    return ans;
}

string toBase(int number,int base){
    char ans_arr[100] = { 0 };
    i = 0;
    while(number >= base){
        if(number % base < 10){
            ans_arr[i] = (number % base) + '0';
              //convert 0 to '0' .... 
        }
        else
        {
            switch (number % base)
            {
            case 10:
                ans_arr[i] = 'a';
                break;
            case 11:
                ans_arr[i] = 'b';
                break;
            case 12:
                ans_arr[i] = 'c';   
                break;
            case 13:
                ans_arr[i] = 'd';
                break;
            case 14:
                ans_arr[i] = 'e';
                break;
            case 15:
                ans_arr[i] = 'f';
                break;
            default:
                break;
            }
        }
        number /= base;
        i++;
    }
    if(number < 10){
        ans_arr[i] = number + '0';
    }
    else{
    switch (number){
        case 10:
            ans_arr[i] = 'a';
            break;
        case 11:
            ans_arr[i] = 'b';
            break;
        case 12:
            ans_arr[i] = 'c';   
            break;
        case 13:
            ans_arr[i] = 'd';
            break;
        case 14:
            ans_arr[i] = 'e';
            break;
        case 15:
            ans_arr[i] = 'f';
            break;
        default:
            break;
    }
    }
    reverse(ans_arr,ans_arr + i + 1);
    return ans_arr;
}

int main(){
    err = false;
    num,s,d = 0;
    cin >> num >> s >> d;
    if(!n && !s && !d){
        cout << "BYE" << endl; 
        return 0;
    }
    // cout << num << s << d << endl;
    n = read(num,s);
    if((s > 16 || s < 2 || n < 0 || d > 16 || d < 2) && !err){
        cout << "ERROR" << endl;
        main();
    }
    if(d == 10 && !err){
        cout << n << endl;
    }
    else if (d > 10 || d < 10 && !err){
        cout << toBase(n,d) << endl;
    }
    main();    
}