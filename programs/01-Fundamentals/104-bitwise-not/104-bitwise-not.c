#include <stdio.h>

int main(void) {
    unsigned char a = 0b11001100;
    unsigned char result = ~a;
    
    printf("a  = %u (0x%02X)\n", a, a);
    printf("~a = %u (0x%02X)\n", result, result);
    
    unsigned int b = 0;
    printf("~0 = %u (0x%08X)\n", ~b, ~b);
    
    return 0;
}
