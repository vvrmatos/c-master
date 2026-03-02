---
id: "023"
title: "Floating Point Limits (float.h)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - float
  - double
  - limits
  - precision
  - epsilon
difficulty: beginner
source: "C11 Standard 5.2.4.2.2, float.h"
---

# 023 — Floating Point Limits (float.h)

## Concept

The `<float.h>` header defines constants describing the characteristics of floating-point types. Understanding these is crucial for numerical code.

**Key constants for each type (FLT_, DBL_, LDBL_):**

| Constant | Meaning |
|----------|---------|
| `XXX_MIN` | Smallest positive normalized value |
| `XXX_MAX` | Largest finite value |
| `XXX_EPSILON` | Smallest ε where 1.0 + ε ≠ 1.0 |
| `XXX_DIG` | Decimal digits of precision |
| `XXX_MANT_DIG` | Bits in mantissa (significand) |
| `XXX_MIN_EXP` | Minimum exponent |
| `XXX_MAX_EXP` | Maximum exponent |

**Typical values (IEEE 754):**

| Type | Epsilon | Precision | Max |
|------|---------|-----------|-----|
| float | ~1.2e-7 | 6 digits | ~3.4e38 |
| double | ~2.2e-16 | 15 digits | ~1.8e308 |
| long double | ~1.1e-19 | 18+ digits | Platform-dependent |

**Epsilon is critical for comparisons:**

```c
// WRONG: Direct floating-point comparison
if (a == b) { ... }

// RIGHT: Compare with tolerance
if (fabs(a - b) < DBL_EPSILON * fabs(a)) { ... }
```

**Note:** `XXX_MIN` is the smallest **positive normalized** value, not the most negative! For float, the most negative is `-FLT_MAX`.

## Code

```c
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
```

## Output

```
=== Floating Point Limits (float.h) ===

--- float ---
  FLT_MIN        = 1.175494e-38 (smallest positive normalized)
  FLT_MAX        = 3.402823e+38 (largest value)
  FLT_EPSILON    = 1.192093e-07 (smallest x where 1.0+x != 1.0)
  FLT_DIG        = 6 (decimal digits of precision)
  FLT_MANT_DIG   = 24 (bits in mantissa)
  FLT_MIN_EXP    = -125 (minimum exponent)
  FLT_MAX_EXP    = 128 (maximum exponent)

--- double ---
  DBL_MIN        = 2.225074e-308 (smallest positive normalized)
  DBL_MAX        = 1.797693e+308 (largest value)
  DBL_EPSILON    = 2.220446e-16 (smallest x where 1.0+x != 1.0)
  DBL_DIG        = 15 (decimal digits of precision)
  DBL_MANT_DIG   = 53 (bits in mantissa)
  DBL_MIN_EXP    = -1021 (minimum exponent)
  DBL_MAX_EXP    = 1024 (maximum exponent)

--- long double ---
  LDBL_MIN       = 3.362103e-4932
  LDBL_MAX       = 1.189731e+4932
  LDBL_EPSILON   = 1.084202e-19
  LDBL_DIG       = 18

--- Practical Epsilon Usage ---
  0.1 + 0.2 = 0.30000001192092895508
  0.3       = 0.30000001192092895508
  Direct comparison (a == b): true
  |a - b| = 0.000000e+00
  Epsilon comparison (|a-b| < FLT_EPSILON): true
```

## Key Takeaways

- `<float.h>` defines limits for `float`, `double`, and `long double`
- `EPSILON` is crucial for floating-point comparisons
- Never compare floats directly with `==`; use epsilon-based comparison
- `XXX_MIN` is smallest positive, not most negative (use `-XXX_MAX`)
- `float` has ~7 significant digits, `double` has ~15
- Use `double` by default; `float` only when memory is critical

## Challenge

Write a function `float_equal(double a, double b)` that returns 1 if two doubles are "equal" using a relative epsilon comparison: `|a-b| <= epsilon * max(|a|, |b|)`. Handle the case where both values are near zero.

## Related

- [[016-floating-point-float]] — Float basics
- [[017-floating-point-double]] — Double basics
- [[022-integer-limits]] — Integer limits
- [[021-sizeof-operator]] — Type sizes
