#include <stdio.h>

int main(void) {
    int x = 42;
    int negative = -100;
    int zero = 0;
    
    printf("=== Integer Type (int) ===\n\n");
    
    printf("int x = %d\n", x);
    printf("int negative = %d\n", negative);
    printf("int zero = %d\n", zero);
    
    printf("\nSize of int: %zu bytes\n", sizeof(int));
    printf("Size of x: %zu bytes\n", sizeof(x));
    
    int a = 10, b = 3;
    printf("\nInteger arithmetic:\n");
    printf("  %d + %d = %d\n", a, b, a + b);
    printf("  %d - %d = %d\n", a, b, a - b);
    printf("  %d * %d = %d\n", a, b, a * b);
    printf("  %d / %d = %d (truncated)\n", a, b, a / b);
    printf("  %d %% %d = %d (remainder)\n", a, b, a % b);
    
    return 0;
}
