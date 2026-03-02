---
id: "093"
title: "Logical AND Operator"
category: "01-Fundamentals"
tags: ["logical", "operators", "and", "boolean"]
difficulty: "beginner"
---

# Logical AND Operator

## Concept

The `&&` operator performs a logical AND operation:
- Returns 1 if **both** operands are non-zero (true)
- Returns 0 if **either** operand is zero (false)

**Truth table**:
| A | B | A && B |
|---|---|--------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

**Key feature**: Short-circuit evaluation—if the first operand is false, the second is not evaluated.

## Code

```c
// Logical AND operator

#include <stdio.h>

int main(void) {
    int a = 1, b = 1, c = 0;
    
    // Basic AND
    printf("%d && %d = %d\n", a, b, a && b);
    printf("%d && %d = %d\n", a, c, a && c);
    printf("%d && %d = %d\n", c, c, c && c);
    
    // Practical use: bounds checking
    int index = 5;
    int size = 10;
    if (index >= 0 && index < size) {
        printf("\nIndex %d is valid (0 to %d)\n", index, size - 1);
    }
    
    // Multiple conditions
    int age = 25;
    int has_license = 1;
    int is_sober = 1;
    if (age >= 18 && has_license && is_sober) {
        printf("Can drive: age=%d, license=%d, sober=%d\n", 
               age, has_license, is_sober);
    }
    
    // Non-boolean values
    int x = 5, y = 10;
    printf("\n5 && 10 = %d (both non-zero = true)\n", x && y);
    printf("5 && 0 = %d\n", x && 0);
    
    return 0;
}
```

## Output

```
1 && 1 = 1
1 && 0 = 0
0 && 0 = 0

Index 5 is valid (0 to 9)
Can drive: age=25, license=1, sober=1

5 && 10 = 1 (both non-zero = true)
5 && 0 = 0
```

## Key Takeaways

1. `&&` returns 1 only if both operands are true (non-zero)
2. Short-circuits: stops at first false operand
3. Commonly used for combining multiple conditions
4. Lower precedence than relational operators
5. Evaluates left-to-right

## Kata Challenge

**Leap Year Checker**

Write a function that determines if a year is a leap year using `&&`:

```c
// Your solution here
// int is_leap_year(int year);
// A year is a leap year if:
// - Divisible by 4 AND not divisible by 100
// - OR divisible by 400

// Test cases:
// is_leap_year(2000) -> 1 (divisible by 400)
// is_leap_year(2020) -> 1 (divisible by 4, not by 100)
// is_leap_year(1900) -> 0 (divisible by 100, not 400)
// is_leap_year(2023) -> 0 (not divisible by 4)
```

Hint: Combine conditions with `&&` and `||`.
