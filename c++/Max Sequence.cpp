#include <stdio.h>
#include <stdbool.h>

int main (){
    bool left = false;
    bool right = false;
    short input;
    short sum = 0;
    char max = 0;
    scanf(" %hd",&input);
    char arr[input] = { 0 };
    char pos[input] = { -1 };
    short i;
    short count = 0;
    short lcount = 0;

    for (i = 0; i < input; i++)
    {
        scanf(" %hd",&arr[i]);
        if(arr[i] >= max){
            max = arr[i];
        }
    }
    for(i = 0; i < input; i++){
        if(arr[i] == max){
            pos[count] = i;
            count++;
        }
    }
    sum += max;
    for(i = 0; i < input; i++)
    {
        if(pos[i] == -1){
            break;
        }

        re:
        if(pos[count] != 0 && pos[count] != input && arr[pos[count]] > 0){
            re1:
            if (arr[pos[count - 1]] >= arr[pos[count + 1]] && right == false)
            {
                count--;
                sum += arr[pos[count]];
                left = true;
                lcount = count;
                goto re1;
            }
            else if(arr[pos[count - 1]] < arr[pos[count + 1]] && left == false)
            {
                count++;
                sum += arr[pos[count]];
                right = true;
                lcount = count;
                goto re1;
            }
        }
        else if (pos[count] == 0 && arr[pos[count]] > 0 && (pos[count + 1]) > pos[count])
        {
            count++;
            sum += arr[pos[count]];
            lcount = count;
            goto re;
        }
        else if (pos[count] == (input - 1) && arr[pos[count]] > 0 && pos[(count - 1)] > pos[count])
        {
            count--;
            sum += arr[pos[count]];
            lcount = count;
            goto re;
        }
        else{
            break;
        }
    }

    if(sum > 0){
        if(lcount > count){
            for (i = count; i <= lcount; i++)
            {
                printf("%hd",arr[i]);
            }
            printf("\n");
        }else{
            for(i = lcount; i <= count; i++){
                printf("%hd ",arr[pos[i]]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Empty Sequence . . .\n");
        scanf(" %c");
    }  
    scanf(" %c");
    return 0;
}