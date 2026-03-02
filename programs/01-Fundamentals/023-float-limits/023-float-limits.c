#include <stdio.h>
#include <float.h>

int main(void) {
    printf("=== Floating Point Limits (float.h) ===\n\n");
    
    printf("--- float ---\n");
    printf("  FLT_MIN        = %e (smallest positive normalized)\n", FLT_MIN);
    printf("  FLT_MAX        = %e (largest value)\n", FLT_MAX);
    printf("  FLT_EPSILON    = %e (smallest x where 1.0+x != 1.0)\n", FLT_EPSILON);
    printf("  FLT_DIG        = %d (decimal digits of precision)\n", FLT_DIG);
    printf("  FLT_MANT_DIG   = %d (bits in mantissa)\n", FLT_MANT_DIG);
    printf("  FLT_MIN_EXP    = %d (minimum exponent)\n", FLT_MIN_EXP);
    printf("  FLT_MAX_EXP    = %d (maximum exponent)\n", FLT_MAX_EXP);
    
    printf("\n--- double ---\n");
    printf("  DBL_MIN        = %e (smallest positive normalized)\n", DBL_MIN);
    printf("  DBL_MAX        = %e (largest value)\n", DBL_MAX);
    printf("  DBL_EPSILON    = %e (smallest x where 1.0+x != 1.0)\n", DBL_EPSILON);
    printf("  DBL_DIG        = %d (decimal digits of precision)\n", DBL_DIG);
    printf("  DBL_MANT_DIG   = %d (bits in mantissa)\n", DBL_MANT_DIG);
    printf("  DBL_MIN_EXP    = %d (minimum exponent)\n", DBL_MIN_EXP);
    printf("  DBL_MAX_EXP    = %d (maximum exponent)\n", DBL_MAX_EXP);
    
    printf("\n--- long double ---\n");
    printf("  LDBL_MIN       = %Le\n", LDBL_MIN);
    printf("  LDBL_MAX       = %Le\n", LDBL_MAX);
    printf("  LDBL_EPSILON   = %Le\n", LDBL_EPSILON);
    printf("  LDBL_DIG       = %d\n", LDBL_DIG);
    
    printf("\n--- Practical Epsilon Usage ---\n");
    float a = 0.1f + 0.2f;
    float b = 0.3f;
    
    printf("  0.1 + 0.2 = %.20f\n", (double)a);
    printf("  0.3       = %.20f\n", (double)b);
    printf("  Direct comparison (a == b): %s\n", (a == b) ? "true" : "false");
    
    float diff = a - b;
    if (diff < 0) diff = -diff;
    printf("  |a - b| = %e\n", diff);
    printf("  Epsilon comparison (|a-b| < FLT_EPSILON): %s\n", 
           (diff < FLT_EPSILON) ? "true" : "false");
    
    return 0;
}
