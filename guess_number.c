#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main()
{
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("Guess my number game!\n");

    do
    {
        printf("Enter a number between 1 and 100: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num)
        {
            printf("Too high! Try again.\n");
        }
        else if (guess < num)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed my number in %d tries.\n", tries);
        }
      }  while (guess != num);
    }
    

        /* code */
     
    
    
