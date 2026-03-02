---
title: "Switch vs If-Else"
topic: "Conditionals"
level: "fundamental"
program_number: 120
---

## Concept

Choose switch for discrete value matching and if-else for ranges, complex conditions, or non-integer types.

| Use Switch | Use If-Else |
|------------|-------------|
| Exact value matching | Range comparisons |
| Integer/char/enum | Floating point, strings |
| Many discrete cases | Few conditions |
| Menu selection | Complex boolean logic |

## Code

```c
#include <stdio.h>

int main(void) {
    int choice = 2;
    
    /* Switch: best for discrete values */
    switch (choice) {
        case 1: printf("Option 1\n"); break;
        case 2: printf("Option 2\n"); break;
        case 3: printf("Option 3\n"); break;
    }
    
    /* If-else: best for ranges and complex conditions */
    int score = 75;
    if (score >= 90) {
        printf("A\n");
    } else if (score >= 80) {
        printf("B\n");
    } else if (score >= 70) {
        printf("C\n");
    } else {
        printf("Below C\n");
    }
    
    return 0;
}
```

## Output

```
Option 2
C
```

## Key Takeaways

1. Switch cannot test ranges (use if-else)
2. Switch requires compile-time constants
3. Switch may be faster (jump table optimization)
4. If-else handles any boolean expression
5. If-else works with any data type

## Kata Challenge

Write a program that implements the same logic twice: once with switch, once with if-else.
