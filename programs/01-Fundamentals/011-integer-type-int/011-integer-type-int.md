---
id: "011"
title: "Integer Type (int)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - int
  - data-types
  - integers
difficulty: beginner
source: "C11 Standard 6.2.5, K&R Chapter 2"
---

# 011 — Integer Type (int)

## Concept

`int` is the **workhorse integer type** in C. It represents whole numbers (positive, negative, or zero) and is designed to be the "natural" size for the target machine.

**Key characteristics:**
- Stores whole numbers only (no decimals)
- Typically 4 bytes (32 bits) on modern systems
- Range: usually -2,147,483,648 to 2,147,483,647
- Default type for integer literals like `42`

**Declaration and initialization:**
```c
int x;          // Declaration (value undefined!)
int y = 10;     // Declaration with initialization
int a, b, c;    // Multiple declarations
int m = 1, n = 2;  // Multiple with initialization
```

**The size of `int` is platform-dependent:**
- C only guarantees `int` is at least 16 bits
- On most modern systems: 32 bits (4 bytes)
- Use `sizeof(int)` to check on your system

**Format specifier:** `%d` or `%i` for printf/scanf

**Why `int` matters for security:**
- Integer overflow can cause vulnerabilities
- Buffer size calculations often use `int`
- Array indices are typically `int`

## Code

```c
#include <stdio.h>

int main(void) {
    int x = 42;
    int negative = -100;
    int zero = 0;
    
    printf("=== Integer Type (int) ===\n\n");
    
    printf("int x = %d\n", x);
    printf("int negative = %d\n", negative);
    printf("int zero = %d\n", zero);
    
    printf("\nSize of int: %zu bytes\n", sizeof(int));
    printf("Size of x: %zu bytes\n", sizeof(x));
    
    int a = 10, b = 3;
    printf("\nInteger arithmetic:\n");
    printf("  %d + %d = %d\n", a, b, a + b);
    printf("  %d - %d = %d\n", a, b, a - b);
    printf("  %d * %d = %d\n", a, b, a * b);
    printf("  %d / %d = %d (truncated)\n", a, b, a / b);
    printf("  %d %% %d = %d (remainder)\n", a, b, a % b);
    
    return 0;
}
```

## Output

```
=== Integer Type (int) ===

int x = 42
int negative = -100
int zero = 0

Size of int: 4 bytes
Size of x: 4 bytes

Integer arithmetic:
  10 + 3 = 13
  10 - 3 = 7
  10 * 3 = 30
  10 / 3 = 3 (truncated)
  10 % 3 = 1 (remainder)
```

## Key Takeaways

- `int` is the default integer type in C
- Usually 4 bytes (32 bits) on modern systems
- Use `%d` to print integers with printf
- Integer division truncates (drops decimal part)
- `%` gives the remainder (modulus)
- Uninitialized `int` has undefined value — always initialize!

## Challenge

What happens when you try to store a number larger than INT_MAX (2,147,483,647) in an `int`? Try it and observe the overflow behavior.

## Related

- [[012-integer-variants]] — short, long, long long
- [[013-unsigned-integers]] — unsigned int
- [[021-sizeof-operator]] — Checking sizes
- [[022-integer-limits]] — INT_MAX, INT_MIN
