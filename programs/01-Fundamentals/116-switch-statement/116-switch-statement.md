---
title: "Switch Statement"
topic: "Conditionals"
level: "fundamental"
program_number: 116
---

## Concept

The `switch` statement provides multi-way branching based on the value of an integer expression. It compares the expression against constant case labels.

```c
switch (expression) {
    case constant1:
        // code
        break;
    case constant2:
        // code
        break;
    default:
        // code
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int day = 3;
    
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        default:
            printf("Weekend\n");
    }
    
    return 0;
}
```

## Output

```
Wednesday
```

## Key Takeaways

1. Expression must be integer type (int, char, enum)
2. Case labels must be compile-time constants
3. No duplicate case values allowed
4. Cases are entry points, not blocks
5. Cleaner than long else-if chains for discrete values

## Kata Challenge

Write a program that converts a digit (0-9) to its English word using switch.
