#include <stdio.h>

int main(void) {
    unsigned int a = 16;
    
    printf("a      = %u\n", a);
    printf("a >> 1 = %u\n", a >> 1);
    printf("a >> 2 = %u\n", a >> 2);
    printf("a >> 3 = %u\n", a >> 3);
    printf("a >> 4 = %u\n", a >> 4);
    
    unsigned int b = 100;
    printf("\n%u / 8 = %u (using >> 3)\n", b, b >> 3);
    
    return 0;
}
