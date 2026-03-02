#include <stdio.h>

int main(void) {
    unsigned char flags = 0b10100101;
    
    printf("Initial:      0x%02X\n", flags);
    
    flags ^= (1 << 0);
    printf("Toggle bit 0: 0x%02X\n", flags);
    
    flags ^= (1 << 0);
    printf("Toggle bit 0: 0x%02X\n", flags);
    
    flags ^= (1 << 7);
    printf("Toggle bit 7: 0x%02X\n", flags);
    
    flags ^= 0xFF;
    printf("Toggle all:   0x%02X\n", flags);
    
    return 0;
}
