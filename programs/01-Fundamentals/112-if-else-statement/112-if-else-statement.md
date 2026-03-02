---
title: "If-Else Statement"
topic: "Conditionals"
level: "fundamental"
program_number: 112
---

## Concept

The `if-else` statement provides two branches: one executed when the condition is true, another when false.

```c
if (condition) {
    // executed when true
} else {
    // executed when false
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int age = 17;
    
    if (age >= 18) {
        printf("You can vote\n");
    } else {
        printf("Too young to vote\n");
    }
    
    int number = -5;
    if (number >= 0) {
        printf("Positive or zero\n");
    } else {
        printf("Negative\n");
    }
    
    return 0;
}
```

## Output

```
Too young to vote
Negative
```

## Key Takeaways

1. Exactly one branch always executes
2. `else` pairs with nearest unmatched `if`
3. Both branches can have multiple statements
4. Common for binary decisions
5. Always use braces to avoid dangling else

## Kata Challenge

Write a program that determines if a number is even or odd using if-else.
