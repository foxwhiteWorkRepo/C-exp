#include <stdio.h>
#define EXTRA 1

int main() {
    int fruit = 1;
    for (int i = 0; i < 9; ++i) {
        fruit += EXTRA;
        fruit *= 2;
    }
    printf("Total number of peach: %d\n",fruit);
    for (int i = 1; i <= 9; ++i) {
        fruit /= 2;
        fruit -= EXTRA;
        printf("Day %d, peach: %d\n",i,fruit);
    }
    return 0;
}
