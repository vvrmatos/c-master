#include <stdio.h>

int main(void) {
    unsigned int a = 0b11001100;
    unsigned int b = 0b10101010;
    unsigned int result = a ^ b;
    
    printf("a      = %u (0x%02X)\n", a, a);
    printf("b      = %u (0x%02X)\n", b, b);
    printf("a ^ b  = %u (0x%02X)\n", result, result);
    
    int x = 5, y = 10;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("Swapped: x=%d, y=%d\n", x, y);
    
    return 0;
}
