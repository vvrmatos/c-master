---
id: "073"
title: "Division Operator"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "division", "integer-division", "float-division"]
difficulty: "beginner"
---

# Division Operator

## Concept

The `/` operator divides the left operand by the right operand. Its behavior depends critically on the operand types:

- **Integer division**: Both operands are integers → result is integer (truncated)
- **Floating-point division**: At least one operand is float/double → result is floating-point

This distinction is one of the most common sources of bugs for C beginners.

**Warning**: Division by zero is undefined behavior for integers and produces infinity/NaN for floats.

## Code

```c
// Division operator - int vs float

#include <stdio.h>

int main(void) {
    // Integer division
    int a = 17, b = 5;
    printf("%d / %d = %d\n", a, b, a / b);
    
    // Floating-point division
    double x = 17.0, y = 5.0;
    printf("%.1f / %.1f = %.1f\n", x, y, x / y);
    
    // Mixed: int and double
    printf("%d / %.1f = %.1f\n", a, y, a / y);
    
    // Force float division from integers
    printf("%d / %d = %.1f (cast)\n", a, b, (double)a / b);
    
    return 0;
}
```

## Output

```
17 / 5 = 3
17.0 / 5.0 = 3.4
17 / 5.0 = 3.4
17 / 5 = 3.4 (cast)
```

## Key Takeaways

1. Integer `/` integer = integer (truncated toward zero)
2. Any float operand makes the result float
3. Cast at least one operand to get decimal result: `(double)a / b`
4. Division by zero: undefined for int, infinity for float
5. Same precedence as multiplication, higher than addition

## Kata Challenge

**Average Calculator**

Write a program that calculates the average of three integers. Make sure you get the correct decimal result!

```c
// Your solution here
// Input: a = 10, b = 20, c = 25
// Expected output:
// Average of 10, 20, 25 = 18.333333

// Common mistake to avoid: (a + b + c) / 3 gives wrong answer. Why?
```

Hint: Think about what type the division needs to produce a decimal result.
