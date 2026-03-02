// Unary plus and minus operators

#include <stdio.h>

int main(void) {
    int a = 5;
    int b = -10;
    
    // Unary minus: negates the value
    printf("a = %d, -a = %d\n", a, -a);
    printf("b = %d, -b = %d\n", b, -b);
    
    // Unary plus: mostly identity (rarely used)
    printf("+a = %d\n", +a);
    
    // Double negation
    printf("-(-a) = %d\n", -(-a));
    
    // Useful in expressions
    int x = 3, y = 4;
    int result = -x + y;  // Not subtraction, it's negation then addition
    printf("-x + y = -%d + %d = %d\n", x, y, result);
    
    // Absolute value logic
    int neg = -42;
    int abs_val = (neg < 0) ? -neg : neg;
    printf("|%d| = %d\n", neg, abs_val);
    
    return 0;
}
