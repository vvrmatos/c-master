---
id: "016"
title: "Floating Point (float)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - float
  - data-types
  - floating-point
  - ieee754
difficulty: beginner
source: "C11 Standard 6.2.5, IEEE 754"
---

# 016 — Floating Point (float)

## Concept

`float` stores numbers with decimal points (floating-point numbers). It uses the IEEE 754 single-precision format.

**Key characteristics:**
- Size: 4 bytes (32 bits)
- Precision: ~7 decimal digits
- Range: approximately ±3.4 × 10³⁸
- Format specifier: `%f`, `%e`, `%g`

**IEEE 754 single-precision (32 bits):**
```
[1 bit sign][8 bit exponent][23 bit mantissa]
```

**Important: Floats are approximations!**
```c
float x = 0.1f;  // Not exactly 0.1!
```

Many decimal fractions cannot be represented exactly in binary floating-point. This leads to precision errors.

**Literal suffix:** Use `f` or `F` to make a literal float:
```c
float f = 3.14f;   // float
double d = 3.14;   // double (default!)
```

Without `f`, floating-point literals are `double` by default.

**Format specifiers:**
| Specifier | Output |
|-----------|--------|
| `%f` | Decimal: 3.141593 |
| `%e` | Scientific: 3.141593e+00 |
| `%g` | Shortest of %f or %e |
| `%.2f` | 2 decimal places: 3.14 |

## Code

```c
#include <stdio.h>

int main(void) {
    float f = 3.14159f;
    float scientific = 6.022e23f;
    float small = 1.6e-19f;
    
    printf("=== Floating Point (float) ===\n\n");
    
    printf("float f = %f\n", f);
    printf("float f = %.2f (2 decimal places)\n", f);
    printf("float f = %e (scientific notation)\n", f);
    
    printf("\nScientific notation:\n");
    printf("  %e (Avogadro's number)\n", scientific);
    printf("  %e (electron charge)\n", small);
    
    printf("\nSize of float: %zu bytes\n", sizeof(float));
    
    printf("\nFloat precision issues:\n");
    float a = 0.1f;
    float b = 0.2f;
    float sum = a + b;
    printf("  0.1 + 0.2 = %.20f\n", sum);
    printf("  (Not exactly 0.3!)\n");
    
    printf("\nFloat literal suffix: f or F\n");
    printf("  3.14f  = float\n");
    printf("  3.14   = double (default)\n");
    
    return 0;
}
```

## Output

```
=== Floating Point (float) ===

float f = 3.141590
float f = 3.14 (2 decimal places)
float f = 3.141590e+00 (scientific notation)

Scientific notation:
  6.022000e+23 (Avogadro's number)
  1.600000e-19 (electron charge)

Size of float: 4 bytes

Float precision issues:
  0.1 + 0.2 = 0.30000001192092895508
  (Not exactly 0.3!)

Float literal suffix: f or F
  3.14f  = float
  3.14   = double (default)
```

## Key Takeaways

- `float` is 4 bytes, ~7 digits precision
- Use `f` suffix for float literals: `3.14f`
- Without suffix, literals are `double`
- Floats are **approximations**, not exact
- Use `%f` for normal, `%e` for scientific notation
- `%.Nf` controls decimal places
- Never compare floats with `==` exactly!

## Challenge

Why does `0.1 + 0.2 != 0.3` in floating point? Research IEEE 754 representation and understand why 0.1 cannot be exactly represented in binary.

## Related

- [[017-floating-point-double]] — Double precision
- [[018-long-double]] — Extended precision
- [[023-float-limits]] — FLT_MAX, FLT_MIN
- [[099-common-comparison-mistakes]] — Float comparison
