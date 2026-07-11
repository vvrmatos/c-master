#include <stdio.h>

int main(void) {
    int c;

    printf("char: ");
    fflush(stdout);

    c = getchar();
    if (c == EOF) {
        fprintf(stderr, "EOF\n");
        return 1;
    }

    if (c == '\n')
        printf("1st: '\\n' (%d)\n", c);
    else
        printf("1st: '%c' (%d)\n", c, c);

    /* Enter is still in the stdin buffer from the same line */
    c = getchar();
    if (c == EOF) {
        printf("2nd: EOF\n");
        return 0;
    }
    if (c == '\n')
        printf("2nd: '\\n' (%d)  <- that was Enter\n", c);
    else
        printf("2nd: '%c' (%d)\n", c, c);

    return 0;
}
