#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentNode {
    int number;                    
    char name[50];                
    float total_marks;             
    struct StudentNode* next;     
} StudentNode;

void insertStudent(StudentNode** head, int number, const char* name, float total_marks) {
     StudentNode* newNode = (StudentNode*)malloc(sizeof(StudentNode));
    newNode->number = number;
    strcpy(newNode->name, name);
    newNode->total_marks = total_marks;
    newNode->next = *head; 
    *head = newNode; 
}

void deleteStudent(StudentNode** head, int number) {
    StudentNode* current = *head;
    StudentNode* previous = NULL;
    while (current != NULL && current->number != number) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Student with number %d not found.\n", number);
        return; 
    }

    else {
        previous->next = current->next;
    }
    free(current);
    printf("Student with number %d deleted.\n", number);
}

StudentNode* searchStudent(StudentNode* head, const char* name, int number) {
    StudentNode* current = head;
    while (current != NULL) {
        if ((name != NULL && strcmp(current->name, name) == 0) || (number != -1 && current->number == number)) {
            return current; 
        }
        current = current->next;
    }
    return NULL; 
}

void sortStudents(StudentNode** head) {
    if (*head == NULL) {
        return; 
    }

    StudentNode *i, *j;
    int tempNumber;
    char tempName[50];
    float tempMarks;

    for (i = *head; i != NULL; i = i->next) {
        for (j = *head; j->next != NULL; j = j->next) {
            if (j->number > j->next->number) {

                tempNumber = j->number;
                j->number = j->next->number;
                j->next->number = tempNumber;

                strcpy(tempName, j->name);
                strcpy(j->name, j->next->name);
                strcpy(j->next->name, tempName);

                tempMarks = j->total_marks;
                j->total_marks = j->next->total_marks;
                j->next->total_marks = tempMarks;
            }
        }
    }
}

void displayStudents(StudentNode* head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    printf("Student List:\n");
    printf("Number\tName\t\tTotal Marks\n");
    printf("-------------------------------------\n");
    StudentNode* current = head;
    while (current != NULL) {
        printf("%d\t%s\t\t%.2f\n", current->number, current->name, current->total_marks);
        current = current->next;
    }
}

int main() {
    StudentNode* head = NULL; 
    int choice, number;
    char name[50];
    float total_marks;

    do {
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Sort Students\n");
        printf("5. Display Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student number, name, and total marks: ");
                scanf("%d %s %f", &number, name, &total_marks);
                insertStudent(&head, number, name, total_marks);
                break;
            case 2:
                printf("Enter student number to delete: ");
                scanf("%d", &number);
                deleteStudent(&head, number);
                break;
            case 3:
                printf("Enter student number to search (or -1 for name search): ");
                scanf("%d", &number);
                if (number == -1) {
                    printf("Enter name to search: ");
                    scanf("%s", name);
                } else {
                    name[0] = '\0'; 
                }

                StudentNode* foundStudent = searchStudent(head, name[0] ? name : NULL, number);
                if (foundStudent != NULL) {
                    printf("Student found: %d %s %.2f\n", foundStudent->number, foundStudent->name, foundStudent->total_marks);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 4:
                sortStudents(&head);
                printf("Students sorted by number.\n");
                break;
            case 5:
                displayStudents(head);
                break;
        }
    } while (choice != 0);

    return 0;
}
