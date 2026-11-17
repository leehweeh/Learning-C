#include<stdio.h>
int main()
{
    int year,month,dayofweek,daysinmonth,startday;
    printf("Enter year [>1]: ");
    scanf("%d",&year);
    printf("Enter month [1-12]: ");
    scanf("%d",&month);

    if(month == 2){
        if((year %4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            daysinmonth = 29;
        }else{
            daysinmonth = 28;
        }
    } else if(month==4 || month==6 || month==9 || month==11){
        daysinmonth = 30;
    } else{
        daysinmonth = 31;
    }
    startday = (year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400;
    for(int i=1;i<month;i++){
        if(i==2){
            if((year %4 == 0 && year % 100 != 0) || (year % 400 == 0)){
                startday +=29;
            }else{
                startday +=28;
            }
        } else if(i==4 || i==6 || i==9 || i==11){
            startday +=30;
        } else{
            startday +=31;
        }
     dayofweek = (startday + 1) %7;

    printf("======================\n");
    printf("       %d / %d\n",year,month);
    printf("======================\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    
    for(int i=0;i<dayofweek;i++){
        printf("    ");
    }
    for(int day=1;day<=daysinmonth;day++){
       printf("%4d ",day);
        if((day + dayofweek) %7 ==0){
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
}
