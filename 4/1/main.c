#include <stdio.h>

int main() {
    puts("1! + 2! + 3! + 4! + ... + 20! = ");
    int m;
    double n, s = 0, h = 1;
    n = 20;
    for (m = 1; m <= n; m++) {
        h *= m;
        s += h;
    }
    printf("%.0f", s);
    return 0;
}