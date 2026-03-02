// Integer promotion - char and short to int

#include <stdio.h>

int main(void) {
    char c1 = 100, c2 = 50;
    short s1 = 1000, s2 = 500;
    
    // char + char: both promoted to int first
    printf("char: %d + %d = %d\n", c1, c2, c1 + c2);
    printf("Result type size: %zu bytes\n", sizeof(c1 + c2));
    
    // short + short: promoted to int
    printf("\nshort: %d + %d = %d\n", s1, s2, s1 + s2);
    printf("Result type size: %zu bytes\n", sizeof(s1 + s2));
    
    // Even unary operations promote
    printf("\nUnary +c1 size: %zu bytes\n", sizeof(+c1));
    printf("c1 alone size: %zu bytes\n", sizeof(c1));
    
    // Prevents overflow in intermediate calculations
    char a = 200, b = 200;  // Would overflow char if not promoted
    int sum = a + b;        // Promotes to int, no overflow
    printf("\n200 + 200 = %d (promoted to int)\n", sum);
    
    return 0;
}
