---
id: "018"
title: "Long Double"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - long-double
  - data-types
  - floating-point
  - precision
difficulty: beginner
source: "C11 Standard 6.2.5"
---

# 018 — Long Double

## Concept

`long double` provides extended precision floating-point. Its size and precision vary significantly by platform — more so than any other type.

**Platform variations:**
| Platform | Size | Precision |
|----------|------|-----------|
| x86/x64 (Linux/macOS) | 16 bytes (80-bit used) | ~18-21 digits |
| x86/x64 (Windows MSVC) | 8 bytes | Same as double |
| ARM64 | 16 bytes (128-bit quad) | ~33 digits |
| Some embedded | 8 bytes | Same as double |

**Key points:**
- C only guarantees: `sizeof(double) <= sizeof(long double)`
- The actual precision depends on the platform
- Use `L` suffix for literals: `3.14L`
- Use `%Lf`, `%Le`, `%Lg` format specifiers

**When to use:**
- High-precision scientific calculations
- Intermediate results in numerical algorithms
- When double precision isn't enough
- Financial calculations requiring more digits

**When NOT to use:**
- Cross-platform code (size varies too much)
- Performance-critical code
- When you need a specific precision (use libraries instead)

**Alternative:** For truly portable high precision, consider libraries like GMP (GNU Multiple Precision) or using fixed-point arithmetic.

## Code

```c
#include <stdio.h>

int main(void) {
    long double ld = 3.14159265358979323846264338327950288L;
    
    printf("=== Long Double ===\n\n");
    
    printf("Sizes:\n");
    printf("  sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("  sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("  sizeof(long double) = %zu bytes\n", sizeof(long double));
    
    printf("\nPrecision comparison (pi):\n");
    float f = 3.14159265358979323846264338327950288f;
    double d = 3.14159265358979323846264338327950288;
    printf("  float:       %.20f\n", (double)f);
    printf("  double:      %.20f\n", d);
    printf("  long double: %.20Lf\n", ld);
    
    printf("\nLong double literal suffix: L\n");
    printf("  3.14L = long double\n");
    
    printf("\nFormat specifier: %%Lf, %%Le, %%Lg\n");
    printf("  Value: %Lf\n", ld);
    printf("  Sci:   %Le\n", ld);
    
    printf("\nNote: long double size varies by platform:\n");
    printf("  - x86 (80-bit extended): 10-16 bytes\n");
    printf("  - Some systems: same as double (8 bytes)\n");
    printf("  - Some systems: 128-bit quad precision\n");
    
    return 0;
}
```

## Output

```
=== Long Double ===

Sizes:
  sizeof(float)       = 4 bytes
  sizeof(double)      = 8 bytes
  sizeof(long double) = 16 bytes

Precision comparison (pi):
  float:       3.14159274101257324219
  double:      3.14159265358979311600
  long double: 3.14159265358979323851

Long double literal suffix: L
  3.14L = long double

Format specifier: %Lf, %Le, %Lg
  Value: 3.141593
  Sci:   3.141593e+00

Note: long double size varies by platform:
  - x86 (80-bit extended): 10-16 bytes
  - Some systems: same as double (8 bytes)
  - Some systems: 128-bit quad precision
```

## Key Takeaways

- `long double` has platform-dependent precision
- Use `L` suffix: `3.14L`
- Use `%Lf` format specifier
- May be 8, 10, 12, or 16 bytes depending on platform
- On Windows MSVC, often same as double
- On x86 Linux/macOS, typically 80-bit precision
- For portable precision, consider specialized libraries

## Challenge

Write a program that calculates the same value using float, double, and long double, then compares how many digits of precision each provides.

## Related

- [[016-floating-point-float]] — Single precision
- [[017-floating-point-double]] — Double precision
- [[023-float-limits]] — LDBL_MAX, LDBL_MIN
