#include <stdio.h>

int main(void) {
    long double ld = 3.14159265358979323846264338327950288L;
    
    printf("=== Long Double ===\n\n");
    
    printf("Sizes:\n");
    printf("  sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("  sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("  sizeof(long double) = %zu bytes\n", sizeof(long double));
    
    printf("\nPrecision comparison (pi):\n");
    float f = 3.14159265358979323846264338327950288f;
    double d = 3.14159265358979323846264338327950288;
    printf("  float:       %.20f\n", (double)f);
    printf("  double:      %.20f\n", d);
    printf("  long double: %.20Lf\n", ld);
    
    printf("\nLong double literal suffix: L\n");
    printf("  3.14L = long double\n");
    
    printf("\nFormat specifier: %%Lf, %%Le, %%Lg\n");
    printf("  Value: %Lf\n", ld);
    printf("  Sci:   %Le\n", ld);
    
    printf("\nNote: long double size varies by platform:\n");
    printf("  - x86 (80-bit extended): 10-16 bytes\n");
    printf("  - Some systems: same as double (8 bytes)\n");
    printf("  - Some systems: 128-bit quad precision\n");
    
    return 0;
}
