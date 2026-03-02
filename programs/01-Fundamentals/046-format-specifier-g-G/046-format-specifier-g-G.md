---
id: "046"
title: "Format Specifiers: %g and %G"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - float
  - automatic
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 046 — Format Specifiers: %g and %G (Shortest Form)

## Concept

`%g` (and `%G`) automatically chooses between `%f` and `%e` format, picking whichever produces **shorter output**. It also removes trailing zeros, making output cleaner.

**Decision rules:**
1. If exponent < -4, use `%e` format
2. If exponent >= precision (default 6), use `%e` format
3. Otherwise, use `%f` format

**Key features:**
- Automatically selects shorter representation
- Removes insignificant trailing zeros
- Removes decimal point if no digits follow
- Precision means **significant digits** (not decimal places)

**Precision behavior:**
| Specifier | Precision Means |
|-----------|-----------------|
| `%f` | Digits after decimal point |
| `%e` | Digits after decimal point |
| `%g` | Total significant digits |

**Examples:**
```c
printf("%g", 0.00001234);  // 1.234e-05 (exponent<-4)
printf("%g", 0.1234);      // 0.1234 (f is shorter)
printf("%g", 1234567.0);   // 1.23457e+06 (exponent>=6)
printf("%g", 1.50000);     // 1.5 (trailing zeros removed)
```

## Code

```c
#include <stdio.h>
#include <math.h>

int main(void) {
    printf("=== Format Specifiers: %%g and %%G (Shortest Form) ===\n\n");
    
    printf("%%g automatically chooses %%f or %%e:\n");
    printf("  0.000123:   %g (uses %%e)\n", 0.000123);
    printf("  0.00123:    %g (uses %%e)\n", 0.00123);
    printf("  0.0123:     %g (uses %%f)\n", 0.0123);
    printf("  0.123:      %g (uses %%f)\n", 0.123);
    printf("  1.23:       %g (uses %%f)\n", 1.23);
    printf("  12.3:       %g (uses %%f)\n", 12.3);
    printf("  123.0:      %g (uses %%f)\n", 123.0);
    printf("  1234.0:     %g (uses %%f)\n", 1234.0);
    printf("  12345.0:    %g (uses %%f)\n", 12345.0);
    printf("  123456.0:   %g (uses %%f)\n", 123456.0);
    printf("  1234567.0:  %g (uses %%e)\n", 1234567.0);
    
    printf("\n%%g vs %%G (case difference):\n");
    printf("  %%g: %g\n", 1.23e10);
    printf("  %%G: %G\n", 1.23e10);
    
    printf("\n%%g removes trailing zeros:\n");
    printf("  %%f: %f\n", 1.5);
    printf("  %%g: %g\n", 1.5);
    printf("  %%f: %f\n", 1.500000);
    printf("  %%g: %g\n", 1.500000);
    
    printf("\nPrecision with %%g (significant digits):\n");
    double pi = 3.141592653589793;
    printf("  Default %%g: %g\n", pi);
    printf("  %%.2g: %.2g\n", pi);
    printf("  %%.4g: %.4g\n", pi);
    printf("  %%.10g: %.10g\n", pi);
    
    printf("\nComparing all three formats:\n");
    double values[] = {0.00001234, 0.1234, 123.4, 1234000.0};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("  %-15s %-15s %-15s %-15s\n", "Value", "%f", "%e", "%g");
    printf("  %-15s %-15s %-15s %-15s\n", "-----", "--", "--", "--");
    for (int i = 0; i < n; i++) {
        printf("  %-15g %-15f %-15e %-15g\n", 
               values[i], values[i], values[i], values[i]);
    }
    
    printf("\nPractical use case - adaptive output:\n");
    double measurements[] = {0.00000123, 0.045, 1.0, 42.5, 1500000.0};
    int m = sizeof(measurements) / sizeof(measurements[0]);
    
    for (int i = 0; i < m; i++) {
        printf("  Measurement %d: %g\n", i + 1, measurements[i]);
    }
    
    return 0;
}
```

## Output

```
=== Format Specifiers: %g and %G (Shortest Form) ===

%g automatically chooses %f or %e:
  0.000123:   0.000123 (uses %e)
  0.00123:    0.00123 (uses %e)
  0.0123:     0.0123 (uses %f)
  0.123:      0.123 (uses %f)
  1.23:       1.23 (uses %f)
  12.3:       12.3 (uses %f)
  123.0:      123 (uses %f)
  1234.0:     1234 (uses %f)
  12345.0:    12345 (uses %f)
  123456.0:   123456 (uses %f)
  1234567.0:  1.23457e+06 (uses %e)

%g vs %G (case difference):
  %g: 1.23e+10
  %G: 1.23E+10

%g removes trailing zeros:
  %f: 1.500000
  %g: 1.5
  %f: 1.500000
  %g: 1.5

Precision with %g (significant digits):
  Default %g: 3.14159
  %.2g: 3.1
  %.4g: 3.142
  %.10g: 3.141592654

Comparing all three formats:
  Value           %f              %e              %g             
  -----           --              --              --             
  1.234e-05       0.000012        1.234000e-05    1.234e-05      
  0.1234          0.123400        1.234000e-01    0.1234         
  123.4           123.400000      1.234000e+02    123.4          
  1.234e+06       1234000.000000  1.234000e+06    1.234e+06      

Practical use case - adaptive output:
  Measurement 1: 1.23e-06
  Measurement 2: 0.045
  Measurement 3: 1
  Measurement 4: 42.5
  Measurement 5: 1.5e+06
```

## Compilation

```bash
gcc 046-format-specifier-g-G.c -o 046-format-specifier-g-G
./046-format-specifier-g-G
```

## Key Takeaways

- `%g` picks the shorter of `%f` or `%e` representations
- Trailing zeros are automatically removed
- Precision specifies significant digits, not decimal places
- `%g` vs `%G` differs only in exponent letter case (e vs E)
- Great for displaying numbers of varying magnitudes
- Use when you don't know the range of values in advance

## Challenge

Write a program that displays the same value in all three formats (%f, %e, %g) side by side for a range of numbers from very small to very large.

## Related

- [[044-format-specifier-f-F]] — Fixed decimal format
- [[045-format-specifier-e-E]] — Scientific notation
