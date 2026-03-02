#include <stdio.h>

int main(void) {
    unsigned char flags = 0b00000000;
    
    printf("Initial: 0x%02X\n", flags);
    
    flags |= (1 << 0);
    printf("Set bit 0: 0x%02X\n", flags);
    
    flags |= (1 << 3);
    printf("Set bit 3: 0x%02X\n", flags);
    
    flags |= (1 << 7);
    printf("Set bit 7: 0x%02X\n", flags);
    
    flags |= (1 << 3);
    printf("Set bit 3 again: 0x%02X\n", flags);
    
    return 0;
}
