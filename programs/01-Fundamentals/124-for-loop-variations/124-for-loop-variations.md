---
title: "For Loop Variations"
topic: "Loops"
level: "fundamental"
program_number: 124
---

## Concept

The for loop is flexible—any part can be omitted or expanded to handle complex iteration patterns.

```c
for (int i=0, j=10; i<j; i++, j--)  // multiple vars
for (; condition; )                   // omitted parts
for (;;)                              // infinite loop
```

## Code

```c
#include <stdio.h>

int main(void) {
    /* Multiple variables */
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("i=%d, j=%d\n", i, j);
    }
    
    printf("\n");
    
    /* Omitted initialization */
    int k = 0;
    for (; k < 3; k++) {
        printf("k=%d\n", k);
    }
    
    /* Omitted update */
    printf("\n");
    for (int m = 0; m < 3; ) {
        printf("m=%d\n", m);
        m++;
    }
    
    return 0;
}
```

## Output

```
i=0, j=10
i=1, j=9
i=2, j=8
i=3, j=7
i=4, j=6

k=0
k=1
k=2

m=0
m=1
m=2
```

## Key Takeaways

1. Comma operator allows multiple expressions
2. Any/all parts can be empty
3. Variables in init must be same type
4. Empty condition defaults to true
5. Flexibility enables creative patterns

## Kata Challenge

Write a program that traverses an array from both ends using two loop variables.
