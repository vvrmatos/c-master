#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("=== Integer Limits (limits.h) ===\n\n");
    
    printf("Bits in a char: CHAR_BIT = %d\n\n", CHAR_BIT);
    
    printf("char limits:\n");
    printf("  CHAR_MIN  = %d\n", CHAR_MIN);
    printf("  CHAR_MAX  = %d\n", CHAR_MAX);
    printf("  SCHAR_MIN = %d\n", SCHAR_MIN);
    printf("  SCHAR_MAX = %d\n", SCHAR_MAX);
    printf("  UCHAR_MAX = %u\n", UCHAR_MAX);
    
    printf("\nshort limits:\n");
    printf("  SHRT_MIN  = %d\n", SHRT_MIN);
    printf("  SHRT_MAX  = %d\n", SHRT_MAX);
    printf("  USHRT_MAX = %u\n", USHRT_MAX);
    
    printf("\nint limits:\n");
    printf("  INT_MIN   = %d\n", INT_MIN);
    printf("  INT_MAX   = %d\n", INT_MAX);
    printf("  UINT_MAX  = %u\n", UINT_MAX);
    
    printf("\nlong limits:\n");
    printf("  LONG_MIN  = %ld\n", LONG_MIN);
    printf("  LONG_MAX  = %ld\n", LONG_MAX);
    printf("  ULONG_MAX = %lu\n", ULONG_MAX);
    
    printf("\nlong long limits:\n");
    printf("  LLONG_MIN  = %lld\n", LLONG_MIN);
    printf("  LLONG_MAX  = %lld\n", LLONG_MAX);
    printf("  ULLONG_MAX = %llu\n", ULLONG_MAX);
    
    printf("\n--- Practical Uses ---\n");
    
    int value = 2000000000;
    if (value > INT_MAX / 2) {
        printf("\nWarning: value is more than half of INT_MAX\n");
        printf("Adding another %d might overflow!\n", value);
    }
    
    printf("\nCalculating if addition would overflow:\n");
    int a = INT_MAX - 10;
    int b = 5;
    if (b <= INT_MAX - a) {
        printf("  %d + %d = %d (safe)\n", a, b, a + b);
    }
    
    return 0;
}
