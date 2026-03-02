#include <stdio.h>
#include <math.h>

int main(void) {
    float f = 3.14159f;
    double d = 3.141592653589793;
    long double ld = 3.14159265358979323846L;

    printf("%f\n", f);
    printf("%f\n", d);
    printf("%Lf\n", ld);
    printf("%.2f\n", d);
    printf("%F\n", INFINITY);
    printf("%f\n", NAN);

    return 0;
}
