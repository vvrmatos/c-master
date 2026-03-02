---
id: "072"
title: "Multiplication Operator"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "multiplication", "math"]
difficulty: "beginner"
---

# Multiplication Operator

## Concept

The `*` operator multiplies two operands together. It works with all numeric types and has higher precedence than addition and subtraction.

Key points:
- Binary operator requiring two operands
- Commutative: `a * b` equals `b * a`
- Associative: `(a * b) * c` equals `a * (b * c)`
- Integer multiplication can overflow silently
- Mixed types are promoted to the wider type

## Code

```c
// Multiplication operator

#include <stdio.h>

int main(void) {
    int a = 6, b = 7;
    int product = a * b;
    
    printf("%d * %d = %d\n", a, b, product);
    
    double price = 19.99;
    int quantity = 3;
    printf("Total: $%.2f\n", price * quantity);
    
    // Chained multiplication
    printf("2 * 3 * 4 = %d\n", 2 * 3 * 4);
    
    return 0;
}
```

## Output

```
6 * 7 = 42
Total: $59.97
2 * 3 * 4 = 24
```

## Key Takeaways

1. `*` has higher precedence than `+` and `-`
2. Integer overflow is undefined behavior—use larger types for big numbers
3. When mixing int and double, result is double
4. Multiplication is evaluated left-to-right
5. Consider using `long long` for large integer products

## Kata Challenge

**Factorial Calculator**

Write a program that calculates the factorial of a number (n! = 1 × 2 × 3 × ... × n).

```c
// Your solution here
// Input: n = 5
// Expected output:
// 5! = 120

// Bonus: What's the largest factorial you can store in an int? In a long long?
```

Hint: Use a loop and accumulate the product.
