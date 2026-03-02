---
id: "043"
title: "Format Specifier: %u"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - unsigned
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 043 — Format Specifier: %u

## Concept

`%u` is the format specifier for **unsigned decimal integers**. Unsigned types can only hold non-negative values but have twice the positive range of their signed counterparts.

**Unsigned format specifiers:**
| Specifier | Type | Range (typical) |
|-----------|------|-----------------|
| `%hu` | unsigned short | 0 to 65,535 |
| `%u` | unsigned int | 0 to 4,294,967,295 |
| `%lu` | unsigned long | 0 to 4,294,967,295+ |
| `%llu` | unsigned long long | 0 to 18.4×10¹⁸ |
| `%zu` | size_t | Platform-dependent |

**Key points:**
- Unsigned values **wrap around** (no overflow in traditional sense)
- `UINT_MAX + 1 = 0` (wraps to zero)
- `0 - 1 = UINT_MAX` (wraps to maximum)
- Printing a negative number with `%u` shows its unsigned interpretation

**Common uses:**
- Sizes and counts (`size_t` uses `%zu`)
- Bit manipulation
- Network protocols (port numbers, packet sizes)
- Memory addresses (often cast to unsigned)

**Warning:** Mixing signed and unsigned in comparisons can cause bugs. `-1 < 1U` is **false** because -1 is converted to a huge unsigned value.

## Code

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("=== Format Specifier: %%u (Unsigned) ===\n\n");
    
    unsigned int value = 42;
    unsigned int big = 4294967295U;
    unsigned int zero = 0;
    
    printf("Basic unsigned output:\n");
    printf("  Value: %u\n", value);
    printf("  Big: %u\n", big);
    printf("  Zero: %u\n", zero);
    
    printf("\nUnsigned integer limits:\n");
    printf("  UINT_MAX: %u\n", UINT_MAX);
    printf("  Minimum: %u\n", 0U);
    
    printf("\nDifferent unsigned sizes:\n");
    unsigned short us = 65535;
    unsigned long ul = 4294967295UL;
    unsigned long long ull = 18446744073709551615ULL;
    
    printf("  unsigned short (%%hu): %hu\n", us);
    printf("  unsigned int (%%u): %u\n", big);
    printf("  unsigned long (%%lu): %lu\n", ul);
    printf("  unsigned long long (%%llu): %llu\n", ull);
    
    printf("\nSigned vs Unsigned interpretation:\n");
    int signed_val = -1;
    unsigned int unsigned_val = (unsigned int)signed_val;
    
    printf("  Signed -1 as %%d: %d\n", signed_val);
    printf("  Signed -1 as %%u: %u\n", signed_val);
    printf("  Cast to unsigned: %u\n", unsigned_val);
    
    printf("\nBit patterns:\n");
    printf("  All bits set (0xFFFFFFFF): %u\n", 0xFFFFFFFF);
    printf("  High bit set (0x80000000): %u\n", 0x80000000);
    
    printf("\nUseful for sizes and counts:\n");
    printf("  sizeof(int) = %zu bytes\n", sizeof(int));
    printf("  sizeof(long) = %zu bytes\n", sizeof(long));
    
    return 0;
}
```

## Output

```
=== Format Specifier: %u (Unsigned) ===

Basic unsigned output:
  Value: 42
  Big: 4294967295
  Zero: 0

Unsigned integer limits:
  UINT_MAX: 4294967295
  Minimum: 0

Different unsigned sizes:
  unsigned short (%hu): 65535
  unsigned int (%u): 4294967295
  unsigned long (%lu): 4294967295
  unsigned long long (%llu): 18446744073709551615

Signed vs Unsigned interpretation:
  Signed -1 as %d: -1
  Signed -1 as %u: 4294967295
  Cast to unsigned: 4294967295

Bit patterns:
  All bits set (0xFFFFFFFF): 4294967295
  High bit set (0x80000000): 2147483648

Useful for sizes and counts:
  sizeof(int) = 4 bytes
  sizeof(long) = 8 bytes
```

## Compilation

```bash
gcc 043-format-specifier-u.c -o 043-format-specifier-u
./043-format-specifier-u
```

## Key Takeaways

- `%u` prints unsigned decimal integers
- Use `U`, `UL`, `ULL` suffixes for unsigned literals
- `%zu` is the correct specifier for `size_t` (from sizeof)
- Negative values printed with `%u` show their unsigned bit interpretation
- Unsigned wraparound is well-defined (unlike signed overflow)

## Challenge

Write a program that demonstrates unsigned wraparound by starting at 0, subtracting 1, and showing the result.

## Related

- [[042-format-specifier-d-i]] — Signed integer formats
- [[049-format-specifier-x-X-o]] — Hex and octal formats
