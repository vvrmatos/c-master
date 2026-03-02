---
id: "057"
title: "scanf() Integer Input"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - scanf
  - input
  - integers
difficulty: beginner
source: "C11 Standard 7.21.6.2"
---

# 057 — scanf() Integer Input

## Concept

scanf provides multiple specifiers for reading integers of different sizes and bases.

**Integer format specifiers:**
| Specifier | Type | Base |
|-----------|------|------|
| `%d` | int | Decimal |
| `%i` | int | Auto-detect (0x=hex, 0=octal) |
| `%u` | unsigned int | Decimal |
| `%x` | unsigned int | Hexadecimal |
| `%o` | unsigned int | Octal |

**Size modifiers:**
| Specifier | Type |
|-----------|------|
| `%hd` | short |
| `%d` | int |
| `%ld` | long |
| `%lld` | long long |

**Important: %d vs %i for scanf:**
- `%d` always reads decimal
- `%i` auto-detects base:
  - `0x` prefix → hexadecimal
  - `0` prefix → octal
  - Otherwise → decimal

This differs from printf where they're identical!

**Reading with delimiters:**
```c
scanf("%d,%d", &x, &y);  // Expects input like "10,20"
scanf("%d/%d/%d", &m, &d, &y); // For dates like "12/25/2024"
```

**Width limitation:**
```c
scanf("%5d", &x);  // Read at most 5 digits
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== scanf() Integer Input ===\n\n");
    
    int decimal;
    printf("Enter a decimal integer: ");
    scanf("%d", &decimal);
    printf("  Decimal: %d\n", decimal);
    printf("  Hex: 0x%x\n", decimal);
    printf("  Octal: %o\n\n", decimal);
    
    printf("%%d vs %%i difference:\n");
    int num;
    printf("Enter a number (try 0x1A or 032): ");
    scanf("%i", &num);
    printf("  %%i interpreted: %d\n", num);
    printf("  (%%i auto-detects base from prefix)\n\n");
    
    short small;
    printf("Enter a small number (-32768 to 32767): ");
    scanf("%hd", &small);
    printf("  short value: %hd\n\n", small);
    
    long big;
    printf("Enter a large number: ");
    scanf("%ld", &big);
    printf("  long value: %ld\n\n", big);
    
    long long huge;
    printf("Enter a huge number: ");
    scanf("%lld", &huge);
    printf("  long long value: %lld\n\n", huge);
    
    unsigned int pos;
    printf("Enter a positive number: ");
    scanf("%u", &pos);
    printf("  unsigned value: %u\n\n", pos);
    
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("  Got: %d, %d, %d\n", a, b, c);
    printf("  Sum: %d\n\n", a + b + c);
    
    int x, y;
    printf("Enter two integers with comma (x,y): ");
    scanf("%d,%d", &x, &y);
    printf("  Got: x=%d, y=%d\n\n", x, y);
    
    unsigned int hex;
    printf("Enter a hex value (like ff or FF): ");
    scanf("%x", &hex);
    printf("  Decimal: %u\n", hex);
    printf("  Hex: 0x%x\n\n", hex);
    
    unsigned int octal;
    printf("Enter an octal value (like 755): ");
    scanf("%o", &octal);
    printf("  Decimal: %u\n", octal);
    printf("  Octal: %o\n\n", octal);
    
    printf("Integer format specifier summary:\n");
    printf("  %%d  - decimal (signed int)\n");
    printf("  %%i  - integer with auto base detection\n");
    printf("  %%u  - unsigned decimal\n");
    printf("  %%x  - hexadecimal\n");
    printf("  %%o  - octal\n");
    printf("  %%hd - short\n");
    printf("  %%ld - long\n");
    printf("  %%lld - long long\n");
    
    return 0;
}
```

## Output

```
=== scanf() Integer Input ===

Enter a decimal integer: 255
  Decimal: 255
  Hex: 0xff
  Octal: 377

%d vs %i difference:
Enter a number (try 0x1A or 032): 0x1A
  %i interpreted: 26
  (%i auto-detects base from prefix)

Enter a small number (-32768 to 32767): 1000
  short value: 1000

Enter a large number: 2147483647
  long value: 2147483647

Enter a huge number: 9223372036854775807
  long long value: 9223372036854775807

Enter a positive number: 4294967295
  unsigned value: 4294967295

Enter three integers: 10 20 30
  Got: 10, 20, 30
  Sum: 60

Enter two integers with comma (x,y): 100,200
  Got: x=100, y=200

Enter a hex value (like ff or FF): ff
  Decimal: 255
  Hex: 0xff

Enter an octal value (like 755): 755
  Decimal: 493
  Octal: 755

Integer format specifier summary:
  %d  - decimal (signed int)
  %i  - integer with auto base detection
  %u  - unsigned decimal
  %x  - hexadecimal
  %o  - octal
  %hd - short
  %ld - long
  %lld - long long
```

## Compilation

```bash
gcc 057-scanf-integers.c -o 057-scanf-integers
./057-scanf-integers
```

## Key Takeaways

- `%d` reads decimal, `%i` auto-detects base
- Use proper length modifiers: `%hd`, `%ld`, `%lld`
- `%x` reads hex input (no 0x prefix needed)
- `%o` reads octal input
- Include literal characters for formatted input: `%d,%d`
- Always match specifier to variable type

## Challenge

Write a program that reads RGB color values in hex (like FF8800) and converts them to decimal components.

## Related

- [[056-scanf-basics]] — scanf fundamentals
- [[058-scanf-floats]] — Reading floating-point values
