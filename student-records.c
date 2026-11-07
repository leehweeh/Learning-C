#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
char name[50];
int age;
float grade;
};

void addstudent(){
    struct student s;
    FILE *file = fopen("students.txt", "a");

    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }
    getchar();
    printf("\nEnter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter age");
    scanf("%d", &s.age);
    printf("Enter grade: ");
    scanf("%f", &s.grade);

    fprintf(file, "%s, %d, %.2f\n", s.name, s.age, s.grade);
    fclose(file);

    printf("student '%s' added successfuly!\n", s.name);
}

void viewstudents(){
char line[100];
FILE *file =fopen("students.txt", "r");

if(file == NULL){
    printf("\n NO records found. Add a student first!\n");
    return;
}
printf("\n--- student records ---\n");

while(fgets(line, sizeof(line), file)){
    printf("%s", line);
}
printf("------------\n");
fclose(file);
}
int main(){
int choice;

while(1){
    printf("\n=== STUDENT RECORD SYSTEM ===\n");
    printf("1. Add new student\n");
    printf("2. view All students\n");
    printf("3. Exit choice: ");
    scanf("%d", &choice);

    if (choice == 1){
        addstudent();
    }
    else if(choice == 2){
        viewstudents();
    }
    else if(choice == 3){
        printf("Exiting program. Goodbye!\n");
        break;
    }
    else{
        printf("Invalid choice. please enter 1, 2, or 3.\n");
    }
}
return 0;
}
