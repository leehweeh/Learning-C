#include<stdio.h>
#include<stdlib.h>

struct Account{
  char ownerName[50];
  int accountNumber;
  int pin;
  double balance;
  };

  void displayMenu(){
  printf("\n=== BANK ACCOUNT SYSTEM ===\n");
  printf("1. Deposit Money\n");
  printf("2. Withdraw Money\n");
  printf("3. Check Balance\n");
  printf("4. Exit\n");
  printf("==============================\n");
}
int main(){
  struct Account myAccount;
  int choice;
  double amount;
  int enteredPin;
  int loginSuccess = 0;

  printf("Welcome! Let's set up your account.\n");
  printf("Enter your name: ");
  scanf(" %[^\n]", myAccount.ownerName);

  printf("Enter your new account number: ");
  scanf("%d", &myAccount.accountNumber);

  printf("Create a 4-digit PIN: ");
  scanf("%d", &myAccount.pin);
  printf("PIN created successfully!\n");

  myAccount.balance = 0.0;

  printf("\nPlease log in to acess your account.\n");
  while(loginSuccess == 0){
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);
    if(enteredPin == myAccount.pin){
        printf("\n Login successful! Welcome, %s.\n", myAccount.ownerName);
        loginSuccess = 1;
         }
  else{
    printf("Incorrect PIN. please try again.\n");
  }
}

while(1){
    displayMenu();
    printf("Enter your choice(1-4): ");
    scanf("%d", &choice);

if(choice == 1){
    printf("Enter amount to deposit: $");
    scanf("%lf", &amount);
    if(amount > 0){
        myAccount.balance += amount;
        printf("successfully deposited $%.2lf\n", amount);
    } else{
        printf("Invalid amount. Deposit must be greater than 0.\n");
    }
    }
    else if(choice == 2){
        printf("Enter amount to withdraw: $");
        scanf("%lf", &amount);
    if(amount > myAccount.balance){
        printf("Insufficient funds! Your balance is only $%.2lf\n", myAccount.balance);
    } else if(amount <= 0){
        printf("Invalid amount.\n");
    }else{
    printf("security Check: please re-enter your pin to confirm: ");
    scanf("%d", &enteredPin);

    if(enteredPin == myAccount.pin){
        myAccount.balance -= amount;
        printf("Successfully withdrew $%.2lf\n", amount);
    } else{
        printf("Incorrect PIN. Transaction cancelled.\n");
    }

    }
    }
    else if(choice == 3){
        printf("\n--- Account Details ---\n");
        printf("Owner: %s\n", myAccount.ownerName);
        printf("Account #: %d\n", myAccount.accountNumber);
        printf("Current Balance: $%.2lf\n", myAccount.balance);
        printf("----------------------------");
        }
        else if (choice == 4){
            printf("Thank you for banking with us. Goodbye\n");
            break;
            }
            else{
                printf("Invalid choice. please try again.\n");
            }
            }
             return 0;
    }
