#include <stdio.h>

int main(void) {
    char input[] = "42 -17 255 0x1A 0755";
    int d, neg;
    unsigned int u;
    int hex, octal;

    sscanf(input, "%d %d %u %i %i", &d, &neg, &u, &hex, &octal);

    printf("%d\n", d);
    printf("%d\n", neg);
    printf("%u\n", u);
    printf("%d\n", hex);
    printf("%d\n", octal);

    return 0;
}

