#include <stdio.h>

#define STRING_LENGTH 100

void count(int result[4], char str[STRING_LENGTH]) {
    for (int i = 0; i <= STRING_LENGTH; i++) {
        if (str[i] == 10) break;
        switch (str[i]) {
            case 32:
                result[1]++;
                break;
            case 48 ... 57:
                result[2]++;
                break;
            case 65 ... 90:
            case 97 ... 122:
                result[0]++;
                break;
            default:
                printf("%d", str[i]);
                result[3]++;
        }
    }
}

int main() {
    char str[STRING_LENGTH];
    setbuf(stdout, NULL);
    puts("Enter a string:");
    fgets(str, STRING_LENGTH, stdin);
    int result[4] = {0};
    // letterCount = 0, spaceCount = 0, numberCount = 0, otherCount = 0;
    count(result, str);
    printf("Letter: %d, Space: %d, Number: %d, Other: %d\n", result[0], result[1], result[2], result[3]);
    printf("\nPress enter to continue...");
    getchar();
    return 0;
}
