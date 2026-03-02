// Explicit type casting

#include <stdio.h>

int main(void) {
    // Force floating-point division
    int a = 7, b = 2;
    double result = (double)a / b;
    printf("7 / 2 = %d (int), %.1f (cast)\n", a / b, result);
    
    // Truncate double to int
    double pi = 3.14159;
    int truncated = (int)pi;
    printf("%.5f truncated = %d\n", pi, truncated);
    
    // Cast for printf format
    long big = 1234567890L;
    printf("As int: %d\n", (int)big);
    
    // Cast in expressions
    int x = 5, y = 3;
    printf("Average: %.2f\n", (double)(x + y) / 2);
    
    // Multiple casts
    char c = (char)(int)3.7;
    printf("double -> int -> char: %d\n", c);
    
    return 0;
}
