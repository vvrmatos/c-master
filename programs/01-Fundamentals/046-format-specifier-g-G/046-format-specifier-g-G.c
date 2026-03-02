#include <stdio.h>

int main(void) {
    double small = 0.000123;
    double medium = 123.456;
    double large = 1234567.0;

    printf("%g\n", small);
    printf("%g\n", medium);
    printf("%g\n", large);
    printf("%G\n", large);
    printf("%.2g\n", 3.14159);

    return 0;
}
