#include <bits/stdc++.h>

int main(){
    int nCharacter;
    scanf("%d",&nCharacter);
    int Str[nCharacter];
    int Int[nCharacter];
    int Exp[nCharacter];
    for (int i = 0; i < nCharacter; i++)
    {
        scanf("%d %d %d",&Str[i],&Int[i],&Exp[i]);
    }
    for (int i = 0; i < nCharacter; i++)
    {
        int curr_str = Str[i];
        int curr_int = Int[i];
        int curr_exp = Exp[i];

        int l = 0;
        int r = curr_exp;
        int ans = 0;
        int m;

        while(l <= r)
        {
            m = ((l + r) / 2);
            if(curr_exp == 0){
                if(curr_str > curr_int){
                    ans = 1;
                    break;
                }
                else if(curr_int >= curr_str){
                    ans = 0;
                    break;
                }
            }
            if(curr_exp == 1){
                if(curr_exp + curr_int > curr_str){
                    ans = 0;
                }
                else if (curr_exp + curr_str > curr_int)
                {
                    ans = 1;
                }
                if(curr_str > curr_int){
                    ans++;
                    break;
                }
                break;
            }

            if(m + curr_str > (curr_exp - m) + curr_int){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
            ans = curr_exp - m;
        }
        printf("%d\n",ans);
    }
}
