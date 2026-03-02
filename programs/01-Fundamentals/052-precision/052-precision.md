---
id: "052"
title: "Precision Specifier"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - formatting
  - precision
  - decimal
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 052 — Precision Specifier

## Concept

**Precision** (`.n`) controls the accuracy or length of output, but its meaning varies by type:

| Type | Precision Meaning |
|------|-------------------|
| `%f`, `%e` | Digits after decimal point |
| `%g` | Maximum significant digits |
| `%s` | Maximum characters to print |
| `%d`, `%x` | Minimum digits (zero-padded) |

**Syntax:** `%[flags][width][.precision]specifier`

**Examples:**
```c
printf("%.2f", 3.14159);    // "3.14" (2 decimal places)
printf("%.5s", "Hello!");   // "Hello" (5 chars max)
printf("%.5d", 42);         // "00042" (5 digits min)
```

**Default precision:**
- `%f`, `%e`: 6 decimal places
- `%g`: 6 significant digits
- `%s`: No limit (prints all)
- `%d`: 1 (minimum)

**Dynamic precision with `*`:**
```c
int p = 3;
printf("%.*f", p, 3.14159);  // "3.142"
```

**Width + Precision:**
```c
printf("%10.2f", 3.14);  // "      3.14" (10 wide, 2 decimals)
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Precision Specifier ===\n\n");
    
    double pi = 3.141592653589793;
    
    printf("Float precision (decimal places):\n");
    printf("  Default %%f: %f\n", pi);
    printf("  %%.0f: %.0f\n", pi);
    printf("  %%.1f: %.1f\n", pi);
    printf("  %%.2f: %.2f\n", pi);
    printf("  %%.4f: %.4f\n", pi);
    printf("  %%.10f: %.10f\n", pi);
    printf("  %%.15f: %.15f\n", pi);
    
    printf("\nPrecision with width:\n");
    printf("  %%10.2f: [%10.2f]\n", pi);
    printf("  %%-10.2f: [%-10.2f]\n", pi);
    printf("  %%10.4f: [%10.4f]\n", pi);
    
    printf("\nCurrency formatting:\n");
    double price = 1234.5;
    printf("  Price: $%.2f\n", price);
    printf("  Price: $%10.2f\n", price);
    printf("  Price: $%010.2f\n", price);
    
    printf("\nString precision (max characters):\n");
    char longstr[] = "Hello, World!";
    printf("  Full: %s\n", longstr);
    printf("  %%.5s: %.5s\n", longstr);
    printf("  %%.10s: %.10s\n", longstr);
    printf("  %%10.5s: [%10.5s]\n", longstr);
    printf("  %%-10.5s: [%-10.5s]\n", longstr);
    
    printf("\nInteger precision (minimum digits):\n");
    int num = 42;
    printf("  %%d: %d\n", num);
    printf("  %%.5d: %.5d\n", num);
    printf("  %%.8d: %.8d\n", num);
    printf("  %%10.5d: [%10.5d]\n", num);
    
    printf("\nDynamic precision with *:\n");
    int prec = 4;
    printf("  %.*f (precision=%d)\n", prec, pi, prec);
    printf("  %.*s (max %d chars)\n", 7, longstr, 7);
    
    printf("\nDynamic width AND precision:\n");
    int w = 12, p = 3;
    printf("  %%*.*f: [%*.*f]\n", w, p, pi);
    
    printf("\nScientific notation precision:\n");
    double big = 123456789.0;
    printf("  %%.2e: %.2e\n", big);
    printf("  %%.4e: %.4e\n", big);
    printf("  %%.6e: %.6e\n", big);
    
    printf("\n%%g precision (significant digits):\n");
    printf("  %%g: %g\n", pi);
    printf("  %%.2g: %.2g\n", pi);
    printf("  %%.4g: %.4g\n", pi);
    printf("  %%.8g: %.8g\n", pi);
    
    printf("\nHex precision (minimum digits):\n");
    printf("  %%x: %x\n", 255);
    printf("  %%.4x: %.4x\n", 255);
    printf("  %%.8x: %.8x\n", 255);
    
    return 0;
}
```

## Output

```
=== Precision Specifier ===

Float precision (decimal places):
  Default %f: 3.141593
  %.0f: 3
  %.1f: 3.1
  %.2f: 3.14
  %.4f: 3.1416
  %.10f: 3.1415926536
  %.15f: 3.141592653589793

Precision with width:
  %10.2f: [      3.14]
  %-10.2f: [3.14      ]
  %10.4f: [    3.1416]

Currency formatting:
  Price: $1234.50
  Price: $   1234.50
  Price: $0001234.50

String precision (max characters):
  Full: Hello, World!
  %.5s: Hello
  %.10s: Hello, Wor
  %10.5s: [     Hello]
  %-10.5s: [Hello     ]

Integer precision (minimum digits):
  %d: 42
  %.5d: 00042
  %.8d: 00000042
  %10.5d: [     00042]

Dynamic precision with *:
  3.1416 (precision=4)
  Hello,  (max 7 chars)

Dynamic width AND precision:
  %*.*f: [       3.142]

Scientific notation precision:
  %.2e: 1.23e+08
  %.4e: 1.2346e+08
  %.6e: 1.234568e+08

%g precision (significant digits):
  %g: 3.14159
  %.2g: 3.1
  %.4g: 3.142
  %.8g: 3.1415927

Hex precision (minimum digits):
  %x: ff
  %.4x: 00ff
  %.8x: 000000ff
```

## Compilation

```bash
gcc 052-precision.c -o 052-precision
./052-precision
```

## Key Takeaways

- Precision meaning depends on the format specifier type
- For floats: number of decimal places
- For strings: maximum characters to print
- For integers: minimum digits (zero-padded)
- Use `.*` for dynamic precision from arguments
- Combine width and precision: `%10.2f`
- Rounding is applied when reducing float precision

## Challenge

Write a program that displays a financial report with amounts formatted to exactly 2 decimal places, right-aligned in columns, with thousand separators simulated using spacing.

## Related

- [[051-field-width]] — Width specifier
- [[054-flags-zero-hash]] — Zero padding flag
