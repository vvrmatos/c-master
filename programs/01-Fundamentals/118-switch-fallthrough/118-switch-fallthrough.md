---
title: "Switch Fall-Through"
topic: "Conditionals"
level: "fundamental"
program_number: 118
---

## Concept

When multiple cases should execute the same code, intentional fall-through groups them together. Cases stack without breaks until a common block.

```c
case 1:
case 2:
case 3:
    // executed for 1, 2, or 3
    break;
```

## Code

```c
#include <stdio.h>

int main(void) {
    int month = 2;
    int days;
    
    switch (month) {
        case 1: case 3: case 5:
        case 7: case 8: case 10:
        case 12:
            days = 31;
            break;
        case 4: case 6:
        case 9: case 11:
            days = 30;
            break;
        case 2:
            days = 28;
            break;
        default:
            days = -1;
    }
    
    printf("Month %d has %d days\n", month, days);
    
    return 0;
}
```

## Output

```
Month 2 has 28 days
```

## Key Takeaways

1. Multiple cases can share same code block
2. Stacking cases is cleaner than duplicating code
3. Comment intentional fall-through for clarity
4. Common pattern for grouping related values
5. Reduces code duplication

## Kata Challenge

Write a program that classifies characters (vowel, consonant, digit, other) using fall-through.
