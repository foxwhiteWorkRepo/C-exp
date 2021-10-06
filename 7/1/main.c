#include <stdio.h>

#define ARRAY_LENGTH 3
#define STRING_LENGTH 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapString(char (*a)[STRING_LENGTH], char (*b)[STRING_LENGTH]) {
    int a_end, b_end = 0;
    for (int i = 0; i < STRING_LENGTH; i++) {
        if (a_end == 1 && b_end == 1) break;
        char temp = (*a)[i];
        (*a)[i] = (*b)[i];
        (*b)[i] = temp;
        if ((*a)[i] == '\0') a_end = 1;
        if ((*b)[i] == '\0') b_end = 1;
    }
}

int getStringLength(const char str[STRING_LENGTH]) {
    int i;
    for (i = 0; i < STRING_LENGTH; i++) {
        if (str[i] == '\0') break;
    }
    return i;
}

void selectionSortInt(int array[ARRAY_LENGTH]) {
    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        int minimum = i;
        for (int j = i + 1; j < ARRAY_LENGTH; j++) {
            if (array[j] < array[minimum]) minimum = j;
        }
        swap(&array[i], &array[minimum]);
    }
}

void selectionSortString(char array[ARRAY_LENGTH][STRING_LENGTH]) {
    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        int minimum = i;
        for (int j = i + 1; j < ARRAY_LENGTH; j++) {
            if (getStringLength(array[j]) < getStringLength(array[minimum])) minimum = j;
        }
        swapString(&array[i], &array[minimum]);
    }
}

void printArrayInt(int array[ARRAY_LENGTH]) {
    printf("[");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d,", array[i]);
    }
    printf("\b]\n");
}

void printArrayString(char array[ARRAY_LENGTH][STRING_LENGTH]) {
    puts("\nString output by string length:");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%s", array[i]);
    }
}

void getString(char array[ARRAY_LENGTH][STRING_LENGTH]){
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        puts("Type a string:");
        fgets(array[i], STRING_LENGTH, stdin);
    }
}

void getInt(int array[ARRAY_LENGTH]){
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        puts("Type a int:");
        scanf("%d", &array[i]);
    }
    getchar();
}

#define selectionSort(array) \
   _Generic((array), int*: selectionSortInt, char(*)[STRING_LENGTH]: selectionSortString)(array)
#define printArray(array) \
   _Generic((array), int*: printArrayInt, char(*)[STRING_LENGTH]: printArrayString)(array)
#define getValue(array) \
   _Generic((array), int*: getInt, char(*)[STRING_LENGTH]: getString)(array)

int main() {
    setbuf(stdout, NULL);
    int array[ARRAY_LENGTH];
//    char array[ARRAY_LENGTH][STRING_LENGTH];
    getValue(array);
    selectionSort(array);
    printArray(array);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}