---
id: "022"
title: "Integer Limits (limits.h)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - limits
  - integers
  - overflow
  - data-types
difficulty: beginner
source: "C11 Standard 5.2.4.2.1, limits.h"
---

# 022 — Integer Limits (limits.h)

## Concept

The `<limits.h>` header defines constants for the limits of integer types. These are essential for:

- Preventing overflow
- Writing portable code
- Input validation
- Algorithm boundary checks

**Key constants:**

| Constant | Meaning | Typical Value |
|----------|---------|---------------|
| `CHAR_BIT` | Bits per byte | 8 |
| `CHAR_MIN` | Min char | 0 or -128 |
| `CHAR_MAX` | Max char | 127 or 255 |
| `SCHAR_MIN/MAX` | Signed char | -128 / 127 |
| `UCHAR_MAX` | Unsigned char | 255 |
| `SHRT_MIN/MAX` | Short | -32768 / 32767 |
| `USHRT_MAX` | Unsigned short | 65535 |
| `INT_MIN/MAX` | Int | -2147483648 / 2147483647 |
| `UINT_MAX` | Unsigned int | 4294967295 |
| `LONG_MIN/MAX` | Long | Platform-dependent |
| `LLONG_MIN/MAX` | Long long | ±9223372036854775807 |

**Overflow prevention pattern:**
```c
// Check BEFORE adding to prevent overflow
if (b <= INT_MAX - a) {
    result = a + b;  // Safe
}
```

**Naming convention:**
- `XXX_MIN` — minimum value (signed types only)
- `XXX_MAX` — maximum value
- `UXXX_MAX` — maximum for unsigned variant

## Code

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("=== Integer Limits (limits.h) ===\n\n");
    
    printf("Bits in a char: CHAR_BIT = %d\n\n", CHAR_BIT);
    
    printf("char limits:\n");
    printf("  CHAR_MIN  = %d\n", CHAR_MIN);
    printf("  CHAR_MAX  = %d\n", CHAR_MAX);
    printf("  SCHAR_MIN = %d\n", SCHAR_MIN);
    printf("  SCHAR_MAX = %d\n", SCHAR_MAX);
    printf("  UCHAR_MAX = %u\n", UCHAR_MAX);
    
    printf("\nshort limits:\n");
    printf("  SHRT_MIN  = %d\n", SHRT_MIN);
    printf("  SHRT_MAX  = %d\n", SHRT_MAX);
    printf("  USHRT_MAX = %u\n", USHRT_MAX);
    
    printf("\nint limits:\n");
    printf("  INT_MIN   = %d\n", INT_MIN);
    printf("  INT_MAX   = %d\n", INT_MAX);
    printf("  UINT_MAX  = %u\n", UINT_MAX);
    
    printf("\nlong limits:\n");
    printf("  LONG_MIN  = %ld\n", LONG_MIN);
    printf("  LONG_MAX  = %ld\n", LONG_MAX);
    printf("  ULONG_MAX = %lu\n", ULONG_MAX);
    
    printf("\nlong long limits:\n");
    printf("  LLONG_MIN  = %lld\n", LLONG_MIN);
    printf("  LLONG_MAX  = %lld\n", LLONG_MAX);
    printf("  ULLONG_MAX = %llu\n", ULLONG_MAX);
    
    printf("\n--- Practical Uses ---\n");
    
    int value = 2000000000;
    if (value > INT_MAX / 2) {
        printf("\nWarning: value is more than half of INT_MAX\n");
        printf("Adding another %d might overflow!\n", value);
    }
    
    printf("\nCalculating if addition would overflow:\n");
    int a = INT_MAX - 10;
    int b = 5;
    if (b <= INT_MAX - a) {
        printf("  %d + %d = %d (safe)\n", a, b, a + b);
    }
    
    return 0;
}
```

## Output

```
=== Integer Limits (limits.h) ===

Bits in a char: CHAR_BIT = 8

char limits:
  CHAR_MIN  = -128
  CHAR_MAX  = 127
  SCHAR_MIN = -128
  SCHAR_MAX = 127
  UCHAR_MAX = 255

short limits:
  SHRT_MIN  = -32768
  SHRT_MAX  = 32767
  USHRT_MAX = 65535

int limits:
  INT_MIN   = -2147483648
  INT_MAX   = 2147483647
  UINT_MAX  = 4294967295

long limits:
  LONG_MIN  = -9223372036854775808
  LONG_MAX  = 9223372036854775807
  ULONG_MAX = 18446744073709551615

long long limits:
  LLONG_MIN  = -9223372036854775808
  LLONG_MAX  = 9223372036854775807
  ULLONG_MAX = 18446744073709551615

--- Practical Uses ---

Warning: value is more than half of INT_MAX
Adding another 2000000000 might overflow!

Calculating if addition would overflow:
  2147483637 + 5 = 2147483642 (safe)
```

## Key Takeaways

- `<limits.h>` provides portable limit constants
- Always check limits before operations that might overflow
- `CHAR_BIT` tells you bits per byte (usually 8)
- Plain `char` signedness is implementation-defined (CHAR_MIN may be 0 or -128)
- Use these constants instead of magic numbers like 2147483647
- Signed integer overflow is undefined behavior — check first!

## Challenge

Write a function `safe_add(int a, int b, int *result)` that returns 1 on success, 0 if overflow would occur. Use `INT_MIN` and `INT_MAX` to check both positive and negative overflow.

## Related

- [[021-sizeof-operator]] — Checking type sizes
- [[023-float-limits]] — Floating point limits
- [[013-unsigned-integers]] — Unsigned types
- [[024-signed-vs-unsigned]] — Signed vs unsigned
