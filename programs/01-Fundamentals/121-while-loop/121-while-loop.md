---
title: "While Loop"
topic: "Loops"
level: "fundamental"
program_number: 121
---

## Concept

The `while` loop checks its condition before each iteration. If the condition is false initially, the body never executes.

```c
while (condition) {
    // body executes while condition is true
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int count = 1;
    
    while (count <= 5) {
        printf("Count: %d\n", count);
        count++;
    }
    
    int sum = 0, n = 1;
    while (n <= 100) {
        sum += n;
        n++;
    }
    printf("Sum 1-100: %d\n", sum);
    
    return 0;
}
```

## Output

```
Count: 1
Count: 2
Count: 3
Count: 4
Count: 5
Sum 1-100: 5050
```

## Key Takeaways

1. Condition checked before each iteration
2. Body may execute zero times
3. Must modify condition variable to avoid infinite loop
4. Good when iteration count is unknown
5. Entry-controlled loop

## Kata Challenge

Write a program that uses while to find the first power of 2 greater than 1000.
