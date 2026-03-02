---
id: "042"
title: "Format Specifiers: %d and %i"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - integers
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 042 — Format Specifiers: %d and %i

## Concept

`%d` and `%i` are format specifiers for **signed decimal integers**. In `printf()`, they are completely identical. The difference only matters with `scanf()` (where `%i` can auto-detect base).

**Length modifiers for integers:**
| Modifier | Type | Example |
|----------|------|---------|
| `%hd` | short | `printf("%hd", (short)123)` |
| `%d` | int | `printf("%d", 123)` |
| `%ld` | long | `printf("%ld", 123L)` |
| `%lld` | long long | `printf("%lld", 123LL)` |

**When to use each:**
- `%d` — default choice for integers, most common
- `%hd` — when explicitly printing short integers
- `%ld` — for long integers (use `L` suffix on literals)
- `%lld` — for long long integers (use `LL` suffix)

**Important:** Mismatching types causes undefined behavior. If you have a `long`, use `%ld`, not `%d`.

**Integer ranges (typical 64-bit system):**
| Type | Range |
|------|-------|
| short | -32,768 to 32,767 |
| int | -2,147,483,648 to 2,147,483,647 |
| long | same as int or larger |
| long long | -9.2×10¹⁸ to 9.2×10¹⁸ |

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Format Specifiers: %%d and %%i ===\n\n");
    
    int positive = 42;
    int negative = -17;
    int zero = 0;
    
    printf("Using %%d (decimal):\n");
    printf("  Positive: %d\n", positive);
    printf("  Negative: %d\n", negative);
    printf("  Zero: %d\n", zero);
    
    printf("\nUsing %%i (integer):\n");
    printf("  Positive: %i\n", positive);
    printf("  Negative: %i\n", negative);
    printf("  Zero: %i\n", zero);
    
    printf("\n%%d and %%i are identical for printf:\n");
    printf("  %%d: %d, %%i: %i\n", 12345, 12345);
    
    short small = 32767;
    long big = 2147483647L;
    long long huge = 9223372036854775807LL;
    
    printf("\nDifferent integer sizes:\n");
    printf("  short (%%hd): %hd\n", small);
    printf("  int (%%d): %d\n", positive);
    printf("  long (%%ld): %ld\n", big);
    printf("  long long (%%lld): %lld\n", huge);
    
    printf("\nInteger limits demonstration:\n");
    printf("  Max int: %d\n", 2147483647);
    printf("  Min int: %d\n", -2147483648);
    
    printf("\nArithmetic in printf arguments:\n");
    int a = 10, b = 3;
    printf("  %d + %d = %d\n", a, b, a + b);
    printf("  %d - %d = %d\n", a, b, a - b);
    printf("  %d * %d = %d\n", a, b, a * b);
    printf("  %d / %d = %d\n", a, b, a / b);
    printf("  %d %% %d = %d\n", a, b, a % b);
    
    return 0;
}
```

## Output

```
=== Format Specifiers: %d and %i ===

Using %d (decimal):
  Positive: 42
  Negative: -17
  Zero: 0

Using %i (integer):
  Positive: 42
  Negative: -17
  Zero: 0

%d and %i are identical for printf:
  %d: 12345, %i: 12345

Different integer sizes:
  short (%hd): 32767
  int (%d): 42
  long (%ld): 2147483647
  long long (%lld): 9223372036854775807

Integer limits demonstration:
  Max int: 2147483647
  Min int: -2147483648

Arithmetic in printf arguments:
  10 + 3 = 13
  10 - 3 = 7
  10 * 3 = 30
  10 / 3 = 3
  10 % 3 = 1
```

## Compilation

```bash
gcc 042-format-specifier-d-i.c -o 042-format-specifier-d-i
./042-format-specifier-d-i
```

## Key Takeaways

- `%d` and `%i` are interchangeable in `printf()` for signed integers
- Use length modifiers (`h`, `l`, `ll`) to match variable types
- Type mismatches cause undefined behavior
- Integer division truncates toward zero
- Use `%%` to print a literal percent sign

## Challenge

Write a program that demonstrates integer overflow by printing values near INT_MAX and showing what happens when you add 1.

## Related

- [[043-format-specifier-u]] — Unsigned integer format
- [[051-field-width]] — Controlling output width
