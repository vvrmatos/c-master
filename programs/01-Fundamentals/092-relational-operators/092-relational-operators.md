---
id: "092"
title: "Relational Operators"
category: "01-Fundamentals"
tags: ["comparison", "operators", "relational", "less-than", "greater-than"]
difficulty: "beginner"
---

# Relational Operators

## Concept

Relational operators compare the relative ordering of two values:

| Operator | Meaning |
|----------|---------|
| `<`  | Less than |
| `>`  | Greater than |
| `<=` | Less than or equal to |
| `>=` | Greater than or equal to |

All return 1 (true) or 0 (false).

**Warning**: Chaining comparisons doesn't work in C!
- `1 < x < 10` is parsed as `(1 < x) < 10`
- The result of `1 < x` is 0 or 1, which is always `< 10`
- Use `1 < x && x < 10` instead

## Code

```c
// Relational operators < > <= >=

#include <stdio.h>

int main(void) {
    int a = 5, b = 10;
    
    // Less than
    printf("%d < %d is %d\n", a, b, a < b);
    printf("%d < %d is %d\n", b, a, b < a);
    
    // Greater than
    printf("%d > %d is %d\n", a, b, a > b);
    printf("%d > %d is %d\n", b, a, b > a);
    
    // Less than or equal
    printf("%d <= %d is %d\n", a, b, a <= b);
    printf("%d <= %d is %d\n", a, a, a <= a);
    
    // Greater than or equal
    printf("%d >= %d is %d\n", a, b, a >= b);
    printf("%d >= %d is %d\n", a, a, a >= a);
    
    // Chaining doesn't work as expected!
    int x = 5;
    printf("\n1 < 5 < 10? (1 < %d < 10)\n", x);
    printf("Mathematical: true\n");
    printf("C expression: %d (wrong!)\n", 1 < x < 10);
    printf("Correct in C: %d\n", 1 < x && x < 10);
    
    return 0;
}
```

## Output

```
5 < 10 is 1
10 < 5 is 0
5 > 10 is 0
10 > 5 is 1
5 <= 10 is 1
5 <= 5 is 1
5 >= 10 is 0
5 >= 5 is 1

1 < 5 < 10? (1 < 5 < 10)
Mathematical: true
C expression: 1 (wrong!)
Correct in C: 1
```

## Key Takeaways

1. Relational operators return 1 (true) or 0 (false)
2. `<=` and `>=` include equality
3. Cannot chain comparisons: use `&&` for ranges
4. These have lower precedence than arithmetic operators
5. Compare same types to avoid implicit conversion surprises

## Kata Challenge

**Range Checker**

Write a function that checks if a value is within a range (inclusive):

```c
// Your solution here
// int in_range(int value, int min, int max);
// Returns 1 if min <= value <= max, 0 otherwise

// Test cases:
// in_range(5, 1, 10)   -> 1
// in_range(1, 1, 10)   -> 1 (boundary)
// in_range(10, 1, 10)  -> 1 (boundary)
// in_range(0, 1, 10)   -> 0
// in_range(11, 1, 10)  -> 0
```

Bonus: Write `in_range_exclusive` that excludes the boundaries.
