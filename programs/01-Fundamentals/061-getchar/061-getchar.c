#include <stdio.h>
#include <string.h>

int main(void) {
    char input[] = "Hello";
    int i = 0;
    int ch;

    while ((ch = input[i++]) != '\0') {
        printf("'%c' = %d\n", ch, ch);
    }

    char text[] = "ABC123!@#";
    int letters = 0, digits = 0, other = 0;
    for (i = 0; text[i]; i++) {
        ch = text[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            letters++;
        else if (ch >= '0' && ch <= '9')
            digits++;
        else
            other++;
    }
    printf("Letters: %d, Digits: %d, Other: %d\n", letters, digits, other);

    return 0;
}

