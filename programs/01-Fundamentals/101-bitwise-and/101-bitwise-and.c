#include <stdio.h>

int main(void) {
    unsigned int a = 0b11001100;
    unsigned int b = 0b10101010;
    unsigned int result = a & b;
    
    printf("a      = %u (0x%02X)\n", a, a);
    printf("b      = %u (0x%02X)\n", b, b);
    printf("a & b  = %u (0x%02X)\n", result, result);
    
    return 0;
}
