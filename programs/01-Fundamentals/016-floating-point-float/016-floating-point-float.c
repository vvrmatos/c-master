#include <stdio.h>

int main(void) {
    float f = 3.14159f;
    float scientific = 6.022e23f;
    float small = 1.6e-19f;
    
    printf("=== Floating Point (float) ===\n\n");
    
    printf("float f = %f\n", f);
    printf("float f = %.2f (2 decimal places)\n", f);
    printf("float f = %e (scientific notation)\n", f);
    
    printf("\nScientific notation:\n");
    printf("  %e (Avogadro's number)\n", scientific);
    printf("  %e (electron charge)\n", small);
    
    printf("\nSize of float: %zu bytes\n", sizeof(float));
    
    printf("\nFloat precision issues:\n");
    float a = 0.1f;
    float b = 0.2f;
    float sum = a + b;
    printf("  0.1 + 0.2 = %.20f\n", sum);
    printf("  (Not exactly 0.3!)\n");
    
    printf("\nFloat literal suffix: f or F\n");
    printf("  3.14f  = float\n");
    printf("  3.14   = double (default)\n");
    
    return 0;
}
