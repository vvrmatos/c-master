---
id: "082"
title: "Integer Promotion"
category: "01-Fundamentals"
tags: ["type-conversion", "integer-promotion", "char", "short"]
difficulty: "intermediate"
---

# Integer Promotion

## Concept

Integer promotion is a specific rule in C: types smaller than `int` (`char`, `short`, and their signed/unsigned variants) are automatically promoted to `int` in most expressions.

**Why this exists**:
- CPUs are optimized for `int`-sized operations
- Prevents overflow in intermediate calculations
- Historical compatibility

**When it happens**:
- Any arithmetic operation
- Function arguments (variadic functions)
- Unary operators like `+` and `-`

## Code

```c
// Integer promotion - char and short to int

#include <stdio.h>

int main(void) {
    char c1 = 100, c2 = 50;
    short s1 = 1000, s2 = 500;
    
    // char + char: both promoted to int first
    printf("char: %d + %d = %d\n", c1, c2, c1 + c2);
    printf("Result type size: %zu bytes\n", sizeof(c1 + c2));
    
    // short + short: promoted to int
    printf("\nshort: %d + %d = %d\n", s1, s2, s1 + s2);
    printf("Result type size: %zu bytes\n", sizeof(s1 + s2));
    
    // Even unary operations promote
    printf("\nUnary +c1 size: %zu bytes\n", sizeof(+c1));
    printf("c1 alone size: %zu bytes\n", sizeof(c1));
    
    // Prevents overflow in intermediate calculations
    char a = 200, b = 200;  // Would overflow char if not promoted
    int sum = a + b;        // Promotes to int, no overflow
    printf("\n200 + 200 = %d (promoted to int)\n", sum);
    
    return 0;
}
```

## Output

```
char: 100 + 50 = 150
Result type size: 4 bytes

short: 1000 + 500 = 1500
Result type size: 4 bytes

Unary +c1 size: 4 bytes
c1 alone size: 1 bytes

200 + 200 = 400 (promoted to int)
```

## Key Takeaways

1. `char` and `short` are promoted to `int` in expressions
2. `sizeof(char + char)` returns `sizeof(int)`, not `sizeof(char)`
3. Promotion happens before the operation is performed
4. This helps prevent overflow in intermediate calculations
5. `sizeof` on a variable doesn't promote; `sizeof` on an expression does

## Kata Challenge

**Promotion Detective**

Write a program that proves integer promotion by examining sizes:

```c
// Your solution here
// For each expression, show:
// 1. The size of each operand
// 2. The size of the result
// 3. The computed value

char a = 127, b = 127;
short c = 30000, d = 30000;

// Test: a + b
// Test: c + d
// Test: a * b
// Test: -a

// Which of these would overflow without promotion?
```

Hint: Compare `sizeof(a)` with `sizeof(a + b)`.
