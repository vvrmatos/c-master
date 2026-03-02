---
id: "024"
title: "Signed vs Unsigned Integers"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - signed
  - unsigned
  - integers
  - overflow
  - type-conversion
difficulty: beginner
source: "C11 Standard 6.2.5, 6.3.1.3"
---

# 024 — Signed vs Unsigned Integers

## Concept

Every integer type in C can be either **signed** (default) or **unsigned**:

```c
int x;           // signed int (default)
signed int x;    // explicitly signed
unsigned int x;  // unsigned
```

**Key differences:**

| Aspect | Signed | Unsigned |
|--------|--------|----------|
| Range | Negative to positive | 0 to positive only |
| 32-bit range | -2B to +2B | 0 to 4B |
| Overflow | Undefined behavior! | Defined (wraps around) |
| Bit pattern | Two's complement | Pure binary |

**Two's complement (signed):**
- Most significant bit is sign bit
- -1 is represented as all 1s (e.g., `11111111` for 8-bit)
- Same bit pattern can mean different values!

**Dangerous: Mixed signed/unsigned operations!**
```c
int a = -1;
unsigned int b = 1;
if (a < b)  // WRONG! -1 is converted to ~4 billion
```

**Conversion rules:**
- When mixing signed and unsigned, signed converts to unsigned
- -1 becomes UINT_MAX (all bits set to 1)
- This causes subtle bugs in comparisons

**Type modifiers:**
```c
signed char sc;      // -128 to 127
unsigned char uc;    // 0 to 255
signed short ss;     // -32768 to 32767
unsigned short us;   // 0 to 65535
unsigned long ul;    // Large positive range
```

## Code

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("=== Signed vs Unsigned Integers ===\n\n");
    
    printf("--- Range Differences ---\n");
    printf("signed char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("\nsigned int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:  0 to %u\n", UINT_MAX);
    
    printf("\n--- Bit Representation (8-bit example) ---\n");
    signed char sc = -1;
    unsigned char uc = 255;
    printf("signed char -1 as bits:   11111111 (two's complement)\n");
    printf("unsigned char 255 as bits: 11111111 (same bits!)\n");
    printf("Same bit pattern, different interpretation!\n");
    
    printf("\n--- Overflow Behavior ---\n");
    unsigned int u = UINT_MAX;
    printf("unsigned int at max: %u\n", u);
    u = u + 1;
    printf("After adding 1:      %u (wraps to 0 - defined behavior)\n", u);
    
    printf("\n--- Mixed Comparisons (Dangerous!) ---\n");
    int signed_val = -1;
    unsigned int unsigned_val = 1;
    
    printf("signed_val = %d, unsigned_val = %u\n", signed_val, unsigned_val);
    printf("Is -1 < 1? Mathematically: yes\n");
    
    if (signed_val < unsigned_val) {
        printf("Comparison result: -1 < 1 (correct)\n");
    } else {
        printf("Comparison result: -1 >= 1 (WRONG! -1 converted to large unsigned)\n");
    }
    
    printf("\n--- Safe Pattern ---\n");
    int a = -5;
    unsigned int b = 10;
    if (a < 0 || (unsigned int)a < b) {
        printf("Properly handled: %d is less than %u\n", a, b);
    }
    
    printf("\n--- Common Use Cases ---\n");
    printf("Use signed for: general arithmetic, loop counters that might go negative\n");
    printf("Use unsigned for: bit manipulation, array indices, sizes, flags\n");
    
    return 0;
}
```

## Output

```
=== Signed vs Unsigned Integers ===

--- Range Differences ---
signed char:   -128 to 127
unsigned char: 0 to 255

signed int:    -2147483648 to 2147483647
unsigned int:  0 to 4294967295

--- Bit Representation (8-bit example) ---
signed char -1 as bits:   11111111 (two's complement)
unsigned char 255 as bits: 11111111 (same bits!)
Same bit pattern, different interpretation!

--- Overflow Behavior ---
unsigned int at max: 4294967295
After adding 1:      0 (wraps to 0 - defined behavior)

--- Mixed Comparisons (Dangerous!) ---
signed_val = -1, unsigned_val = 1
Is -1 < 1? Mathematically: yes
Comparison result: -1 >= 1 (WRONG! -1 converted to large unsigned)

--- Safe Pattern ---
Properly handled: -5 is less than 10

--- Common Use Cases ---
Use signed for: general arithmetic, loop counters that might go negative
Use unsigned for: bit manipulation, array indices, sizes, flags
```

## Key Takeaways

- Signed types can hold negative values; unsigned cannot
- Same bit pattern has different meanings for signed vs unsigned
- **Signed overflow is undefined behavior** — compiler can do anything
- Unsigned overflow is defined — wraps around (modulo 2^n)
- Never compare signed with unsigned directly
- Use `-Wall -Wextra` compiler flags to catch mixed comparisons
- Prefer `size_t` (unsigned) for sizes and array indices

## Challenge

Write a program that demonstrates the "billion laughs" bug: a loop using `unsigned int i` counting down with condition `i >= 0`. Why does this loop never terminate? Fix it properly.

## Related

- [[013-unsigned-integers]] — Unsigned basics
- [[022-integer-limits]] — Limit constants
- [[012-integer-variants]] — Integer types
- [[025-const-qualifier]] — Type qualifiers
