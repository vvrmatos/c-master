---
id: "017"
title: "Floating Point (double)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - double
  - data-types
  - floating-point
  - ieee754
difficulty: beginner
source: "C11 Standard 6.2.5, IEEE 754"
---

# 017 — Floating Point (double)

## Concept

`double` is double-precision floating-point — the **default** and most commonly used floating-point type in C.

**Key characteristics:**
- Size: 8 bytes (64 bits)
- Precision: ~15-17 decimal digits
- Range: approximately ±1.7 × 10³⁰⁸
- Format specifier: `%f`, `%lf` (for scanf), `%e`, `%g`

**IEEE 754 double-precision (64 bits):**
```
[1 bit sign][11 bit exponent][52 bit mantissa]
```

**Why use double over float?**
- More than double the precision (~15 vs ~7 digits)
- Default type for floating-point literals
- Most math library functions work with double
- Minimal performance difference on modern CPUs

**When to use float instead:**
- Large arrays where memory matters
- GPU programming (often prefers float)
- Explicit need for 32-bit representation

**Literal suffix:**
```c
double d = 3.14;      // double (default, no suffix)
float f = 3.14f;      // float (f suffix)
long double l = 3.14L; // long double (L suffix)
```

**printf vs scanf format specifiers:**
```c
printf("%f", d);   // %f works for both float and double
scanf("%lf", &d);  // MUST use %lf for double in scanf!
```

## Code

```c
#include <stdio.h>

int main(void) {
    double d = 3.141592653589793;
    double large = 1.7976931348623157e308;
    double small = 2.2250738585072014e-308;
    
    printf("=== Floating Point (double) ===\n\n");
    
    printf("double d = %.15f\n", d);
    printf("double d = %f (default 6 decimals)\n", d);
    printf("double d = %e\n", d);
    
    printf("\nSize comparison:\n");
    printf("  sizeof(float)  = %zu bytes\n", sizeof(float));
    printf("  sizeof(double) = %zu bytes\n", sizeof(double));
    
    printf("\nPrecision comparison (pi):\n");
    float  f_pi = 3.141592653589793f;
    double d_pi = 3.141592653589793;
    printf("  float:  %.15f\n", f_pi);
    printf("  double: %.15f\n", d_pi);
    printf("  actual: 3.141592653589793...\n");
    
    printf("\nDouble is the DEFAULT for literals:\n");
    printf("  3.14   -> double\n");
    printf("  3.14f  -> float\n");
    printf("  3.14L  -> long double\n");
    
    printf("\nRange:\n");
    printf("  Max: %e\n", large);
    printf("  Min positive: %e\n", small);
    
    return 0;
}
```

## Output

```
=== Floating Point (double) ===

double d = 3.141592653589793
double d = 3.141593 (default 6 decimals)
double d = 3.141593e+00

Size comparison:
  sizeof(float)  = 4 bytes
  sizeof(double) = 8 bytes

Precision comparison (pi):
  float:  3.141592741012573
  double: 3.141592653589793
  actual: 3.141592653589793...

Range:
  Max: 1.797693e+308
  Min positive: 2.225074e-308
```

## Key Takeaways

- `double` is 8 bytes, ~15 digits precision
- It's the DEFAULT for floating-point literals
- Use `%f` for printf, `%lf` for scanf with double
- Double has twice the precision of float
- Most math functions (sin, cos, sqrt) use double
- Prefer double unless you have specific reasons

## Challenge

Calculate the value of e (Euler's number) using the series: e = 1 + 1/1! + 1/2! + 1/3! + ... Compare float vs double precision after 20 terms.

## Related

- [[016-floating-point-float]] — Single precision
- [[018-long-double]] — Extended precision
- [[023-float-limits]] — DBL_MAX, DBL_MIN
- [[057-scanf-for-floats]] — Reading doubles
