---
id: "080"
title: "Operator Precedence"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "precedence", "order-of-operations"]
difficulty: "beginner"
---

# Operator Precedence

## Concept

Operator precedence determines the order in which operations are performed when multiple operators appear in an expression. C follows rules similar to mathematics (PEMDAS):

**Precedence (highest to lowest)**:
1. `()` - Parentheses (grouping)
2. `++` `--` (postfix), unary `+` `-` (prefix)
3. `*` `/` `%` - Multiplication, division, modulus
4. `+` `-` - Addition, subtraction
5. `=` `+=` `-=` etc. - Assignment (lowest)

**Associativity**: When operators have the same precedence:
- Arithmetic operators: left-to-right
- Assignment operators: right-to-left

## Code

```c
// Operator precedence (PEMDAS-like)

#include <stdio.h>

int main(void) {
    // Multiplication before addition
    printf("2 + 3 * 4 = %d\n", 2 + 3 * 4);        // 14, not 20
    printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);    // 20
    
    // Division and multiplication: left to right
    printf("20 / 4 * 2 = %d\n", 20 / 4 * 2);      // 10
    printf("20 / (4 * 2) = %d\n", 20 / (4 * 2));  // 2
    
    // Modulus same precedence as * and /
    printf("10 + 15 %% 4 = %d\n", 10 + 15 % 4);   // 13
    
    // Unary minus highest
    printf("-3 * 4 = %d\n", -3 * 4);              // -12
    
    // Complex expression
    int result = 2 + 3 * 4 - 10 / 2;
    printf("2 + 3 * 4 - 10 / 2 = %d\n", result);  // 2 + 12 - 5 = 9
    
    // When in doubt, use parentheses!
    printf("((2 + 3) * (4 - 1)) / 3 = %d\n", ((2 + 3) * (4 - 1)) / 3);
    
    return 0;
}
```

## Output

```
2 + 3 * 4 = 14
(2 + 3) * 4 = 20
20 / 4 * 2 = 10
20 / (4 * 2) = 2
10 + 15 % 4 = 13
-3 * 4 = -12
2 + 3 * 4 - 10 / 2 = 9
((2 + 3) * (4 - 1)) / 3 = 5
```

## Key Takeaways

1. `*`, `/`, `%` have higher precedence than `+`, `-`
2. Parentheses override all precedence rules
3. Same-precedence operators evaluate left-to-right (except assignment)
4. Unary operators bind tighter than binary
5. When in doubt, use parentheses for clarity

## Kata Challenge

**Expression Evaluator**

Predict the output of these expressions, then verify with code:

```c
// Your solution here
// Predict the values, then check:

int a = 2, b = 3, c = 4;

// 1. a + b * c
// 2. (a + b) * c
// 3. a * b + c * a
// 4. a + b / c
// 5. (a + b) / c
// 6. -a * b + c
// 7. a - b - c
// 8. c / b / a

// Write your predictions, then verify!
```

Extra: Write an expression that evaluates to exactly 10 using a, b, c each exactly once.
