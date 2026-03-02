---
id: "084"
title: "Explicit Type Casting"
category: "01-Fundamentals"
tags: ["type-conversion", "casting", "explicit", "type-cast"]
difficulty: "intermediate"
---

# Explicit Type Casting

## Concept

Explicit type casting forces a conversion from one type to another using the cast operator: `(type)expression`.

**Common uses**:
- Force floating-point division: `(double)a / b`
- Truncate floating-point to integer: `(int)3.14`
- Silence compiler warnings
- Interface with APIs expecting specific types
- Pointer type conversions (advanced)

**Syntax**: `(target_type)expression`

The cast has higher precedence than arithmetic operators, so `(double)a / b` casts `a` first, then divides.

## Code

```c
// Explicit type casting

#include <stdio.h>

int main(void) {
    // Force floating-point division
    int a = 7, b = 2;
    double result = (double)a / b;
    printf("7 / 2 = %d (int), %.1f (cast)\n", a / b, result);
    
    // Truncate double to int
    double pi = 3.14159;
    int truncated = (int)pi;
    printf("%.5f truncated = %d\n", pi, truncated);
    
    // Cast for printf format
    long big = 1234567890L;
    printf("As int: %d\n", (int)big);
    
    // Cast in expressions
    int x = 5, y = 3;
    printf("Average: %.2f\n", (double)(x + y) / 2);
    
    // Multiple casts
    char c = (char)(int)3.7;
    printf("double -> int -> char: %d\n", c);
    
    return 0;
}
```

## Output

```
7 / 2 = 3 (int), 3.5 (cast)
3.14159 truncated = 3
As int: 1234567890
Average: 4.00
double -> int -> char: 3
```

## Key Takeaways

1. `(type)expression` forces conversion to the specified type
2. Cast has high precedence—use parentheses for complex expressions
3. `(double)a / b` ≠ `(double)(a / b)`—cast before division!
4. Casting can lose information (truncation, overflow)
5. Explicit casts document your intent to readers and compilers

## Kata Challenge

**Percentage Calculator**

Write a program that calculates percentages correctly using explicit casts:

```c
// Your solution here
// Input: part = 3, total = 7
// Expected output:
// Integer division: 3/7 = 0 (42%)
// Correct: 3/7 = 0.428571 (42.86%)

// The percentage should show 2 decimal places.
// Calculate both the ratio and percentage using proper casting.
```

Hint: Cast before dividing, not after!
