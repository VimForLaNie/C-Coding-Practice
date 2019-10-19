#include <stdio.h>
#include <time.h>

short int md[] = {31,28,31,30,31,30,31,31,30,31,30,31};
double time_spent;

short int checkLeap(short int End){
    short int count = 0;
    for (short int i = 1; i <= End ; i++)
    {
        if(i % 4 == 0 || i % 400 == 0){
            count++;
        }
    }
    return count;
}
long getdate(short int day, short int month, short int year){
	short int dayMonth = 0;
    int dayYear = 0;
    dayYear = (year - 1)* 365;
    for (short int i = 1; i < month; i++)
    {
        dayMonth += md[i - 1];
    }
    long totalDate = day + dayMonth + dayYear + checkLeap(year);
    return totalDate;
}

int main(){
    short int Sd,Sm,Ed,Em;
    short int Sy,Ey;
    // printf("%d",checkLeap(1990,2500));
    printf("==========================================\n");
    printf("Enter The Starting Date (dd/mm/yyyy) : ");
    scanf("%hd/%hd/%hd",&Sd,&Sm,&Sy);
    if(Sd > md[Sm - 1] || Sm > 12){
        printf("Invalid Input . . . \n");
        return 0;
    }
    printf("==========================================\n");
    printf("Enter The Ending Date (dd/mm/yyyy) : ");
    scanf("%hd/%hd/%hd",&Ed,&Em,&Ey);
    if(Ed > md[Em - 1] || Em > 12){
        printf("Invalid Input . . . \n");
        return 0;
    }
    printf("==========================================\n");    
    clock_t start = clock();
    long Start = getdate(Sd,Sm,Sy);
    long End = getdate(Ed,Em,Ey);
    long Duration = End - Start;
    clock_t end = clock();
    time_spent += (double)(end - start) / CLOCKS_PER_SEC;
    printf("Between Starting Date to Ending Date : %d day(s)\n",Duration);
    printf("==========================================\n"); 
    printf("time used in calculation : %f",time_spent);
    scanf(" %c");
    return 0;
}