#include <stdio.h>

int main(void) {
    char input[] = "3.14159 2.71828 1.5e-3";
    float f;
    double d;
    float sci;

    sscanf(input, "%f %lf %f", &f, &d, &sci);

    printf("%f\n", f);
    printf("%.10f\n", d);
    printf("%e\n", sci);

    return 0;
}

