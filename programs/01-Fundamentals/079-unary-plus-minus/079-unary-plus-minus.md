---
id: "079"
title: "Unary Plus and Minus"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "unary", "negation"]
difficulty: "beginner"
---

# Unary Plus and Minus

## Concept

Unary operators take a single operand:

- **Unary minus (`-x`)**: Negates the value (positive becomes negative, negative becomes positive)
- **Unary plus (`+x`)**: Identity operator, rarely used; can trigger integer promotion

These are different from binary subtraction and addition, which operate on two values.

**Note**: Negating the minimum signed integer value (e.g., `INT_MIN`) is undefined behavior because the positive value can't be represented.

## Code

```c
// Unary plus and minus operators

#include <stdio.h>

int main(void) {
    int a = 5;
    int b = -10;
    
    // Unary minus: negates the value
    printf("a = %d, -a = %d\n", a, -a);
    printf("b = %d, -b = %d\n", b, -b);
    
    // Unary plus: mostly identity (rarely used)
    printf("+a = %d\n", +a);
    
    // Double negation
    printf("-(-a) = %d\n", -(-a));
    
    // Useful in expressions
    int x = 3, y = 4;
    int result = -x + y;  // Not subtraction, it's negation then addition
    printf("-x + y = -%d + %d = %d\n", x, y, result);
    
    // Absolute value logic
    int neg = -42;
    int abs_val = (neg < 0) ? -neg : neg;
    printf("|%d| = %d\n", neg, abs_val);
    
    return 0;
}
```

## Output

```
a = 5, -a = -5
b = -10, -b = 10
+a = 5
-(-a) = 5
-x + y = -3 + 4 = 1
|−42| = 42
```

## Key Takeaways

1. `-x` negates: flips the sign of `x`
2. `+x` is the identity operator (almost never needed)
3. `-(-x)` returns `x` (double negation)
4. Unary operators have higher precedence than binary arithmetic
5. `-INT_MIN` is undefined behavior—be careful with edge cases

## Kata Challenge

**Sign Flipper**

Write a program that reads a number and outputs its negation. Handle the special case where negating might overflow.

```c
// Your solution here
// Test cases:
// Input: 42  → Output: -42
// Input: -7  → Output: 7
// Input: 0   → Output: 0
// Input: INT_MIN → Output: (handle overflow gracefully)

#include <limits.h>
// Hint: Check if n == INT_MIN before negating
```

Bonus: Implement your own `abs()` function that handles overflow.
