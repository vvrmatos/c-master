#include <stdio.h>

int main(void) {
    unsigned int u = 4294967295U;
    unsigned short us = 65535;
    unsigned long ul = 4294967295UL;
    unsigned long long ull = 18446744073709551615ULL;
    
    printf("=== Unsigned Integers ===\n\n");
    
    printf("unsigned int u = %u\n", u);
    printf("unsigned short us = %hu\n", us);
    printf("unsigned long ul = %lu\n", ul);
    printf("unsigned long long ull = %llu\n", ull);
    
    printf("\nSigned vs Unsigned ranges (assuming 32-bit int):\n");
    printf("  signed int:   -2,147,483,648 to 2,147,483,647\n");
    printf("  unsigned int: 0 to 4,294,967,295\n");
    
    unsigned int x = 0;
    printf("\nDanger! Underflow:\n");
    printf("  unsigned int x = 0\n");
    printf("  x - 1 = %u (wraps around!)\n", x - 1);
    
    return 0;
}
