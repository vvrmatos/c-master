// Implicit type conversion (automatic promotion)

#include <stdio.h>

int main(void) {
    int i = 10;
    double d = 3.5;
    
    // int is promoted to double
    double result = i + d;
    printf("int + double: %d + %.1f = %.1f\n", i, d, result);
    
    // char promoted to int
    char c = 'A';
    int sum = c + 1;
    printf("char + int: '%c' + 1 = %d ('%c')\n", c, sum, sum);
    
    // float promoted to double in expressions
    float f = 1.5f;
    double mixed = f + d;
    printf("float + double: %.1f + %.1f = %.1f\n", f, d, mixed);
    
    // int to float (automatic)
    float quotient = i;
    printf("int to float: %d -> %.1f\n", i, quotient);
    
    return 0;
}
