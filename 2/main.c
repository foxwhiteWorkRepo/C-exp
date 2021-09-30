#include <stdio.h>

void two() {
    char c1='a',c2='b',c3='c',c4='\101',c5='\116';
    printf("a%c b%c\tc%c\tabc\n",c1,c2,c3);
    printf("\t\b%c %c",c4,c5);
}


char shift(char c, int delta){
    delta = delta % 26;
    int shifted_int = (int) c + delta;
    if (shifted_int > 'z') c -= 26;
    if (shifted_int < 'a') c += 26;
    return c + delta;
}

void one(int delta) {
    char c1 = 'c';
    char c2 = 'h';
    char c3 = 'i';
    char c4 = 'n';
    char c5 = 'a';
    printf("Original: %c,%c,%c,%c,%c\n", c1, c2, c3, c4, c5);
    c1 = shift(c1,delta);
    c2 = shift(c2,delta);
    c3 = shift(c3,delta);
    c4 = shift(c4,delta);
    c5 = shift(c5,delta);
    printf("Shifted: %c,%c,%c,%c,%c\n", c1, c2, c3, c4, c5);
}


int main() {
    int option, delta;
    setbuf(stdout, NULL);
    printf("Clang Experiment-2\n");
    printf("Choose the programme you want to run (1 or 2):\n");
    scanf("%d", &option);
    getchar();
    switch (option){
        case 1:
            printf("Type a delta that you want the char to shift:\n");
            scanf("%d", &delta);
            getchar();
            printf("Task one with shift %d:\n",delta);
            one(delta);
            break;
        case 2:
            two();
            break;
        default:
            printf("You entered neither 1 nor 2.\n");
    }
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}
