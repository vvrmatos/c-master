#include <stdio.h>

int main(void) {
    double pi = 3.141592653589793;
    char str[] = "Hello, World!";

    printf("%.0f\n", pi);
    printf("%.2f\n", pi);
    printf("%.6f\n", pi);
    printf("%10.2f\n", pi);
    printf("%.5s\n", str);
    printf("%.8d\n", 42);
    printf("%.*f\n", 4, pi);

    return 0;
}
