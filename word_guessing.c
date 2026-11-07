#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
   char secretword[] = "github";//the word to guess//
   char guessedword[] = "_______";
   char guess;
   int attempts = 5;
   int i, found;
   int wordlength = strlen(secretword);

   printf("**********************\n");
   printf("WORD GUESSING GAME\n");
   printf("***********************");
   printf("Guess the %d-letter secret word.\n", wordlength);
   printf("You have %d wrong guesses allowed.\n\n", attempts);
   //loop until attempts runs out//
   while (attempts > 0){
    printf("word: %s\n, guessword");
    printf("Enter a letter: ");
    scanf(" %c", &guess);
     //converts guess to lwercase if it's in uppercase//
    guess = tolower(guess);
    found = 0;
    //checks if the guessed letter is in the secret word//
    for(i = 0; i < wordlength; i++){
        if(secretword[i] == guess){
            guessedword[i] = guess;
            found = 1;
        }
    }
    if(found){
        printf(" Good job! '%c' is in the word.\n\n, guess");
    }
    else{
        attempts--;
        printf(" wrong! '%c' is not in the word.attempts left: %d\n\n", guess, attempts);
    }
    //checks if the user won//
    if(strcmp(secretword, guessedword) == 0){
        printf("congratulations! you guessed the word: %s\n", secretword);
        break; //exits the loop//
    }
    //if user runs out of attempts//
    if(attempts == 0){
        printf(" Game over! The word was: %s\n", secretword);
        }
        return 0;
   }

}
