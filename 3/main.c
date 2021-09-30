#include <stdio.h>

void one() {
    char c1 = '\0';
    char c2 = '\0';
    int c;

    puts("Please enter two characters");
    while ((c = getchar())) {
        if (c == '\n' || c == ' ') {
            continue;
        }
        if (c1 == '\0') {
            c1 = c;
            continue;
        }
        c2 = c;
        break;
    }
    puts("Result of putchar():");
    putchar(c1);
    putchar(c2);
    puts("\nResult of printf():");
    printf("%c%c\n", c1, c2);
    getchar();
}

void two() {
    int score;
    puts("Enter your score:");
    scanf("%d", &score);
    getchar();
    if (score > 100 || score < 0) {
        puts("Invalid score");
        return;
    }
    puts("Your rank:");
    if (score >= 90) puts("A");
    if (score >= 80 && score < 90) puts("B");
    if (score >= 70 && score < 80) puts("C");
    if (score >= 60 && score < 70) puts("D");
    if (score < 60) puts("E");
}

int main() {
    int option, delta;
    setbuf(stdout, NULL);
    puts("Clang Experiment - 3");
    puts("Choose the programme you want to run (1 or 2):");
    scanf("%d", &option);
    getchar();
    switch (option) {
        case 1:
            one();
            break;
        case 2:
            two();
            break;
        default:
            puts("You entered neither 1 nor 2.");
    }
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}
