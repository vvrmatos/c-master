// Float to integer conversion (truncation)

#include <stdio.h>
#include <math.h>

int main(void) {
    // Basic truncation (toward zero)
    printf("(int)3.7 = %d\n", (int)3.7);
    printf("(int)3.2 = %d\n", (int)3.2);
    printf("(int)-3.7 = %d\n", (int)-3.7);
    printf("(int)-3.2 = %d\n", (int)-3.2);
    
    // Truncation vs rounding
    double val = 2.6;
    printf("\nValue: %.1f\n", val);
    printf("Truncated: %d\n", (int)val);
    printf("Rounded: %d\n", (int)(val + 0.5));  // Simple rounding
    printf("floor(): %.1f\n", floor(val));
    printf("ceil(): %.1f\n", ceil(val));
    printf("round(): %.1f\n", round(val));
    
    // Negative rounding
    double neg = -2.6;
    printf("\nNegative: %.1f\n", neg);
    printf("Truncated: %d\n", (int)neg);
    printf("floor(): %.1f\n", floor(neg));
    printf("round(): %.1f\n", round(neg));
    
    return 0;
}
