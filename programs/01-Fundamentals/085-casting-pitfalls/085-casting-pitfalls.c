// Casting pitfalls - precision loss

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    // Truncation: fractional part lost
    double d = 9.999;
    int i = (int)d;
    printf("Truncation: %.3f -> %d (lost %.3f)\n", d, i, d - i);
    
    // Overflow: value too large for target type
    long big = 3000000000L;
    int small = (int)big;
    printf("Overflow: %ld -> %d (UB on some systems)\n", big, small);
    
    // Precision loss: large int to float
    int precise = 123456789;
    float imprecise = (float)precise;
    printf("Precision: %d -> %.0f (diff: %d)\n", 
           precise, imprecise, precise - (int)imprecise);
    
    // Large double to int
    double huge = 1e20;
    int overflow = (int)huge;  // Undefined behavior!
    printf("Double overflow: %.0e -> %d (UB!)\n", huge, overflow);
    
    // Negative to unsigned
    int neg = -1;
    unsigned int u = (unsigned int)neg;
    printf("Signed to unsigned: %d -> %u\n", neg, u);
    
    return 0;
}
