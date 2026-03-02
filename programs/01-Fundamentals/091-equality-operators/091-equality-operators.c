// Equality operators == and !=

#include <stdio.h>

int main(void) {
    int a = 5, b = 5, c = 10;
    
    // Equality check
    printf("%d == %d is %d\n", a, b, a == b);
    printf("%d == %d is %d\n", a, c, a == c);
    
    // Inequality check
    printf("%d != %d is %d\n", a, b, a != b);
    printf("%d != %d is %d\n", a, c, a != c);
    
    // With characters
    char ch = 'A';
    printf("'%c' == 'A' is %d\n", ch, ch == 'A');
    printf("'%c' == 'B' is %d\n", ch, ch == 'B');
    
    // With floating point (be careful!)
    double x = 0.1 + 0.2;
    printf("\n0.1 + 0.2 == 0.3 is %d\n", x == 0.3);
    printf("Actual value: %.17f\n", x);
    
    return 0;
}
