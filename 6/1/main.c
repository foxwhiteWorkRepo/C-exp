#include <stdio.h>

int isPrime(int x){
    for (int i = 2; i <= (x / 2); ++i) if (x % i == 0) return 0;
    return 1;
}

int main() {
    int n;
    setbuf(stdout, NULL);
    puts("Enter a number > 0:");
    scanf("%d", &n);
    getchar();
    if (n == 1) puts("1 is neither prime nor composite.");
    (isPrime(n) == 1) ? puts("Is prime.") : puts("Not prime.");
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}
