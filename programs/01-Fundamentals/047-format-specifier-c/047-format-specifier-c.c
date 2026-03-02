#include <stdio.h>

int main(void) {
    char letter = 'A';
    char digit = '7';

    printf("%c\n", letter);
    printf("%c\n", digit);
    printf("%c\n", 65);
    printf("%c%c%c\n", 'X', 'Y', 'Z');

    for (char c = 'a'; c <= 'f'; c++) {
        printf("%c ", c);
    }
    printf("\n");

    return 0;
}
