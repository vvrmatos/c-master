---
id: "033"
title: "Floating-Point Literals"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - literals
  - floating-point
  - double
  - float
difficulty: beginner
source: "C11 Standard Section 6.4.4.2"
---

# 033 — Floating-Point Literals

## Concept

Floating-point literals represent real numbers with fractional parts. They can be written in decimal notation or scientific notation. Unlike integers, floating-point literals have a **default type of `double`**, not `float`.

Notation styles:
- **Decimal**: `3.14`, `.5`, `2.`, `0.0`
- **Scientific**: `1.5e10`, `6.022E23`, `1.6e-19`
- **Hexadecimal** (C99): `0x1.5p10` (mantissa in hex, exponent is power of 2)

Type suffixes:
- No suffix → `double` (default)
- `f` or `F` → `float`
- `l` or `L` → `long double`

> **Precision Warning**: Float literals default to `double`. When assigning to `float`, use the `f` suffix to avoid implicit conversion. This matters for precision-sensitive calculations and binary compatibility.

## Code

```c
#include <stdio.h>

int main(void) {
    double d1 = 3.14159;
    double d2 = 3.14159265358979;
    double d3 = .5;
    double d4 = 2.;
    double d5 = 0.0;
    
    float f1 = 3.14f;
    float f2 = 3.14F;
    
    long double ld1 = 3.14159265358979323846L;
    
    double sci1 = 1.5e10;
    double sci2 = 1.5E10;
    double sci3 = 6.022e23;
    double sci4 = 1.6e-19;
    double sci5 = 2.99792458e8;
    
    printf("=== Floating-Point Literals ===\n\n");
    
    printf("Basic decimal notation:\n");
    printf("  3.14159   = %.5f\n", d1);
    printf("  3.14159265358979 = %.14f\n", d2);
    printf("  .5        = %f\n", d3);
    printf("  2.        = %f\n", d4);
    printf("  0.0       = %f\n", d5);
    
    printf("\nWith type suffixes:\n");
    printf("  3.14f  (float)       = %f\n", f1);
    printf("  3.14F  (float)       = %f\n", f2);
    printf("  3.14L  (long double) = %Lf\n", ld1);
    printf("  3.14   (double)      = %f (default)\n", 3.14);
    
    printf("\nScientific notation (e or E):\n");
    printf("  1.5e10  = %e = %.0f\n", sci1, sci1);
    printf("  1.5E10  = %E\n", sci2);
    printf("  6.022e23 (Avogadro) = %e\n", sci3);
    printf("  1.6e-19 (electron charge) = %e\n", sci4);
    printf("  2.99792458e8 (speed of light) = %e m/s\n", sci5);
    
    printf("\nSize comparison:\n");
    printf("  sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("  sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("  sizeof(long double) = %zu bytes\n", sizeof(long double));
    
    printf("\nHexadecimal floating-point (C99):\n");
    double hex_float = 0x1.5p10;
    printf("  0x1.5p10 = %f (1.3125 * 2^10)\n", hex_float);
    
    return 0;
}
```

## Output

```
=== Floating-Point Literals ===

Basic decimal notation:
  3.14159   = 3.14159
  3.14159265358979 = 3.14159265358979
  .5        = 0.500000
  2.        = 2.000000
  0.0       = 0.000000

With type suffixes:
  3.14f  (float)       = 3.140000
  3.14F  (float)       = 3.140000
  3.14L  (long double) = 3.141593
  3.14   (double)      = 3.140000 (default)

Scientific notation (e or E):
  1.5e10  = 1.500000e+10 = 15000000000
  1.5E10  = 1.500000E+10
  6.022e23 (Avogadro) = 6.022000e+23
  1.6e-19 (electron charge) = 1.600000e-19
  2.99792458e8 (speed of light) = 2.997925e+08 m/s

Size comparison:
  sizeof(float)       = 4 bytes
  sizeof(double)      = 8 bytes
  sizeof(long double) = 16 bytes

Hexadecimal floating-point (C99):
  0x1.5p10 = 1344.000000 (1.3125 * 2^10)
```

## Key Takeaways

- Default type for floating literals is `double`, not float
- Use `f` suffix for float: `3.14f`
- Use `L` suffix for long double: `3.14L`
- Scientific notation: `e` or `E` followed by exponent
- Can omit leading/trailing zero: `.5` and `2.` are valid
- Hex float: `0x1.5p10` means 1.3125 × 2¹⁰

## Challenge

Calculate the distance light travels in one year using scientific notation literals. Store in appropriate precision and display in both scientific and regular notation.

## Related

- [[015-floating-point-types]] — Float and double variables
- [[044-format-specifier-f-F]] — Printing floats
- [[045-format-specifier-e-E]] — Scientific notation output
