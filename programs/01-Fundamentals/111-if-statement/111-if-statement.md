---
title: "If Statement"
topic: "Conditionals"
level: "fundamental"
program_number: 111
---

## Concept

The `if` statement executes code only when a condition evaluates to true (non-zero). This is the most basic form of conditional execution.

```c
if (condition) {
    // executed when condition is true
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int temperature = 30;
    
    if (temperature > 25) {
        printf("It's hot outside\n");
    }
    
    int x = 10;
    if (x)
        printf("x is non-zero\n");
    
    return 0;
}
```

## Output

```
It's hot outside
x is non-zero
```

## Key Takeaways

1. Condition must be in parentheses
2. Braces optional for single statement (but recommended)
3. Any non-zero value is considered true
4. Zero is false
5. Condition is evaluated once before block

## Kata Challenge

Write a program that checks if a year is a leap year using if statements.
