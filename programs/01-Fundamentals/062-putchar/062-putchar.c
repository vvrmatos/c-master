#include <stdio.h>

int main(void) {
    putchar('H');
    putchar('e');
    putchar('l');
    putchar('l');
    putchar('o');
    putchar('\n');

    putchar(65);
    putchar(66);
    putchar(67);
    putchar('\n');

    for (char c = 'A'; c <= 'Z'; c++) {
        putchar(c);
    }
    putchar('\n');

    for (int row = 1; row <= 4; row++) {
        for (int col = 0; col < row; col++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}

