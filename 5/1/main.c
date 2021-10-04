#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ARRAY_LENGTH 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[ARRAY_LENGTH]) {
    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        int minimum = i;
        for (int j = i + 1; j < ARRAY_LENGTH; j++) {
            if (array[j] < array[minimum]) minimum = j;
        }
        swap(&array[i],&array[minimum]);
    }
}

void printArray(int array[ARRAY_LENGTH]){
    printf("[");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d,",array[i]);
    }
    printf("\b]\n");
}

int main() {
    int array[ARRAY_LENGTH];
    setbuf(stdout, NULL);
    srand(time(0));
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = rand() % 50;
    }
    puts("Original array:");
    printArray(array);
    selectionSort(array);
    puts("Sorted array:");
    printArray(array);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}
