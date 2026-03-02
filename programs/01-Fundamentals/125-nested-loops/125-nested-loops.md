---
title: "Nested Loops"
topic: "Loops"
level: "fundamental"
program_number: 125
---

## Concept

Nested loops place one loop inside another. The inner loop completes all iterations for each iteration of the outer loop.

```c
for (outer) {
    for (inner) {
        // runs outer × inner times
    }
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    
    printf("\nMultiplication table:\n");
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            printf("%3d ", row * col);
        }
        printf("\n");
    }
    
    return 0;
}
```

## Output

```
(1,1) (1,2) (1,3) 
(2,1) (2,2) (2,3) 
(3,1) (3,2) (3,3) 

Multiplication table:
  1   2   3   4   5 
  2   4   6   8  10 
  3   6   9  12  15 
  4   8  12  16  20 
  5  10  15  20  25 
```

## Key Takeaways

1. Total iterations = outer × inner
2. Inner loop variable resets each outer iteration
3. Use different variable names for each level
4. Good for 2D patterns and matrices
5. Can nest any loop types (for, while, do-while)

## Kata Challenge

Write a program that prints a right triangle of asterisks using nested loops.
