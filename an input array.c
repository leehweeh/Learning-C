#include<stdio.h>
int main()
{

    float marks[5];
    int counter=0;
    for (counter=0;counter<=4;counter++){
        printf("\nkey in a value: ",counter+1);
        scanf("%f", &marks[counter]);

    }
    for(counter=0; counter<=4; counter++){
        printf("\n%.2f",marks[counter]);
    }
    return 0;
}
