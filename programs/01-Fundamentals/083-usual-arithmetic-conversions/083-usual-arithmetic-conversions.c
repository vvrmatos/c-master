// Usual arithmetic conversions (mixed types)

#include <stdio.h>

int main(void) {
    int i = 5;
    long l = 10L;
    float f = 2.5f;
    double d = 3.5;
    
    // int + long -> long
    long r1 = i + l;
    printf("int + long = %ld (size: %zu)\n", r1, sizeof(i + l));
    
    // long + float -> float
    float r2 = l + f;
    printf("long + float = %.1f (size: %zu)\n", r2, sizeof(l + f));
    
    // float + double -> double
    double r3 = f + d;
    printf("float + double = %.1f (size: %zu)\n", r3, sizeof(f + d));
    
    // int + double -> double
    double r4 = i + d;
    printf("int + double = %.1f (size: %zu)\n", r4, sizeof(i + d));
    
    // Full chain: int + long + float + double -> double
    double r5 = i + l + f + d;
    printf("i + l + f + d = %.1f (size: %zu)\n", r5, sizeof(i + l + f + d));
    
    return 0;
}
