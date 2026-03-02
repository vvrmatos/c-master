---
title: "Nested If"
topic: "Conditionals"
level: "fundamental"
program_number: 114
---

## Concept

Nested if statements place one conditional inside another, allowing complex decision trees with multiple levels of conditions.

```c
if (outer_condition) {
    if (inner_condition) {
        // both true
    }
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int x = 15;
    int y = 8;
    
    if (x > 10) {
        if (y > 5) {
            printf("x > 10 AND y > 5\n");
        } else {
            printf("x > 10 AND y <= 5\n");
        }
    } else {
        if (y > 5) {
            printf("x <= 10 AND y > 5\n");
        } else {
            printf("x <= 10 AND y <= 5\n");
        }
    }
    
    return 0;
}
```

## Output

```
x > 10 AND y > 5
```

## Key Takeaways

1. Inner if only evaluated if outer is true
2. Braces prevent dangling else ambiguity
3. Can nest to any depth (but limit for readability)
4. Can sometimes simplify with `&&` operator
5. Consider refactoring deep nesting

## Kata Challenge

Write a program that classifies a triangle (equilateral, isosceles, scalene) using nested ifs.
