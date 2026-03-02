---
title: "Switch Default"
topic: "Conditionals"
level: "fundamental"
program_number: 119
---

## Concept

The `default` case executes when no other case matches. It acts as a catch-all for unexpected or unhandled values.

```c
switch (value) {
    case 1: /* ... */ break;
    case 2: /* ... */ break;
    default:
        // handles all other values
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    char op = '%';
    int a = 10, b = 3;
    
    switch (op) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, a / b);
            break;
        default:
            printf("Unknown operator: %c\n", op);
    }
    
    return 0;
}
```

## Output

```
Unknown operator: %
```

## Key Takeaways

1. Default handles values not covered by cases
2. Can appear anywhere (by convention, at end)
3. Good for error handling and validation
4. Optional but recommended for robustness
5. Helps catch unexpected inputs

## Kata Challenge

Write a program with a menu system that handles invalid menu choices with default.
