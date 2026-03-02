---
id: "044"
title: "Format Specifiers: %f and %F"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - float
  - double
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 044 — Format Specifiers: %f and %F

## Concept

`%f` and `%F` are format specifiers for **floating-point numbers** in decimal notation. They display the number with a decimal point and default to 6 digits after the decimal.

**Format specifiers for floats:**
| Specifier | Type | Notes |
|-----------|------|-------|
| `%f` | double | Lowercase inf/nan |
| `%F` | double | Uppercase INF/NAN |
| `%Lf` | long double | Note capital L |

**Key facts:**
- `float` is promoted to `double` when passed to printf, so both use `%f`
- Default precision: 6 decimal places
- `%f` vs `%F`: Only differ for infinity and NaN (lowercase vs uppercase)
- Very large/small numbers may be hard to read — use `%e` for those

**Special floating-point values:**
| Value | %f Output | %F Output |
|-------|-----------|-----------|
| ∞ | inf | INF |
| -∞ | -inf | -INF |
| NaN | nan | NAN |

**Common precision examples:**
```c
printf("%.2f", 3.14159);  // 3.14
printf("%.0f", 3.14159);  // 3
printf("%.10f", 3.14159); // 3.1415900000
```

> **Note:** `float` has ~7 significant digits, `double` has ~15-16. Printing more precision than a type supports shows garbage digits.

## Code

```c
#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void) {
    printf("=== Format Specifiers: %%f and %%F ===\n\n");
    
    float f = 3.14159f;
    double d = 3.141592653589793;
    long double ld = 3.14159265358979323846L;
    
    printf("Default %%f (6 decimal places):\n");
    printf("  float: %f\n", f);
    printf("  double: %f\n", d);
    printf("  long double: %Lf\n", ld);
    
    printf("\nVarious values:\n");
    printf("  Zero: %f\n", 0.0);
    printf("  One: %f\n", 1.0);
    printf("  Negative: %f\n", -273.15);
    printf("  Small: %f\n", 0.000123);
    printf("  Large: %f\n", 1234567.890);
    
    printf("\n%%f vs %%F (differ for special values):\n");
    printf("  Infinity %%f: %f\n", INFINITY);
    printf("  Infinity %%F: %F\n", INFINITY);
    printf("  -Infinity %%f: %f\n", -INFINITY);
    printf("  -Infinity %%F: %F\n", -INFINITY);
    printf("  NaN %%f: %f\n", NAN);
    printf("  NaN %%F: %F\n", NAN);
    
    printf("\nPrecision control (covered in depth later):\n");
    printf("  %%.2f: %.2f\n", d);
    printf("  %%.4f: %.4f\n", d);
    printf("  %%.10f: %.10f\n", d);
    
    printf("\nFloat limits:\n");
    printf("  FLT_MIN: %e\n", FLT_MIN);
    printf("  FLT_MAX: %e\n", FLT_MAX);
    printf("  DBL_MIN: %e\n", DBL_MIN);
    printf("  DBL_MAX: %e\n", DBL_MAX);
    
    printf("\nPractical examples:\n");
    double price = 19.99;
    double temperature = -40.0;
    double percentage = 0.8575;
    
    printf("  Price: $%.2f\n", price);
    printf("  Temperature: %.1f°C\n", temperature);
    printf("  Percentage: %.2f%%\n", percentage * 100);
    
    return 0;
}
```

## Output

```
=== Format Specifiers: %f and %F ===

Default %f (6 decimal places):
  float: 3.141590
  double: 3.141593
  long double: 3.141593

Various values:
  Zero: 0.000000
  One: 1.000000
  Negative: -273.150000
  Small: 0.000123
  Large: 1234567.890000

%f vs %F (differ for special values):
  Infinity %f: inf
  Infinity %F: INF
  -Infinity %f: -inf
  -Infinity %F: -INF
  NaN %f: nan
  NaN %F: NAN

Precision control (covered in depth later):
  %.2f: 3.14
  %.4f: 3.1416
  %.10f: 3.1415926536

Float limits:
  FLT_MIN: 1.175494e-38
  FLT_MAX: 3.402823e+38
  DBL_MIN: 2.225074e-308
  DBL_MAX: 1.797693e+308

Practical examples:
  Price: $19.99
  Temperature: -40.0°C
  Percentage: 85.75%
```

## Compilation

```bash
gcc 044-format-specifier-f-F.c -o 044-format-specifier-f-F -lm
./044-format-specifier-f-F
```

## Key Takeaways

- `%f` prints floating-point numbers with 6 decimal places by default
- Both `float` and `double` use `%f` (float is promoted to double)
- Use `%Lf` (capital L) for `long double`
- `%f` vs `%F` only differs for inf/nan output case
- Use precision (`.n`) to control decimal places
- Link with `-lm` when using math.h functions

## Challenge

Write a program that calculates compound interest and displays the results formatted as currency with 2 decimal places.

## Related

- [[045-format-specifier-e-E]] — Scientific notation
- [[052-precision]] — Decimal precision control
