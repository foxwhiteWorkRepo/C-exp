#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STUDENT 5
#define SUBJECT 3

typedef struct{
    int id;
    char name[20];
    int score[SUBJECT];
} Student;

void input(Student array[STUDENT]) {
    for (int i = 0; i < STUDENT; i++) {
        printf("Enter the name of student %d :\n", i);
        fgets(array[i].name, 20, stdin);
        for (int j = 0; j < 20; j++) if (array[i].name[j] == '\n') array[i].name[j] = '\0';
        for (int j = 0; j < SUBJECT; j++) {
            printf("Enter score of subject %d for student %d :\n", j, i);
            scanf("%d", &array[i].score[j]);
        }
        getchar();
        array[i].id = i;
    }
}

int totalAverage(Student array[STUDENT]) {
    int total = 0;
    for (int i = 0; i < SUBJECT; i++) {
        for (int j = 0; j < STUDENT; j++) {
            total += array[j].score[i];
        }
    }
    return (total/SUBJECT/STUDENT);
}

int average(Student *array) {
    int total = 0;
    for (int i = 0; i < SUBJECT; i++) {
        total += (*array).score[i];
    }
    return (total/SUBJECT);
}

int max(Student array[STUDENT]) {
    int max = 0;
    for (int i = 0; i < STUDENT; i++) {
        if (average(&array[i]) > average(&array[max])) max = i;
    }
    return max;
}

void printStudent(int student_idx, Student array[STUDENT]) {
    printf("Student %s, id %d:\n", array[student_idx].name, array[student_idx].id);
    for (int j = 0; j < SUBJECT; j++) {
        printf("Subject %d: %d, ", j, array[student_idx].score[j]);
    }
    printf("Average :%d", average(&array[student_idx]));
    puts("\n");
}

int main() {
    setbuf(stdout, NULL);
    srand(time(0));
    Student array[STUDENT];
    input(array);
    for (int i = 0; i < STUDENT; i++) {
        printStudent(i, array);
    }
    puts("Best student:");
    printStudent(max(array), array);
    puts("Total average:");
    printf("%d", totalAverage(array));
    return 0;
}
