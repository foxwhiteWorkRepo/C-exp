#include <stdio.h>
#define MATRIX 3

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transposeMatrix(int matrix[MATRIX][MATRIX]) {
    for (int row = 0; row < MATRIX; row++) {
        for (int column = 0; column < MATRIX; column++) {
            if (column >= row) break;
            swap(&matrix[row][column], &matrix[column][row]);
        }
    }
}

void printMatrix(int matrix[MATRIX][MATRIX]) {
    for (int row = 0; row < MATRIX; row++) {
        for (int column = 0; column < MATRIX; column++) {
            printf("%3d ", matrix[row][column]);
        }
        puts("");
    }
}

int main() {
    setbuf(stdout, NULL);
    int matrix[MATRIX][MATRIX];
    puts("Enter int from left to right, up to down:");
    for (int row = 0; row < MATRIX; row++) for (int column = 0; column < MATRIX; column++) scanf("%d", &matrix[row][column]);
    puts("Original Matrix");
    printMatrix(matrix);
    transposeMatrix(matrix);
    puts("Transpose Matrix");
    printMatrix(matrix);
    printf("\nPress enter to continue...");
    getchar();
    getchar();
    return 0;
}
