#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Task{
    char description[100];
    int isCompleted;
};

int main(){
    struct Task *tasks = NULL;
    int taskCount = 0;
    int choice;

    printf("=== DYNAMIC TO DO LIST ===\n");

    while(1){
        printf("\n 1. Add Task\n");
        printf("2. View Task\n");
        printf("3. Mark Task as completed\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1){
            tasks = (struct Task *)realloc(tasks,(taskCount + 1)* sizeof(struct Task));
            if(tasks == NULL){
                printf("Memory allocation failed!\n");
                return 1;
            }
            printf("Enter task description: ");
            scanf(" %[^\n]", tasks[taskCount].description);
            tasks[taskCount].isCompleted = 0;

            taskCount++;
            printf("Task added!\n");

        }
        else if(choice == 2){
            if(taskCount == 0){
                printf("Your to-do list is empty.\n");
                continue;
            }
            printf("\n-- YOUR TASKS ---\n");
            for (int i = 0; i < taskCount; i++){
                printf("%d. [%c] %s\n", i + 1,
                       tasks[i].isCompleted ? 'X' : ' ',
                       tasks[i].description);

            }
        }
        else if(choice == 3){
            if(taskCount == 0){
                printf("No tasks to complete.\n");
                continue;
            }
            int taskNum;
            printf("Enter the task number to mark as completed: ");
            scanf("%d", &taskNum);

            if(taskNum > 0 && taskNum <= taskCount){
                tasks[taskNum - 1].isCompleted = 1;
                printf("Task marked as completed!\n");
            } else{
                printf("Invalid task number.\n");
                }
        }
        else if(choice == 4){
            printf("Goodbye\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

}
