#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("=== Signed vs Unsigned Integers ===\n\n");
    
    printf("--- Range Differences ---\n");
    printf("signed char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("\nsigned int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:  0 to %u\n", UINT_MAX);
    
    printf("\n--- Bit Representation (8-bit example) ---\n");
    signed char sc = -1;
    unsigned char uc = 255;
    printf("signed char -1 as bits:   11111111 (two's complement)\n");
    printf("unsigned char 255 as bits: 11111111 (same bits!)\n");
    printf("Same bit pattern, different interpretation!\n");
    
    printf("\n--- Overflow Behavior ---\n");
    unsigned int u = UINT_MAX;
    printf("unsigned int at max: %u\n", u);
    u = u + 1;
    printf("After adding 1:      %u (wraps to 0 - defined behavior)\n", u);
    
    printf("\n--- Mixed Comparisons (Dangerous!) ---\n");
    int signed_val = -1;
    unsigned int unsigned_val = 1;
    
    printf("signed_val = %d, unsigned_val = %u\n", signed_val, unsigned_val);
    printf("Is -1 < 1? Mathematically: yes\n");
    
    if (signed_val < unsigned_val) {
        printf("Comparison result: -1 < 1 (correct)\n");
    } else {
        printf("Comparison result: -1 >= 1 (WRONG! -1 converted to large unsigned)\n");
    }
    
    printf("\n--- Safe Pattern ---\n");
    int a = -5;
    unsigned int b = 10;
    if (a < 0 || (unsigned int)a < b) {
        printf("Properly handled: %d is less than %u\n", a, b);
    }
    
    printf("\n--- Common Use Cases ---\n");
    printf("Use signed for: general arithmetic, loop counters that might go negative\n");
    printf("Use unsigned for: bit manipulation, array indices, sizes, flags\n");
    
    return 0;
}
