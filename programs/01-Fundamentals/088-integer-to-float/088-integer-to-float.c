// Integer to float conversion (precision)

#include <stdio.h>
#include <float.h>

int main(void) {
    // Small integers convert exactly
    int small = 42;
    float f_small = small;
    printf("int %d -> float %.1f (exact)\n", small, f_small);
    
    // Large integers may lose precision
    int large = 123456789;
    float f_large = large;
    printf("int %d -> float %.0f (diff: %d)\n", 
           large, f_large, large - (int)f_large);
    
    // double has more precision
    double d_large = large;
    printf("int %d -> double %.0f (diff: %.0f)\n",
           large, d_large, large - d_large);
    
    // The limit of float precision
    printf("\nFloat precision limit:\n");
    for (int i = 16777210; i <= 16777220; i++) {
        float f = i;
        printf("%d -> %.0f %s\n", i, f, (i == (int)f) ? "" : "(lost precision)");
    }
    
    // Why? float has 23-bit mantissa
    printf("\nFloat mantissa: 23 bits = %d distinct values\n", 1 << 23);
    printf("2^24 = %d (largest exact integer in float)\n", 1 << 24);
    
    return 0;
}
