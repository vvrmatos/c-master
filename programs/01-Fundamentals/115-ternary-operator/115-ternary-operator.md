---
title: "Ternary Operator"
topic: "Conditionals"
level: "fundamental"
program_number: 115
---

## Concept

The ternary operator (`?:`) is a compact conditional expression that returns one of two values based on a condition.

```c
result = condition ? value_if_true : value_if_false;
```

## Code

```c
#include <stdio.h>

int main(void) {
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    printf("Max of %d and %d is %d\n", a, b, max);
    
    int x = 5;
    printf("%d is %s\n", x, (x % 2 == 0) ? "even" : "odd");
    
    int score = 85;
    char *result = (score >= 60) ? "Pass" : "Fail";
    printf("Result: %s\n", result);
    
    return 0;
}
```

## Output

```
Max of 10 and 20 is 20
5 is odd
Result: Pass
```

## Key Takeaways

1. Returns a value, unlike if-else
2. Both branches must have compatible types
3. Can be nested (but hurts readability)
4. Useful for inline conditional assignment
5. Also called conditional operator

## Kata Challenge

Write a program that uses nested ternary to find the maximum of three numbers.
