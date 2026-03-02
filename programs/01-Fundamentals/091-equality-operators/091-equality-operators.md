---
id: "091"
title: "Equality Operators"
category: "01-Fundamentals"
tags: ["comparison", "operators", "equality", "relational"]
difficulty: "beginner"
---

# Equality Operators

## Concept

Equality operators compare two values and return 1 (true) or 0 (false):

- `==` : Equal to (returns 1 if operands are equal)
- `!=` : Not equal to (returns 1 if operands are different)

**Important distinctions**:
- `==` is comparison, `=` is assignment (common mistake!)
- Floating-point comparisons can be unreliable due to precision
- Characters are compared by their ASCII values

## Code

```c
// Equality operators == and !=

#include <stdio.h>

int main(void) {
    int a = 5, b = 5, c = 10;
    
    // Equality check
    printf("%d == %d is %d\n", a, b, a == b);
    printf("%d == %d is %d\n", a, c, a == c);
    
    // Inequality check
    printf("%d != %d is %d\n", a, b, a != b);
    printf("%d != %d is %d\n", a, c, a != c);
    
    // With characters
    char ch = 'A';
    printf("'%c' == 'A' is %d\n", ch, ch == 'A');
    printf("'%c' == 'B' is %d\n", ch, ch == 'B');
    
    // With floating point (be careful!)
    double x = 0.1 + 0.2;
    printf("\n0.1 + 0.2 == 0.3 is %d\n", x == 0.3);
    printf("Actual value: %.17f\n", x);
    
    return 0;
}
```

## Output

```
5 == 5 is 1
5 == 10 is 0
5 != 5 is 0
5 != 10 is 1
'A' == 'A' is 1
'A' == 'B' is 0

0.1 + 0.2 == 0.3 is 0
Actual value: 0.30000000000000004
```

## Key Takeaways

1. `==` returns 1 for true, 0 for false
2. `!=` is the logical inverse of `==`
3. Don't confuse `==` (comparison) with `=` (assignment)
4. Floating-point equality is unreliable—use epsilon comparison
5. Characters are compared by their numeric (ASCII) values

## Kata Challenge

**Float Comparison Function**

Write a function that safely compares floating-point numbers using an epsilon tolerance:

```c
// Your solution here
// int float_equal(double a, double b, double epsilon);
// Returns 1 if |a - b| < epsilon, 0 otherwise

// Test cases:
// float_equal(0.1 + 0.2, 0.3, 0.0001) -> 1 (equal within tolerance)
// float_equal(1.0, 1.001, 0.0001)      -> 0 (not equal)
// float_equal(1.0, 1.00001, 0.0001)    -> 1 (equal within tolerance)
```

Hint: Use `fabs()` from `<math.h>` for absolute difference.
