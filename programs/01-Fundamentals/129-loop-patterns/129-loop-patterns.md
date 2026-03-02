---
title: "Loop Patterns"
topic: "Loops"
level: "fundamental"
program_number: 129
---

## Concept

Common loop patterns include counting up, counting down, stepping by values, and exponential iteration.

```c
for (i = 0; i < n; i++)      // count up
for (i = n-1; i >= 0; i--)   // count down
for (i = 0; i < n; i += step) // step
for (i = 1; i <= n; i *= 2)  // exponential
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("Count up: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Count down: ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Step by 2: ");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Step by 3: ");
    for (int i = 0; i <= 15; i += 3) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Powers of 2: ");
    for (int i = 1; i <= 256; i *= 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
```

## Output

```
Count up: 1 2 3 4 5 
Count down: 5 4 3 2 1 
Step by 2: 0 2 4 6 8 10 
Step by 3: 0 3 6 9 12 15 
Powers of 2: 1 2 4 8 16 32 64 128 256 
```

## Key Takeaways

1. `i++` increments by 1
2. `i--` decrements by 1
3. `i += n` steps by n
4. `i *= n` multiplies each iteration
5. Match pattern to problem requirements

## Kata Challenge

Write a program that prints Fibonacci numbers using a loop pattern.
