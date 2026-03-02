// Addition and subtraction operators

#include <stdio.h>

int main(void) {
    int a = 15, b = 7;
    
    int sum = a + b;
    int diff = a - b;
    
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, diff);
    
    double x = 3.5, y = 1.2;
    printf("%.1f + %.1f = %.1f\n", x, y, x + y);
    printf("%.1f - %.1f = %.1f\n", x, y, x - y);
    
    return 0;
}
