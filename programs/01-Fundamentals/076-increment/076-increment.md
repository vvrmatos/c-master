---
id: "076"
title: "Increment Operator"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "increment", "unary"]
difficulty: "beginner"
---

# Increment Operator

## Concept

The `++` operator adds 1 to its operand. It comes in two forms:

- **Pre-increment (`++a`)**: Increment first, then return the new value
- **Post-increment (`a++`)**: Return the current value, then increment

When used as a standalone statement, both have the same effect. The difference matters when the result is used in an expression.

**Warning**: Avoid using `++` multiple times on the same variable in one expression—behavior is undefined.

## Code

```c
// Increment operator (pre and post)

#include <stdio.h>

int main(void) {
    int a = 5;
    
    // Post-increment: use, then increment
    printf("a = %d\n", a);
    printf("a++ = %d\n", a++);
    printf("a = %d\n\n", a);
    
    // Pre-increment: increment, then use
    a = 5;
    printf("a = %d\n", a);
    printf("++a = %d\n", ++a);
    printf("a = %d\n\n", a);
    
    // In isolation, both just add 1
    int x = 10, y = 10;
    x++;
    ++y;
    printf("x++ then x = %d\n", x);
    printf("++y then y = %d\n", y);
    
    return 0;
}
```

## Output

```
a = 5
a++ = 5
a = 6

a = 5
++a = 6
a = 6

x++ then x = 11
++y then y = 11
```

## Key Takeaways

1. `++a` increments before returning the value
2. `a++` returns the original value, then increments
3. As standalone statements, both just add 1
4. `++` modifies the variable—it's not just an expression
5. Never use `++` twice on the same variable in one expression

## Kata Challenge

**Array Traversal Counter**

Write a program that simulates traversing an array using increment. Print the index used and the index after, showing the difference between pre and post increment.

```c
// Your solution here
// Using post-increment to access elements:
// Accessing index 0, current index: 1
// Accessing index 1, current index: 2
// ...
// Using pre-increment:
// Accessing index 1, current index: 1
// Accessing index 2, current index: 2
```

Hint: Think about which form you'd use in `array[i++]` vs `array[++i]`.
