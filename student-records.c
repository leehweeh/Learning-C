#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

void addStudent() {
    struct Student s;
    FILE *file = fopen("students.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    getchar(); // Clears the newline buffer

    printf("\nEnter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter grade: ");
    scanf("%f", &s.grade);

    fprintf(file, "%s, %d, %.2f\n", s.name, s.age, s.grade);
    fclose(file);
    printf("Student '%s' added successfully!\n", s.name);
}

void viewStudents() {
    char line[100];
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("\nNo records found. Add a student first!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("-----------------------\n");
    fclose(file);
}

void deleteStudent() {
    char nameToDelete[50];
    char currentLine[150];
    char studentName[50];
    int age;
    float grade;
    int found = 0;

    FILE *file = fopen("students.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL) {
        printf("\nNo records found to delete.\n");
        return;
    }

    printf("\nEnter the exact name of the student to delete: ");
    scanf(" %[^\n]", nameToDelete);

    while (fgets(currentLine, sizeof(currentLine), file)) {
        sscanf(currentLine, "%[^,], %d, %f", studentName, &age, &grade);

        if (strcmp(studentName, nameToDelete) != 0) {
            fprintf(tempFile, "%s", currentLine);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        printf("Student '%s' deleted successfully!\n", nameToDelete);
    } else {
        printf("Student '%s' not found.\n", nameToDelete);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add New Student\n");
        printf("2. View All Students\n");
        printf("3. Delete a Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addStudent();
        }
        else if (choice == 2) {
            viewStudents();
        }
        else if (choice == 3) {
            deleteStudent();
        }
        else if (choice == 4) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
