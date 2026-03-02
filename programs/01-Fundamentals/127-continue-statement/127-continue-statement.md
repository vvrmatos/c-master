---
title: "Continue Statement"
topic: "Loops"
level: "fundamental"
program_number: 127
---

## Concept

The `continue` statement skips the rest of the current iteration and jumps to the next iteration of the loop.

```c
for (int i = 0; i < n; i++) {
    if (skip_condition) {
        continue;  // skip to next i
    }
    // this code skipped when continue executes
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("Odd numbers 1-10: ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    printf("\nSkip multiples of 3:\n");
    for (int i = 1; i <= 15; i++) {
        if (i % 3 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
```

## Output

```
Odd numbers 1-10: 1 3 5 7 9 

Skip multiples of 3:
1 2 4 5 7 8 10 11 13 14 
```

## Key Takeaways

1. Skips remaining body, not the loop
2. In for loop, update expression still runs
3. In while/do-while, jumps to condition check
4. Useful for filtering iterations
5. Can improve readability vs deep nesting

## Kata Challenge

Write a program that sums only positive numbers from an array, skipping negatives with continue.
