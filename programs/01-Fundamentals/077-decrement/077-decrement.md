---
id: "077"
title: "Decrement Operator"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "decrement", "unary"]
difficulty: "beginner"
---

# Decrement Operator

## Concept

The `--` operator subtracts 1 from its operand. Like increment, it has two forms:

- **Pre-decrement (`--a`)**: Decrement first, then return the new value
- **Post-decrement (`a--`)**: Return the current value, then decrement

Commonly used in loops counting down, stack operations (pop), and reverse traversal.

## Code

```c
// Decrement operator (pre and post)

#include <stdio.h>

int main(void) {
    int a = 5;
    
    // Post-decrement: use, then decrement
    printf("a = %d\n", a);
    printf("a-- = %d\n", a--);
    printf("a = %d\n\n", a);
    
    // Pre-decrement: decrement, then use
    a = 5;
    printf("a = %d\n", a);
    printf("--a = %d\n", --a);
    printf("a = %d\n\n", a);
    
    // Countdown
    printf("Countdown: ");
    for (int i = 5; i > 0; i--) {
        printf("%d ", i);
    }
    printf("Liftoff!\n");
    
    return 0;
}
```

## Output

```
a = 5
a-- = 5
a = 4

a = 5
--a = 4
a = 4

Countdown: 5 4 3 2 1 Liftoff!
```

## Key Takeaways

1. `--a` decrements before returning the value
2. `a--` returns the original value, then decrements
3. Commonly used in countdown loops: `for (i = n; i > 0; i--)`
4. Same undefined behavior rules as `++`—don't use twice in one expression
5. Pre-decrement can be slightly more efficient (no temp copy needed)

## Kata Challenge

**Reverse Digit Printer**

Write a program that prints the digits of a number in reverse order using decrement and modulus.

```c
// Your solution here
// Input: num = 12345
// Expected output:
// Digits reversed: 5 4 3 2 1

// Hint: Use % 10 to get last digit, / 10 to remove it
```

Bonus: Count how many digits were processed.
