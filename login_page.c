#include<stdio.h>
#include<string.h>

#define MAX_ATTEMPTS 3

int main(void){
    const char correct_user[] = "maina_lewis";
    const char correct_pass[] = "admin123";

    char username[50];
    char password[50];
    int attempts = 0;
    int logged_in = 0;

    while(attempts < MAX_ATTEMPTS && !logged_in){
        printf("=====================\n");
        printf("     LOGIN           \n");
        printf("=====================\n");

        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';
        
        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';
        
        // Check credentials
        if(strcmp(username, correct_user) == 0 && strcmp(password, correct_pass) == 0){
            logged_in = 1;
            printf("Login successful!\n");
        } else {
            attempts++;
            printf("Invalid username or password. Please try again.\n");
        }
    }

    if(!logged_in){
        printf("Too many failed attempts. Access denied.\n");
    }

    return 0;
}
    
