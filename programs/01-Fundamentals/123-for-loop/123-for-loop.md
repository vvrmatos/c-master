---
title: "For Loop"
topic: "Loops"
level: "fundamental"
program_number: 123
---

## Concept

The `for` loop combines initialization, condition, and update in one line. Best for counted iterations.

```c
for (init; condition; update) {
    // body
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 5; i++) {
        printf("i = %d\n", i);
    }
    
    printf("\nEven numbers: ");
    for (int n = 2; n <= 10; n += 2) {
        printf("%d ", n);
    }
    printf("\n");
    
    printf("Countdown: ");
    for (int c = 5; c >= 1; c--) {
        printf("%d ", c);
    }
    printf("\n");
    
    return 0;
}
```

## Output

```
i = 1
i = 2
i = 3
i = 4
i = 5

Even numbers: 2 4 6 8 10 
Countdown: 5 4 3 2 1 
```

## Key Takeaways

1. Three parts: init, condition, update
2. Init runs once before loop starts
3. Condition checked before each iteration
4. Update runs after each iteration
5. Loop variable scope limited to loop (C99+)

## Kata Challenge

Write a program that prints ASCII characters from 'A' to 'Z' using a for loop.
