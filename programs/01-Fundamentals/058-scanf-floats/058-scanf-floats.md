---
id: "058"
title: "scanf() Float Input"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - scanf
  - input
  - float
  - double
difficulty: beginner
source: "C11 Standard 7.21.6.2"
---

# 058 — scanf() Float Input

## Concept

Reading floating-point numbers with scanf requires attention to type specifiers — they differ from printf!

**Critical difference from printf:**
| Type | scanf | printf |
|------|-------|--------|
| float | `%f` | `%f` |
| double | `%lf` | `%f` |
| long double | `%Lf` | `%Lf` |

**Why the difference?**
- printf receives doubles (floats are promoted)
- scanf receives pointers to specific types
- `%f` pointer to scanf means 4-byte float
- `%lf` pointer means 8-byte double

**Common mistake:**
```c
double d;
scanf("%f", &d);   // WRONG! Writes 4 bytes to 8-byte variable
scanf("%lf", &d);  // CORRECT
```

**Input formats accepted:**
- Decimal: `3.14`, `3.`, `.14`, `3`
- Scientific: `1.5e-3`, `2E10`, `1e+5`
- Negative: `-3.14`, `-1e-5`

**Width specification:**
```c
scanf("%5f", &f);  // Read at most 5 characters
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== scanf() Float Input ===\n\n");
    
    float f;
    printf("Enter a float: ");
    scanf("%f", &f);
    printf("  float: %f\n", f);
    printf("  Scientific: %e\n\n", f);
    
    double d;
    printf("Enter a double: ");
    scanf("%lf", &d);
    printf("  double: %f\n", d);
    printf("  More precision: %.15f\n\n", d);
    
    long double ld;
    printf("Enter a long double: ");
    scanf("%Lf", &ld);
    printf("  long double: %Lf\n\n", ld);
    
    printf("Important: scanf uses different specifiers than printf!\n");
    printf("  float:       scanf uses %%f,  printf uses %%f\n");
    printf("  double:      scanf uses %%lf, printf uses %%f\n");
    printf("  long double: scanf uses %%Lf, printf uses %%Lf\n\n");
    
    float sci;
    printf("Enter scientific notation (e.g., 1.5e-3): ");
    scanf("%f", &sci);
    printf("  Value: %f\n", sci);
    printf("  Scientific: %e\n\n", sci);
    
    float a, b;
    printf("Enter two floats (space-separated): ");
    scanf("%f %f", &a, &b);
    printf("  Sum: %.2f + %.2f = %.2f\n\n", a, b, a + b);
    
    float x, y;
    printf("Enter coordinates (x,y): ");
    scanf("%f,%f", &x, &y);
    printf("  Point: (%.2f, %.2f)\n\n", x, y);
    
    double price;
    printf("Enter price with $ (e.g., $19.99): ");
    scanf("$%lf", &price);
    printf("  Price: $%.2f\n\n", price);
    
    printf("Float precision demonstration:\n");
    float fval;
    double dval;
    
    printf("  Enter 1.23456789012345: ");
    scanf("%f", &fval);
    printf("    As float: %.15f\n", fval);
    
    printf("  Enter 1.23456789012345: ");
    scanf("%lf", &dval);  
    printf("    As double: %.15f\n\n", dval);
    
    printf("Summary - scanf float specifiers:\n");
    printf("  %%f  - float\n");
    printf("  %%lf - double (l for long)\n");
    printf("  %%Lf - long double (L for Long)\n");
    printf("  %%e  - scientific notation (works like %%f)\n");
    printf("  %%g  - general format (works like %%f)\n");
    
    return 0;
}
```

## Output

```
=== scanf() Float Input ===

Enter a float: 3.14159
  float: 3.141590
  Scientific: 3.141590e+00

Enter a double: 3.141592653589793
  double: 3.141593
  More precision: 3.141592653589793

Enter a long double: 2.718281828
  long double: 2.718282

Important: scanf uses different specifiers than printf!
  float:       scanf uses %f,  printf uses %f
  double:      scanf uses %lf, printf uses %f
  long double: scanf uses %Lf, printf uses %Lf

Enter scientific notation (e.g., 1.5e-3): 1.5e-3
  Value: 0.001500
  Scientific: 1.500000e-03

Enter two floats (space-separated): 1.5 2.5
  Sum: 1.50 + 2.50 = 4.00

Enter coordinates (x,y): 3.5,4.2
  Point: (3.50, 4.20)

Enter price with $ (e.g., $19.99): $19.99
  Price: $19.99

Float precision demonstration:
  Enter 1.23456789012345: 1.23456789012345
    As float: 1.234567880630493
  Enter 1.23456789012345: 1.23456789012345
    As double: 1.234567890123450

Summary - scanf float specifiers:
  %f  - float
  %lf - double (l for long)
  %Lf - long double (L for Long)
  %e  - scientific notation (works like %f)
  %g  - general format (works like %f)
```

## Compilation

```bash
gcc 058-scanf-floats.c -o 058-scanf-floats
./058-scanf-floats
```

## Key Takeaways

- Use `%lf` for double in scanf (NOT `%f`)
- Use `%Lf` for long double (capital L)
- Float has ~7 significant digits, double ~15
- Scientific notation works with `%f`/`%lf`/`%e`
- Type mismatch causes silent corruption
- Always check return value in production code

## Challenge

Write a temperature converter that reads Celsius or Fahrenheit (indicated by C or F suffix) and converts to the other scale.

## Related

- [[057-scanf-integers]] — Integer input
- [[059-scanf-char-string]] — Character and string input
