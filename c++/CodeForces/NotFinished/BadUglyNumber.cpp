#include <bits/stdc++.h>
using namespace std;
int i,t,num;

bool checkDivisibility(int n, int digit) 
{ 
    return (digit != 0 && n % digit == 0); 
} 

bool allDigitsDivide(int n) 
{ 
    int temp = n; 
    while (temp > 0) { 

        int digit = n % 10; 
        if (!(checkDivisibility(n, digit))) 
            return false; 
  
        temp /= 10; 
    } 
    return true; 
} 

int main(){
    cin >> t;
    for(i = 0; i < t;i++){
        cin >> num;
        
    } 
}