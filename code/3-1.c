#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
    char name[10];
    int score;
    struct Student* next;
} Student;

int main() {
    Student* head = NULL;
    char command[20];
    char name[10];
    int score;
  
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            Student* newNode = (Student*)malloc(sizeof(Student));
            strcpy(newNode->name, name);
            newNode->score = score;
            newNode->next = NULL;

            if (head == NULL) { 
                head = newNode;
            } else {
                Student* current = head;
                while (current->next != NULL) { 
                    current = current->next;
                }
                current->next = newNode;
            }
            } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            
            Student* current = head;
            Student* prev = NULL;

            while (current != NULL && strcmp(current->name, name) != 0) {
                prev = current;
                current = current->next;
            }
            if (current != NULL) { 
                if (prev == NULL) { 
                    
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current); 
            }
            
        } else if (strcmp(command, "print") == 0) {
            Student* current = head;
            while (current != NULL) {
                printf("%s %d\n", current->name, current->score);
                current = current->next;
            }
            
        } else if (strcmp(command, "quit") == 0) {
            Student* current = head;
            while (current != NULL) {
                Student* temp = current;
                current = current->next;
                free(temp);
            }
            break; 
        }
    }
}
