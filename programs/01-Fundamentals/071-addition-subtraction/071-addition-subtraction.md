---
id: "071"
title: "Addition and Subtraction Operators"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "addition", "subtraction", "math"]
difficulty: "beginner"
---

# Addition and Subtraction Operators

## Concept

The `+` and `-` operators are binary arithmetic operators that perform addition and subtraction on two operands. They work with all numeric types including integers and floating-point numbers.

- **Addition (+)**: Adds two values together
- **Subtraction (-)**: Subtracts the right operand from the left operand

Both operators have left-to-right associativity and the same precedence level.

## Code

```c
// Addition and subtraction operators

#include <stdio.h>

int main(void) {
    int a = 15, b = 7;
    
    int sum = a + b;
    int diff = a - b;
    
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, diff);
    
    double x = 3.5, y = 1.2;
    printf("%.1f + %.1f = %.1f\n", x, y, x + y);
    printf("%.1f - %.1f = %.1f\n", x, y, x - y);
    
    return 0;
}
```

## Output

```
15 + 7 = 22
15 - 7 = 8
3.5 + 1.2 = 4.7
3.5 - 1.2 = 2.3
```

## Key Takeaways

1. `+` and `-` work with integers and floating-point types
2. The result type matches the operand types (int + int = int, double + double = double)
3. Mixed types undergo implicit conversion (covered later)
4. Integer overflow can occur with large values
5. Left-to-right associativity: `a - b - c` means `(a - b) - c`

## Kata Challenge

**Sum of Range**

Write a program that calculates the sum of all integers from a starting number to an ending number (inclusive). Also calculate how many numbers are in that range.

```c
// Your solution here
// Input: start = 5, end = 10
// Expected output:
// Sum from 5 to 10 = 45
// Count: 6 numbers
```

Hint: You can solve this with a loop, or use the formula: `sum = (n * (first + last)) / 2`
