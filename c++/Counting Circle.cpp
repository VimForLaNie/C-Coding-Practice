#include <stdio.h>
// check on kill pos on every case

void FindWinner(int list[],int start,int k,int list_size,int normal){ 
    if(list_size > 1){
        int killPos;
        if(k > list_size){
            killPos = k - (normal - list_size);
        }
        else if (k + start > list_size){
            killPos = (k + k - 1) - normal;
        }
        else{
            killPos = k - 1;
        }
        k = list[killPos];
        int temp_list[list_size - 1];
        int pointer = 0;
        for (size_t i = 0; i < list_size; i++)
        {
            if(i != killPos){ 
                temp_list[pointer] = list[i];
                pointer++;
            }
        }
        FindWinner(temp_list,killPos + 1,k,list_size - 1,normal);
    }
    else{
        printf("%i",list[0]);
    }
}
int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    int list[n];
    for (size_t i = 0; i < n; i++)
    {
        list[i] = i + 1;
    }
    FindWinner(list,0,k,n,n);
    return 0;
}