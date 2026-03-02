#include <stdio.h>

int main(void) {
    double d1 = 3.14159;
    double d2 = 3.14159265358979;
    double d3 = .5;
    double d4 = 2.;
    double d5 = 0.0;
    
    float f1 = 3.14f;
    float f2 = 3.14F;
    
    long double ld1 = 3.14159265358979323846L;
    
    double sci1 = 1.5e10;
    double sci2 = 1.5E10;
    double sci3 = 6.022e23;
    double sci4 = 1.6e-19;
    double sci5 = 2.99792458e8;
    
    printf("=== Floating-Point Literals ===\n\n");
    
    printf("Basic decimal notation:\n");
    printf("  3.14159   = %.5f\n", d1);
    printf("  3.14159265358979 = %.14f\n", d2);
    printf("  .5        = %f\n", d3);
    printf("  2.        = %f\n", d4);
    printf("  0.0       = %f\n", d5);
    
    printf("\nWith type suffixes:\n");
    printf("  3.14f  (float)       = %f\n", f1);
    printf("  3.14F  (float)       = %f\n", f2);
    printf("  3.14L  (long double) = %Lf\n", ld1);
    printf("  3.14   (double)      = %f (default)\n", 3.14);
    
    printf("\nScientific notation (e or E):\n");
    printf("  1.5e10  = %e = %.0f\n", sci1, sci1);
    printf("  1.5E10  = %E\n", sci2);
    printf("  6.022e23 (Avogadro) = %e\n", sci3);
    printf("  1.6e-19 (electron charge) = %e\n", sci4);
    printf("  2.99792458e8 (speed of light) = %e m/s\n", sci5);
    
    printf("\nSize comparison:\n");
    printf("  sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("  sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("  sizeof(long double) = %zu bytes\n", sizeof(long double));
    
    printf("\nHexadecimal floating-point (C99):\n");
    double hex_float = 0x1.5p10;
    printf("  0x1.5p10 = %f (1.3125 * 2^10)\n", hex_float);
    
    return 0;
}
