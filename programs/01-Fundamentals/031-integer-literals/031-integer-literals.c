#include <stdio.h>

int main(void) {
    int zero = 0;
    int positive = 42;
    int negative = -17;
    int large = 1000000;
    int with_suffix_l = 100L;
    long with_suffix_ll = 100LL;
    unsigned int with_suffix_u = 100U;
    unsigned long with_suffix_ul = 100UL;
    unsigned long long with_suffix_ull = 100ULL;
    
    printf("=== Integer Literals ===\n\n");
    
    printf("Basic decimal literals:\n");
    printf("  zero = %d\n", zero);
    printf("  positive = %d\n", positive);
    printf("  negative = %d\n", negative);
    printf("  large = %d\n", large);
    
    printf("\nLiterals with suffixes:\n");
    printf("  100L   (long)               = %ld\n", with_suffix_l);
    printf("  100LL  (long long)          = %lld\n", with_suffix_ll);
    printf("  100U   (unsigned)           = %u\n", with_suffix_u);
    printf("  100UL  (unsigned long)      = %lu\n", with_suffix_ul);
    printf("  100ULL (unsigned long long) = %llu\n", with_suffix_ull);
    
    printf("\nCombined suffixes:\n");
    printf("  42LU or 42UL = %lu\n", 42LU);
    printf("  99LLU or 99ULL = %llu\n", 99LLU);
    
    printf("\nInteger literal rules:\n");
    printf("  - No leading zeros for decimal (0 prefix = octal!)\n");
    printf("  - Suffixes are case-insensitive (L = l, U = u)\n");
    printf("  - Default type: int (or larger if needed)\n");
    
    return 0;
}
