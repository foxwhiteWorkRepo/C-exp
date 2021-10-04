
#include <stdio.h>

#define STRING_LENGTH 100

int main() {
    char str[STRING_LENGTH];
    setbuf(stdout, NULL);
    puts("Enter a string:");
    fgets(str, STRING_LENGTH, stdin);
    int letterCount = 0, spaceCount = 0, numberCount = 0, otherCount = 0;
    for (int i = 0; i <= STRING_LENGTH; i++) {
        if (str[i] == 10) break;
        switch (str[i]) {
            case 32:
                spaceCount++;
                break;
            case 48 ... 57:
                numberCount++;
                break;
            case 65 ... 90:
            case 97 ... 122:
                letterCount++;
                break;
            default:
                printf("%d", str[i]);
                otherCount++;
        }
    }
    printf("Letter: %d, Space: %d, Number: %d, Other: %d\n", letterCount, spaceCount, numberCount, otherCount);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}