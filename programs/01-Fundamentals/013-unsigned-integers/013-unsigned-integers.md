---
id: "013"
title: "Unsigned Integers"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - unsigned
  - data-types
  - integers
difficulty: beginner
source: "C11 Standard 6.2.5"
---

# 013 — Unsigned Integers

## Concept

**Unsigned** integers can only hold non-negative values (0 and positive). By not storing negative numbers, they can hold larger positive values in the same space.

**Comparison (32-bit):**
| Type | Range |
|------|-------|
| `signed int` | -2,147,483,648 to 2,147,483,647 |
| `unsigned int` | 0 to 4,294,967,295 |

**Declaration:**
```c
unsigned int u = 100;
unsigned short us = 50;
unsigned long ul = 1000;
unsigned long long ull = 10000;
unsigned char uc = 255;     // Often used for bytes
```

**Literal suffixes:**
- `U` or `u`: unsigned
- `UL` or `ul`: unsigned long
- `ULL` or `ull`: unsigned long long

**Format specifiers:**
- `%u`: unsigned int
- `%hu`: unsigned short
- `%lu`: unsigned long
- `%llu`: unsigned long long

**DANGER — Unsigned underflow:**
```c
unsigned int x = 0;
x = x - 1;  // Wraps to 4,294,967,295!
```

**When to use unsigned:**
- Bit manipulation
- Array sizes and indices
- Values that can never be negative
- Binary data (bytes)

**Security note:** Many buffer overflow vulnerabilities involve signed/unsigned confusion, especially in size calculations.

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned int u = 4294967295U;
    unsigned short us = 65535;
    unsigned long ul = 4294967295UL;
    unsigned long long ull = 18446744073709551615ULL;
    
    printf("=== Unsigned Integers ===\n\n");
    
    printf("unsigned int u = %u\n", u);
    printf("unsigned short us = %hu\n", us);
    printf("unsigned long ul = %lu\n", ul);
    printf("unsigned long long ull = %llu\n", ull);
    
    printf("\nSigned vs Unsigned ranges (assuming 32-bit int):\n");
    printf("  signed int:   -2,147,483,648 to 2,147,483,647\n");
    printf("  unsigned int: 0 to 4,294,967,295\n");
    
    unsigned int x = 0;
    printf("\nDanger! Underflow:\n");
    printf("  unsigned int x = 0\n");
    printf("  x - 1 = %u (wraps around!)\n", x - 1);
    
    return 0;
}
```

## Output

```
=== Unsigned Integers ===

unsigned int u = 4294967295
unsigned short us = 65535
unsigned long ul = 4294967295
unsigned long long ull = 18446744073709551615

Signed vs Unsigned ranges (assuming 32-bit int):
  signed int:   -2,147,483,648 to 2,147,483,647
  unsigned int: 0 to 4,294,967,295

Danger! Underflow:
  unsigned int x = 0
  x - 1 = 4294967295 (wraps around!)
```

## Key Takeaways

- `unsigned` types only hold non-negative values
- Double the positive range compared to signed
- Underflow wraps around (no negative numbers!)
- Use `U`, `UL`, `ULL` suffixes for literals
- Use `%u`, `%lu`, `%llu` format specifiers
- Be careful mixing signed and unsigned in comparisons
- Common source of security vulnerabilities

## Challenge

What happens when you compare `-1` with an unsigned int? Try: `if (-1 < 1U)` — the result may surprise you! (Hint: -1 gets converted to unsigned)

## Related

- [[011-integer-type-int]] — Signed int
- [[012-integer-variants]] — Size variants
- [[086-signed-unsigned-conversion]] — Conversion dangers
