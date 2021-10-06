#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STUDENT 4
#define SUBJECT 5

int averageSubject(int subject_idx, int array[STUDENT][SUBJECT]) {
    int total = 0;
    for (int i = 0; i < STUDENT; i++) total += array[i][subject_idx];
    return (total / STUDENT);
}

int averageStudent(int student_idx, int array[STUDENT][SUBJECT]) {
    int total = 0;
    for (int i = 0; i < SUBJECT; i++) total += array[student_idx][i];
    return (total / SUBJECT);
}

void printStudent(int array[STUDENT][SUBJECT], int student_idx) {
    printf("Student %d:\n", student_idx);
    for (int y = 0; y < SUBJECT; y++) printf("Subject %d: %d, ", y, array[student_idx][y]);
    printf("\b\b\nAverage: %d\n\n", averageStudent(student_idx, array));
}

void failedStudent(int array[STUDENT][SUBJECT]) {
    for (int x = 0; x < STUDENT; x++) {
        int failed = 0;
        for (int y = 0; y < SUBJECT; y++) {
            if (array[x][y] < 60) failed++;
            if (failed == 2) {
                printStudent(array, x);
                break;
            }
        }
    }
}

void goodStudent(int array[STUDENT][SUBJECT]) {
    for (int x = 0; x < STUDENT; x++) {
        if (averageStudent(x, array) > 90) printStudent(array, x);
        int total = 0;
        for (int y = 0; y < SUBJECT; y++) {
            if (array[x][y] > 85) total++;
            if (total == SUBJECT) printStudent(array, x);
        }
    }
}

int main() {
    int array[STUDENT][SUBJECT];
    setbuf(stdout, NULL);
    srand(time(0));
    for (int x = 0; x < STUDENT; x++) {
        for (int y = 0; y < SUBJECT; y++) {
            array[x][y] = rand() % 51 + 50;
        }
    }
    puts("1. Average of Subject 0:");
    printf("%d\n", averageSubject(0, array));
    puts("2. Failed Student:");
    failedStudent(array);
    puts("3. Good Student:");
    goodStudent(array);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}