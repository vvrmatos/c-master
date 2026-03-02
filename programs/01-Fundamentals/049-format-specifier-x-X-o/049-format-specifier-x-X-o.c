#include <stdio.h>

int main(void) {
    unsigned int value = 255;

    printf("%x\n", value);
    printf("%X\n", value);
    printf("%o\n", value);
    printf("%#x\n", value);
    printf("%#X\n", value);
    printf("%08x\n", 0xABCD);
    printf("%#010x\n", 0xABCD);

    return 0;
}
