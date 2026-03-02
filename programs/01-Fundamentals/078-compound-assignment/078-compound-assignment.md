---
id: "078"
title: "Compound Assignment Operators"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "compound-assignment", "shorthand"]
difficulty: "beginner"
---

# Compound Assignment Operators

## Concept

Compound assignment operators combine an arithmetic operation with assignment. They provide a shorter syntax for a common pattern.

| Operator | Equivalent |
|----------|------------|
| `x += y` | `x = x + y` |
| `x -= y` | `x = x - y` |
| `x *= y` | `x = x * y` |
| `x /= y` | `x = x / y` |
| `x %= y` | `x = x % y` |

**Advantages**:
- More concise
- Variable is evaluated only once (matters with side effects)
- Clearer intent: "modify x" vs "compute and store"

## Code

```c
// Compound assignment operators

#include <stdio.h>

int main(void) {
    int x = 10;
    
    x += 5;   // x = x + 5
    printf("After x += 5: %d\n", x);
    
    x -= 3;   // x = x - 3
    printf("After x -= 3: %d\n", x);
    
    x *= 2;   // x = x * 2
    printf("After x *= 2: %d\n", x);
    
    x /= 4;   // x = x / 4
    printf("After x /= 4: %d\n", x);
    
    x %= 3;   // x = x % 3
    printf("After x %%= 3: %d\n", x);
    
    // Chaining (right-to-left)
    int a = 5, b = 10;
    a += b -= 3;  // b = 7, then a = 5 + 7 = 12
    printf("\na += b -= 3: a=%d, b=%d\n", a, b);
    
    return 0;
}
```

## Output

```
After x += 5: 15
After x -= 3: 12
After x *= 2: 24
After x /= 4: 6
After x %= 3: 0

a += b -= 3: a=12, b=7
```

## Key Takeaways

1. `x op= y` is equivalent to `x = x op y`
2. Right-hand side is evaluated before the operation
3. Assignment operators have right-to-left associativity
4. Also available for bitwise: `&=`, `|=`, `^=`, `<<=`, `>>=`
5. The left operand is evaluated only once (important for `arr[i++] += 1`)

## Kata Challenge

**Running Total Calculator**

Write a program that reads a series of numbers and keeps a running total using compound assignment. Also track the count of numbers entered.

```c
// Your solution here
// Simulate input: 10, 25, 15, 30, 20
// Expected output:
// After 10: total = 10, count = 1
// After 25: total = 35, count = 2
// After 15: total = 50, count = 3
// After 30: total = 80, count = 4
// After 20: total = 100, count = 5
// Average: 20.00
```

Hint: Use `total += value` and `count++` in a loop.
