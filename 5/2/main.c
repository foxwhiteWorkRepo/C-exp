#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_LENGTH 15

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
        swap(&array[i], &array[minimum]);
    }
}

void printArray(int array[ARRAY_LENGTH]) {
    printf("[");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d,", array[i]);
    }
    printf("\b]\n");
}

int binarySearch(int array[], int start, int finish, int x) { // Find x in array from start to finish
    if (finish >= start) {
        int mid = start + (finish - start) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] > x)
            return binarySearch(array, start, mid - 1, x);
        return binarySearch(array, mid + 1, finish, x);
    }
    return -1;
}

int main() {
    int array[ARRAY_LENGTH];
    int input;
    setbuf(stdout, NULL);
    srand(time(0));
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = rand();
    }
    puts("Original Array:");
    selectionSort(array);
    printArray(array);
    puts("Type in a value to search:");
    scanf("%d", &input);
    getchar();
    int result = binarySearch(array, 0, ARRAY_LENGTH - 1, input);
    (result == -1) ? printf("%d is not in array.", input) : printf("%d is at index %d", input, result);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}