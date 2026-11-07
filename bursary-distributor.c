#include<stdio.h>
int main()
{
    char grade;
    int balance;
    printf("Enter grade: ");
    scanf("%c", &grade);
    printf("Enter balance: ");
    scanf("%d", &balance);
    if(grade == 'A' &&  balance < 20000)
    {
        printf("busary given: 100000");
    }
    else if(grade == 'A' &&  balance > 20000)
    {
        printf("busary given: 90000");
    }
    else if(grade == 'B' && balance < 20000)
    {
        printf("busary given: 80000");
    }
    else if(grade == 'B' && balance > 20000)
    {
        printf("busary given is: 70000");
    }
    else if(grade == 'C' && balance < 20000)
    {
        printf("busary given is: 60000");
    }
    else if(grade == 'C' && balance > 20000)
    {
        printf("busary given is: 50000");
    }
    else if(grade == 'D' && balance < 20000)
    {
        printf("busary given is: 40000");
    }
    else if(grade == 'D' && balance > 20000)
    {
        printf("busary given is: 30000");
    }
    else
    {
        printf("Invalid input");
    }
    return 0;
}

