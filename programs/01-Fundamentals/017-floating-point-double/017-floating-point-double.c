#include <stdio.h>

int main(void) {
    double d = 3.141592653589793;
    double large = 1.7976931348623157e308;
    double small = 2.2250738585072014e-308;
    
    printf("=== Floating Point (double) ===\n\n");
    
    printf("double d = %.15f\n", d);
    printf("double d = %f (default 6 decimals)\n", d);
    printf("double d = %e\n", d);
    
    printf("\nSize comparison:\n");
    printf("  sizeof(float)  = %zu bytes\n", sizeof(float));
    printf("  sizeof(double) = %zu bytes\n", sizeof(double));
    
    printf("\nPrecision comparison (pi):\n");
    float  f_pi = 3.141592653589793f;
    double d_pi = 3.141592653589793;
    printf("  float:  %.15f\n", f_pi);
    printf("  double: %.15f\n", d_pi);
    printf("  actual: 3.141592653589793...\n");
    
    printf("\nDouble is the DEFAULT for literals:\n");
    printf("  3.14   -> double\n");
    printf("  3.14f  -> float\n");
    printf("  3.14L  -> long double\n");
    
    printf("\nRange:\n");
    printf("  Max: %e\n", large);
    printf("  Min positive: %e\n", small);
    
    return 0;
}
