#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct student {
    int id;
    char name[20];
    char gender;
    int age;
    struct student *next;
} student_t;

void printStudent(student_t *node) {
    printf("Student No. %d:\nName: %s\nAge: %d\nGender: %c\n\n", node->id, node->name, node->age, node->gender);
}

void printLinkedList(student_t *head) {
    student_t *temp = head;
    while (temp != NULL) {
        printStudent(temp);
        temp = temp->next;
    }
    puts("");
}

student_t *createNewStudent(int id, int age) {
    student_t *result = malloc(sizeof(student_t));
    result->id = id;
    result->age = age;
    strcpy(result->name, "Bob");
    result->gender = (rand() % 2 == 0) ? 'M' : 'F';
    result->next = NULL;
    return result;
}

student_t *createHead(int id, int age) {
    student_t *temp;
    temp = createNewStudent(id, age);
    return temp;
}

void insertAtHead(student_t **head, student_t *node_to_add) {
    node_to_add->next = *head;
    *head = node_to_add;
}

void removeElement(student_t *head, student_t *node_to_remove) {
    student_t *temp = head;
    while (temp != NULL) {
        if (temp->next == node_to_remove) {
            temp->next = node_to_remove->next;
            return;
        }
        temp = temp->next;
    }
}

student_t *findElementByAge(student_t *head, int age) {
    student_t *temp = head;
    while (temp != NULL) {
        if (temp->age == age) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void removeElementByAge(student_t *head, int age) {
    student_t *temp = findElementByAge(head, age);
    if (temp != NULL) {
        removeElement(head, temp);
        removeElementByAge(head, age);
    }
}

void insertNodeAfter(student_t *front, student_t *node_to_add) {
    node_to_add->next = front->next;
    front->next = node_to_add;
}

int main() {
    student_t *head, *temp;
    setbuf(stdout, NULL);
    srand(time(0));

    head = createHead(2021153000, (rand() % 3) + 18);

    for (int i = 1; i < 20; i++) {
        temp = createNewStudent(2021153000 + i, (rand() % 5) + 18);
        insertAtHead(&head, temp);
    }

    int option;
    puts("Enter a age to remove:");
    scanf("%d", &option);
    removeElementByAge(head, option);
    puts("Student list:");
    printLinkedList(head);
    printf("\nPress enter to continue...");
    getchar();
    getchar();
    return 0;
}
