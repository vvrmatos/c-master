#include <stdio.h>

int main(void) {
    double d = 12345.6789;
    double tiny = 0.00000123;
    double huge = 6.022e23;

    printf("%e\n", d);
    printf("%E\n", d);
    printf("%.2e\n", d);
    printf("%e\n", tiny);
    printf("%.4e\n", huge);

    return 0;
}
