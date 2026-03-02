#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define SQUARE(x) ((x) * (x))

int main(void) {
    double radius = 5.0;
    double area = PI * SQUARE(radius);
    double root = sqrt(25.0);

    printf("Area: %.2f\n", area);
    printf("Sqrt: %.2f\n", root);
    return 0;
}
