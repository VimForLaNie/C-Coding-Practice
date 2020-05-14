#include <bits/stdc++.h>
using namespace std;

long long n,m,i,key,x,y,cnt,ans;
bool err = false;
long long mod = 1e9 + 7;

int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    char lion[n];
    ans = pow(2,n);
    for(i = 0; i < n; i++){
        lion[i] = '0';
    }
    for(i = 0; i < m; i++){
        scanf("%d",&key);
        scanf("%d",&x);
        scanf("%d",&y);
        x -= 1;
        y -= 1;
        if(err){
            printf("0\n");
            continue;
        } 
        if(key){
            if(lion[x] != '0'){ //has value
                if(lion[y] != '0'){ // has value
                    if(lion[x] == lion[y]){
                        printf("%lld\n",ans % mod);
                        continue;
                    }
                    else{
                        err = true;
                        printf("0\n");
                        continue;
                    }
                }
                else{
                    ans /= 2;
                    lion[y] = lion[x];
                }
            }
            else{ // no value
                if(lion[y] != '0'){ // has value
                    ans /= 2;
                    lion[x] = lion[y];
                }
                else{
                    ans /= 2;
                    lion[y] = 'H';
                    lion[x] = 'H';
                }
            }
        }
        else{
            if(lion[x] != '0'){ //has value
                if(lion[y] != '0'){ // has value
                    if(lion[x] == lion[y]){
                        err = true;
                        printf("0\n");
                    }
                    else{
                        printf("%lld\n",ans % mod);
                        continue;
                    }
                }
                else{
                    if(lion[x] == 'H'){
                        ans /= 2;
                        lion[y] = 'A';
                    }
                    else{
                        lion[y] = 'H';
                        ans /= 2;
                    }
                }
            }
            else{ // no value
                if(lion[y] != '0'){ // has value
                    if(lion[y] == 'H'){
                        ans /= 2;
                        lion[x] = 'A';
                    }
                    else{
                        ans /= 2;
                        lion[x] = 'H';
                    }
                }
                else{
                    ans /= 2;
                    lion[y] = 'A';
                    lion[x] = 'H';
                }
            }
        }
        // int j;
        // for(j = 0; j < n; j++){
        //     printf("%c ",lion[j]);
        // }
        // printf("\n");
        printf("%lld\n",ans % mod);
    }
    
}