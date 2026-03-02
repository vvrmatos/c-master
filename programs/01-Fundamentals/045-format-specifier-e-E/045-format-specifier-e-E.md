---
id: "045"
title: "Format Specifiers: %e and %E"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - scientific-notation
  - float
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 045 — Format Specifiers: %e and %E (Scientific Notation)

## Concept

`%e` and `%E` display floating-point numbers in **scientific notation** (exponential form). This format is ideal for very large or very small numbers.

**Format:** `[-]d.dddddde±dd` or `[-]d.ddddddE±dd`

**Key characteristics:**
- One digit before decimal point
- Default 6 digits after decimal point
- Exponent shown with `e` or `E`
- Exponent always has sign (+ or -)
- Exponent has at least 2 digits

**When to use:**
| Use `%e` | Use `%f` |
|----------|----------|
| Very large numbers (>10⁶) | Numbers near 1 |
| Very small numbers (<10⁻⁴) | Fixed decimal places |
| Scientific data | Currency, percentages |
| Unknown magnitude | Known magnitude |

**Precision with %e:**
```c
printf("%.2e", 12345.6789);  // 1.23e+04
printf("%.6e", 12345.6789);  // 1.234568e+04
```

**The exponent indicates:**
- `e+03` means ×10³ (multiply by 1000)
- `e-03` means ×10⁻³ (divide by 1000)

## Code

```c
#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void) {
    printf("=== Format Specifiers: %%e and %%E (Scientific Notation) ===\n\n");
    
    double d = 12345.6789;
    
    printf("Basic scientific notation:\n");
    printf("  %%e: %e\n", d);
    printf("  %%E: %E\n", d);
    
    printf("\nVarious magnitudes:\n");
    printf("  1.0:        %e\n", 1.0);
    printf("  123.456:    %e\n", 123.456);
    printf("  0.00123:    %e\n", 0.00123);
    printf("  -9876.54:   %e\n", -9876.54);
    
    printf("\nVery large numbers:\n");
    printf("  1e10:    %e\n", 1e10);
    printf("  1e100:   %e\n", 1e100);
    printf("  DBL_MAX: %e\n", DBL_MAX);
    
    printf("\nVery small numbers:\n");
    printf("  1e-10:   %e\n", 1e-10);
    printf("  1e-100:  %e\n", 1e-100);
    printf("  DBL_MIN: %e\n", DBL_MIN);
    
    printf("\nPrecision control:\n");
    double pi = 3.141592653589793;
    printf("  %%.2e: %.2e\n", pi);
    printf("  %%.4e: %.4e\n", pi);
    printf("  %%.10e: %.10e\n", pi);
    
    printf("\n%%e vs %%E (case difference):\n");
    printf("  %%e: %e\n", 6.022e23);
    printf("  %%E: %E\n", 6.022e23);
    
    printf("\nScientific constants:\n");
    double avogadro = 6.02214076e23;
    double planck = 6.62607015e-34;
    double speed_of_light = 2.998e8;
    double electron_mass = 9.109e-31;
    
    printf("  Avogadro's number: %.4e\n", avogadro);
    printf("  Planck's constant: %.4e J·s\n", planck);
    printf("  Speed of light: %.3e m/s\n", speed_of_light);
    printf("  Electron mass: %.3e kg\n", electron_mass);
    
    printf("\nSpecial values:\n");
    printf("  Infinity: %e\n", INFINITY);
    printf("  -Infinity: %e\n", -INFINITY);
    printf("  NaN: %e\n", NAN);
    
    return 0;
}
```

## Output

```
=== Format Specifiers: %e and %E (Scientific Notation) ===

Basic scientific notation:
  %e: 1.234568e+04
  %E: 1.234568E+04

Various magnitudes:
  1.0:        1.000000e+00
  123.456:    1.234560e+02
  0.00123:    1.230000e-03
  -9876.54:   -9.876540e+03

Very large numbers:
  1e10:    1.000000e+10
  1e100:   1.000000e+100
  DBL_MAX: 1.797693e+308

Very small numbers:
  1e-10:   1.000000e-10
  1e-100:  1.000000e-100
  DBL_MIN: 2.225074e-308

Precision control:
  %.2e: 3.14e+00
  %.4e: 3.1416e+00
  %.10e: 3.1415926536e+00

%e vs %E (case difference):
  %e: 6.022000e+23
  %E: 6.022000E+23

Scientific constants:
  Avogadro's number: 6.0221e+23
  Planck's constant: 6.6261e-34 J·s
  Speed of light: 2.998e+08 m/s
  Electron mass: 9.109e-31 kg

Special values:
  Infinity: inf
  -Infinity: -inf
  NaN: nan
```

## Compilation

```bash
gcc 045-format-specifier-e-E.c -o 045-format-specifier-e-E -lm
./045-format-specifier-e-E
```

## Key Takeaways

- `%e`/`%E` display numbers in scientific notation
- Format: `d.dddddd×10^exp` displayed as `d.dddddde±exp`
- Default: 6 digits after decimal point
- `%e` uses lowercase 'e', `%E` uses uppercase 'E'
- Ideal for very large or very small numbers
- Exponent always shows sign (+ or -)

## Challenge

Write a program that converts between metric prefixes (nano, micro, milli, kilo, mega, giga) and displays values in scientific notation.

## Related

- [[044-format-specifier-f-F]] — Fixed decimal notation
- [[046-format-specifier-g-G]] — Automatic shortest form
