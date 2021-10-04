#include <stdio.h>
#define swap(x,y) { x = x + y; y = x - y; x = x - y; }

int main() {
    int x = 69, y = 420;
    setbuf(stdout, NULL);
    printf("x = %d, y = %d\n",x,y);
    swap(x,y);
    printf("x = %d, y = %d\n",x,y);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}
