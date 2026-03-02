// Operator precedence (PEMDAS-like)

#include <stdio.h>

int main(void) {
    // Multiplication before addition
    printf("2 + 3 * 4 = %d\n", 2 + 3 * 4);        // 14, not 20
    printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);    // 20
    
    // Division and multiplication: left to right
    printf("20 / 4 * 2 = %d\n", 20 / 4 * 2);      // 10
    printf("20 / (4 * 2) = %d\n", 20 / (4 * 2));  // 2
    
    // Modulus same precedence as * and /
    printf("10 + 15 %% 4 = %d\n", 10 + 15 % 4);   // 13
    
    // Unary minus highest
    printf("-3 * 4 = %d\n", -3 * 4);              // -12
    
    // Complex expression
    int result = 2 + 3 * 4 - 10 / 2;
    printf("2 + 3 * 4 - 10 / 2 = %d\n", result);  // 2 + 12 - 5 = 9
    
    // When in doubt, use parentheses!
    printf("((2 + 3) * (4 - 1)) / 3 = %d\n", ((2 + 3) * (4 - 1)) / 3);
    
    return 0;
}
