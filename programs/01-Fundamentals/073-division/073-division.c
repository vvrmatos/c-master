// Division operator - int vs float

#include <stdio.h>

int main(void) {
    // Integer division
    int a = 17, b = 5;
    printf("%d / %d = %d\n", a, b, a / b);
    
    // Floating-point division
    double x = 17.0, y = 5.0;
    printf("%.1f / %.1f = %.1f\n", x, y, x / y);
    
    // Mixed: int and double
    printf("%d / %.1f = %.1f\n", a, y, a / y);
    
    // Force float division from integers
    printf("%d / %d = %.1f (cast)\n", a, b, (double)a / b);
    
    return 0;
}
