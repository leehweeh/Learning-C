#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{

    int length, choice;
    srand(time(NULL));

    printf("==========================\n");
    printf(" RANDOM PASSWORD GENERATOR\n");
    printf("==========================\n");

    printf("Enter the desired password length (e.g, 8, 12, 16): ");
    scanf("%d", &length);

    if(length < 4){
        printf("password length must be at least 4.\n");
        return 1;
    }
    printf("\nChoose password complexity:\n");
    printf("1. Only numbers (e.g, 58392014)\n");
    printf("2. Only letters (e.g, afjkds)\n");
    printf("3. Letters and Numbers (e.g, a8Fj2k)");
    printf("4. High Security (Letters, Numbers, Symbols\n ");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    for(int i=0; i < length; i++){
        int type = choice;

        if(choice == 3){
            type =(rand()% 2) + 1;
        }
        else if (choice == 4){
            type = (rand() % 2) + 1;
        }
        if(type == 1){
            printf("%c", (rand() % 10) + '0');
        }
        else if(type == 2){
            if (rand() % 2 == 0){
                printf("%c", (rand() % 26) + 'A');
            }
            else{
                printf("%c", (rand() % 26) + 'a');
            }
        }
        else if(type == 33){
            char symbols[] = "!@#$%^&*()-_=+";
            printf("%c", symbols[rand() % 17]);
        }
    }
    printf("\n====================\n");
    return 0;
}
