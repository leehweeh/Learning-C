#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact{
  char name[50];
  char phone[20];
};

void addContact();
void viewContact();
void searchContact();
void deleteContact();

int main(){
   int choice;

   while (1){
    printf("\n========================\n");
    printf("CONTACT MANAGEMENT SYSTEM");
    printf("=========================\n");
    printf("1. Add new Contact\n");
    printf("2. View All Contacts\n");
    printf("3. Search for Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("-------------------------");
    printf("Enter your choice(1-5): ");

    if(scanf("%d", &choice)!= 1){
        printf("Invalid input. Please enter a number.\n");
        while(getchar()!= '\n');
        continue;
    }
    if(choice == 1){
        addContact();
    } else if(choice == 2){
        viewContact();
    } else if(choice == 3){
        searchContact();
    } else if(choice == 4){
        deleteContact();
    } else if(choice == 5){
        printf("Goodbye!\n");
        break;
    } else {
        printf("Invalid choice! please choose 1-5.\n");
    }
   }
    return 0;
}

    void addContact(){
       struct Contact c;
       FILE *file = fopen("C:\\users\\user\\Desktop\\c projects\\contacts.txt", "a");

       if(file == NULL){
        printf("Error opening file!\n");
        return;
       }
    getchar();
    printf("\nEnter contact name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", c.phone);

    fprintf(file, "%s, %s\n", c.name, c.phone);
    fclose(file);
    printf("contact added successfully\n");
    }

    void viewContact(){
       char line[100];
       FILE *file = fopen("C:\\users\\user\\Desktop\\c projects\\contacts.txt", "r");

       if(file == NULL){
        printf("\n No contacts found. Add a contact first\n");
        return;
       }
       printf("\n--- All Contacts ---\n");
       while(fgets(line, sizeof(line), file)){
        printf("%s", line);
       }
        printf("----------------------\n");
        fclose(file);
       }
       void searchContact(){
         char searchName[50];
         char line[100];
         char savedName[50];
         char savedPhone[20];
         int  found = 0;

         FILE *file = fopen("C:\\users\\user\\Desktop\\c projects\\contacts.txt", "r");
         if(file == NULL){
            printf("\n No contacts found.\n");
            return;
         }

         getchar();
         printf("\nEnter name to search: ");
         scanf(" %[^\n]", searchName);

         printf("\n--- Search Results ---\n");
         while(fgets(line, sizeof(line), file)){
            sscanf(line, " %[^,], %[^,]", savedName, savedPhone);
            if(strcmp(savedName, searchName) == 0){
                printf("Name: %s\nphone: %s\n", savedName, savedPhone);
                found = 1;
            }
         }
         if(!found){
            printf("contact not found.\n");
         }
         fclose(file);
         }
         void deleteContact(){
            char deleteName[50];
            char line[100];
            char savedName[50];
            char savedPhone[20];
            int  found = 0;

            FILE *file = fopen("C:\\users\\user\\Desktop\\c projects\\contacts.txt", "r");
            FILE *tempFile = fopen("temp.txt", "w");

            if(file == NULL){
                printf("\n No contacts found to delete: ");
                return;
            }
         getchar();
         printf("\n Enter the name to delete: ");
         scanf(" %[^\n]", deleteName);

         while(fgets(line, sizeof(line), file)){
            sscanf(line, "%[^,], %[^\n]", savedName, savedPhone);

            if(strcmp(savedName, deleteName) != 0){
                fprintf(tempFile, "%s", line);
            } else{
                found = 1;
                }
         }
         fclose(file);
         fclose(tempFile);

         remove("contacts.txt");
         rename("temp.txt", "contacts.txt");

         if(found){
            printf("contact '%s' deleted successfully.\n", deleteName);
         } else{
            printf("contact '%s' not found.\n", deleteName);
         }

         }




