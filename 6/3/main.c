#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STUDENT 10
#define SUBJECT 5

int bestStudent(int array[STUDENT][SUBJECT], int *bestSubject, int *bestStudent) {
    int max = 0;
    for (int x = 0; x < STUDENT; x++) {
        for (int y = 0; y < SUBJECT; y++) {
            if (array[x][y] > max) {
                max = array[x][y];
                *bestStudent = x;
                *bestSubject = y;
            }
        }
    }
    return max;
}

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

void printStudent(int array[STUDENT][SUBJECT]) {
    for (int x = 0; x < STUDENT; x++) {
        printf("Student %d:\n", x);
        for (int y = 0; y < SUBJECT; y++) printf("Subject %d: %d, ", y, array[x][y]);
        printf("\b\b\nAverage: %d\n\n", averageStudent(x, array));
    }

    puts("Subject average:");
    for (int y = 0; y < SUBJECT; y++) printf("Subject %d: %d, ", y, averageSubject(y, array));

    puts("\b\b\n\nBest score:");
    int student, subject;
    int max = bestStudent(array, &subject, &student);
    printf("Student %d got a score of %d at Subject %d.", student, max, subject);
}

int main() {
    int array[STUDENT][SUBJECT];
    setbuf(stdout, NULL);
    srand(time(0));
    for (int x = 0; x < STUDENT; x++) {
        for (int y = 0; y < SUBJECT; y++) {
            array[x][y] = rand() % 91 + 10;
        }
    }
    printStudent(array);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}
