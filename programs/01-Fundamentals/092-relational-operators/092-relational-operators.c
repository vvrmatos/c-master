// Relational operators < > <= >=

#include <stdio.h>

int main(void) {
    int a = 5, b = 10;
    
    // Less than
    printf("%d < %d is %d\n", a, b, a < b);
    printf("%d < %d is %d\n", b, a, b < a);
    
    // Greater than
    printf("%d > %d is %d\n", a, b, a > b);
    printf("%d > %d is %d\n", b, a, b > a);
    
    // Less than or equal
    printf("%d <= %d is %d\n", a, b, a <= b);
    printf("%d <= %d is %d\n", a, a, a <= a);
    
    // Greater than or equal
    printf("%d >= %d is %d\n", a, b, a >= b);
    printf("%d >= %d is %d\n", a, a, a >= a);
    
    // Chaining doesn't work as expected!
    int x = 5;
    printf("\n1 < 5 < 10? (1 < %d < 10)\n", x);
    printf("Mathematical: true\n");
    printf("C expression: %d (wrong!)\n", 1 < x < 10);
    printf("Correct in C: %d\n", 1 < x && x < 10);
    
    return 0;
}
