#include <stdio.h>
#include <cstdlib>
#include <time.h>

int main()
{
    double time_spent = 0.0;
    int totalTime = 0;
    int nstage = 0;
    int nvid = 0;
    scanf("%d %d", &nstage, &nvid);
    // printf("n(stage) : %d\nn(video) : %d\n", nstage, nvid);
    if (nstage > 100 || nvid > 100 || nstage > nvid)
    {
        return 0;
    }
    int min[nstage];
    for (int i = 0; i < nstage; i++)
    {
        min[i] = 500;
    }
    int pos[nstage];
    for (int i = 0; i < nstage; i++)
    {
        pos[i] = i;
    }
    int table[nvid][2];
    int gaytor = 1;
    for (int i = 0; i < nvid; i++)
    {
        scanf("%d %d",&table[i][0],&table[i][1]);
        if(table[i][0] > nstage || table[i][0] > 500){
            printf("Invalid Input\n");
            return 0;
        }
        // if (gaytor > nstage)
        // {
        //     gaytor = 1;
        // }
        table[i][0] = gaytor;
        table[i][1] = rand() % 501;
        gaytor++;
    }
    clock_t start = clock();
    // printf("------------------------------------\n");
    // printf("Table :");
    // for (int i = 0; i < nvid; i++)
    // {
    //     for (int x = 0; x < 2; x++)
    //     {
    //         printf("\t%d",table[i][x]);
    //     }
    //     printf("\n");
    // }
    // printf("------------------------------------\n");
    if (nstage != nvid)
    {
        // printf("gaytor\n");
        for (int count = 1; count <= nstage; count++)
        {
            for (int i = 0; i < nvid; i++)
            {
                // if(table[i][0] == count){
                // printf("table[%d][0] == %d == True\n",i,caount);
                for (int x = 0; x < nvid; x++)
                {
                    // printf("Finding Min . . . [%d]\n",x);
                    if (table[x][1] < min[count - 1] && table[x][0] == count)
                    {
                        // printf("\ttable[%d][1] < %d && table[%d][0] == %d True\n",x,min[count - 1],x,count);
                        min[count - 1] = table[x][1];
                        // printf("\tmin[%d] = %d -> table[%d][1]\n",count - 1,min[count - 1],x);
                        // printf("\tmin :");
                        // for (int i = 0; i < nstage; i++)
                        // {
                        //     printf(" %d",min[i]);
                        // }
                        // printf("\n");
                        pos[count - 1] = x;
                        // printf("*_=_*pos = %d\n",x);
                    }
                }
                // printf("------------------------------------\n");
                //     break;
                // }
            }
        }
    }
    // printf("min :");
    for (int i = 0; i < nstage; i++)
    {
        totalTime += min[i];
        // printf(" %d",min[i]);
    }
    // printf("\n");
    // printf("pos :");
    for (int i = 0; i < nstage; i++)
    {
        // printf(" %d",pos[i]);
    }
    // printf("\n");
    // printf("------------------------------------\n");
    printf("%d\n", totalTime);
    for (int i = 0; i < nstage; i++)
    {
        printf("%d %d\n", table[pos[i]][0], table[pos[i]][1]);
    }
    clock_t end = clock();
    time_spent += (double)(end - start) / CLOCKS_PER_SEC;
    printf("time used in calculation : %f", time_spent);
    scanf(" %c");
    return 0;
}