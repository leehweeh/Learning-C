#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
   char name[50];
   float grade;
};

int main(){
    int numStudents;
    struct Student *students;
    float totalGrade = 0.0;

    printf("=== STUDENT GRADE ANALYZER ===\n");
    printf("How many students are in the class?");
    scanf("%d", &numStudents);
    getchar();

    if(numStudents <= 0){
    printf("Invalid number of students.\n");
    return 1;
    }

    students =(struct Student *)malloc(numStudents * sizeof(struct Student));

    if(students == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    for(int i = 0; i < numStudents; i++){
        printf("\nEnter name for student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name);

        printf("Enter grade for %s: ", students[i].name);
        scanf("%f", &students[i].grade);
        getchar();

        totalGrade += students[i].grade;
    }
    float average = totalGrade / numStudents;
    printf("\n==============================");
    printf("Class Average: %.2f\n", average);
    printf("===============================\n");

    for(int i = 0; i < numStudents - 1; i++){
        for(int j = 0; j < numStudents - i - 1; j++){
            if (students[j].grade < students[j + 1].grade){

                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("\n--- Class Ranking(Highest to lowest) ---\n");
    for (int i = 0; i< numStudents; i++){
            printf("%d. %-15s : %.2f\n", i + 1, students[i].name, students[i].grade);
}
free(students);

return 0;
}
