---
id: "031"
title: "Integer Literals"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - literals
  - integers
  - constants
difficulty: beginner
source: "C11 Standard Section 6.4.4.1"
---

# 031 — Integer Literals

## Concept

Integer literals are constant integer values written directly in source code. In decimal form, they consist of digits 0-9 without a leading zero. The compiler determines the type based on the value's magnitude and any suffix provided.

Key rules for integer literals:
- **Decimal literals** — digits 0-9, no leading zero (leading zero = octal!)
- **Default type** — `int`, promoted to larger types if value exceeds range
- **Type suffixes** — force specific types: `L` (long), `LL` (long long), `U` (unsigned)
- **Suffix combinations** — `UL`, `ULL`, `LU`, `LLU` for unsigned long types
- **Case insensitive** — `100L` same as `100l`, but uppercase preferred for readability

> **Why This Matters**: When working with large values, cryptographic operations, or system APIs, you need to ensure your literals have the correct type. Using `1000000000000` without `LL` suffix may overflow on 32-bit systems.

## Code

```c
#include <stdio.h>

int main(void) {
    int zero = 0;
    int positive = 42;
    int negative = -17;
    int large = 1000000;
    int with_suffix_l = 100L;
    long with_suffix_ll = 100LL;
    unsigned int with_suffix_u = 100U;
    unsigned long with_suffix_ul = 100UL;
    unsigned long long with_suffix_ull = 100ULL;
    
    printf("=== Integer Literals ===\n\n");
    
    printf("Basic decimal literals:\n");
    printf("  zero = %d\n", zero);
    printf("  positive = %d\n", positive);
    printf("  negative = %d\n", negative);
    printf("  large = %d\n", large);
    
    printf("\nLiterals with suffixes:\n");
    printf("  100L   (long)               = %ld\n", with_suffix_l);
    printf("  100LL  (long long)          = %lld\n", with_suffix_ll);
    printf("  100U   (unsigned)           = %u\n", with_suffix_u);
    printf("  100UL  (unsigned long)      = %lu\n", with_suffix_ul);
    printf("  100ULL (unsigned long long) = %llu\n", with_suffix_ull);
    
    printf("\nCombined suffixes:\n");
    printf("  42LU or 42UL = %lu\n", 42LU);
    printf("  99LLU or 99ULL = %llu\n", 99LLU);
    
    printf("\nInteger literal rules:\n");
    printf("  - No leading zeros for decimal (0 prefix = octal!)\n");
    printf("  - Suffixes are case-insensitive (L = l, U = u)\n");
    printf("  - Default type: int (or larger if needed)\n");
    
    return 0;
}
```

## Output

```
=== Integer Literals ===

Basic decimal literals:
  zero = 0
  positive = 42
  negative = -17
  large = 1000000

Literals with suffixes:
  100L   (long)               = 100
  100LL  (long long)          = 100
  100U   (unsigned)           = 100
  100UL  (unsigned long)      = 100
  100ULL (unsigned long long) = 100

Combined suffixes:
  42LU or 42UL = 42
  99LLU or 99ULL = 99

Integer literal rules:
  - No leading zeros for decimal (0 prefix = octal!)
  - Suffixes are case-insensitive (L = l, U = u)
  - Default type: int (or larger if needed)
```

## Key Takeaways

- Decimal literals are digits 0-9 without leading zeros
- Use `L` suffix for long, `LL` for long long
- Use `U` suffix for unsigned types
- Combine suffixes: `UL`, `ULL`, `LU`, `LLU`
- Negative sign `-` is actually an operator, not part of the literal
- Default type is `int` unless value is too large

## Challenge

Create a program that demonstrates the maximum values you can store with different suffixes. What happens when you assign `5000000000` to an `int` without `LL` suffix?

## Related

- [[032-octal-hex-binary-literals]] — Non-decimal integer bases
- [[011-integer-type-int]] — Integer variable types
- [[013-unsigned-integers]] — Unsigned integer types
