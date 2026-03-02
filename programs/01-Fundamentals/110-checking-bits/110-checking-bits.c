#include <stdio.h>

int main(void) {
    unsigned char flags = 0b10100101;
    
    printf("flags = 0x%02X\n\n", flags);
    
    for (int i = 7; i >= 0; i--) {
        if (flags & (1 << i)) {
            printf("Bit %d is SET\n", i);
        } else {
            printf("Bit %d is CLEAR\n", i);
        }
    }
    
    return 0;
}
