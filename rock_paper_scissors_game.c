#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
 int playerchoice;
 int computerChoice;
 int playerscore = 0;
 int computerscore = 0;

 srand(time(NULL));

 printf("===========================\n");
 printf("   ROCK,  PAPER,   SCISSORS\n");
 printf("===========================\n");
 printf("Rules:\n");
 printf("1 = Rock\n");
 printf("2 = paper\n");
 printf("3 = scissors\n");

 while (1){
    printf("\nplayer: %d | computer: %d\n", playerscore, computerscore);
    printf("Enter your choice(1-3), or 0 to quit: ");

    if(scanf("%d", &playerchoice) !=1){
        printf("Invalid input. please enter a number.\n");
        while(getchar() != '\n');
        continue;
    }

    if(playerchoice == 0){
        printf("Thanks for playing!\n");
        break;
    }

    if(playerchoice == 0){
        printf("Thanks for playing!\n");
        break;
        }
    if (playerchoice < 1 || playerchoice > 3){
        printf("please choose 1, 2, or 3.\n");
        continue;
    }
    computerChoice = (rand() % 3) + 1;

    printf("you choose: ");
    if(playerchoice == 1)printf("Rock\n");
    else if(playerchoice == 2)printf("Paper\n");
    else printf("scissor\n");

    printf("computer choose: ");
    if (computerChoice == 1) printf("Rock\n");
    else if (computerChoice == 2) printf("paper\n");
    else printf("scissors\n");

    if(playerchoice == computerChoice){
        printf("It's a tie!\n");
    }
    else if((playerchoice == 1 && computerChoice == 3) ||
        (playerchoice == 2 && computerChoice == 1)||
    (playerchoice == 3 && computerChoice == 2)){
        printf("You won this round!\n");
        playerscore++;
    }
    else{
        printf("Computer wins this round!\n");
        computerscore++;
    }
    return 0;


    }


}
