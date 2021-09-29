#include <stdio.h>

void two() {
    int a, b, c;
    printf("Input 3 int, format as int,int,int \n");
    scanf("%d,%d,%d", &a, &b, &c);
    int max = ((a > b) && (a > c)) ? a : b > c ? b : c;
    printf("Max value: %d\n", max);
}

int main() {
    int option;
    setbuf(stdout, NULL);
    printf("Clang Experiment-1\n");
    printf("Choose the programme you want to run (1 or 2):\n");
    scanf("%d", &option);
    switch (option){
        case 1:
            printf("******************************\n         Very good!\n******************************\n");
            break;
        case 2:
            two();
            break;
        default:
            printf("You entered neither 1 nor 2.\n");
    }
    getchar();
    printf("Press enter to continue...");
    getchar();
    return 0;
}