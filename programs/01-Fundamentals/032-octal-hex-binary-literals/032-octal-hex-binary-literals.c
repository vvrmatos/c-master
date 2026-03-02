#include <stdio.h>

int main(void) {
    int decimal = 255;
    int octal = 0377;
    int hex_lower = 0xff;
    int hex_upper = 0xFF;
    int binary = 0b11111111;
    
    printf("=== Octal, Hexadecimal, and Binary Literals ===\n\n");
    
    printf("Same value in different bases:\n");
    printf("  Decimal:     255   = %d\n", decimal);
    printf("  Octal:       0377  = %d\n", octal);
    printf("  Hexadecimal: 0xFF  = %d\n", hex_upper);
    printf("  Binary:      0b11111111 = %d\n", binary);
    
    printf("\nOctal literals (prefix 0):\n");
    printf("  010 = %d (not 10!)\n", 010);
    printf("  0777 = %d (Unix permissions)\n", 0777);
    printf("  0644 = %d (file permissions)\n", 0644);
    
    printf("\nHexadecimal literals (prefix 0x or 0X):\n");
    printf("  0xDEADBEEF = %u\n", 0xDEADBEEF);
    printf("  0xCAFEBABE = %u\n", 0xCAFEBABE);
    printf("  0x7F = %d (max signed byte)\n", 0x7F);
    printf("  0xFF = %d (max unsigned byte)\n", 0xFF);
    
    printf("\nBinary literals (C23/GNU extension, prefix 0b):\n");
    printf("  0b1010 = %d\n", 0b1010);
    printf("  0b11110000 = %d\n", 0b11110000);
    printf("  0b00001111 = %d\n", 0b00001111);
    
    printf("\nCommon patterns in security:\n");
    printf("  0x41414141 = %u ('AAAA')\n", 0x41414141);
    printf("  0x90909090 = %u (NOP sled)\n", 0x90909090);
    printf("  0xCCCCCCCC = %u (INT3 breakpoints)\n", 0xCCCCCCCC);
    
    printf("\nWith type suffixes:\n");
    printf("  0xFFFFFFFFUL = %lu\n", 0xFFFFFFFFUL);
    printf("  0xFFFFFFFFFFFFFFFFULL = %llu\n", 0xFFFFFFFFFFFFFFFFULL);
    
    return 0;
}
