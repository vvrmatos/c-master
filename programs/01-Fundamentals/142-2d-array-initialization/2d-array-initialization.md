---
title: 2D Array Initialization
topic: arrays
level: fundamentals
importance: essential
---

## Concept

2D arrays can be initialized with **nested braces**, where each inner brace represents a row:

```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Partial initialization works: missing elements are zero.

## Code

```c
#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("Initialized with nested braces:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
    
    int flat[2][3] = {1, 2, 3, 4, 5, 6};
    printf("\nFlat initialization (fills row by row):\n");
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%3d ", flat[row][col]);
        }
        printf("\n");
    }
    
    int partial[3][3] = {{1}, {4}, {7}};
    printf("\nPartial initialization (rest are 0):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%3d ", partial[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## Output

```
Initialized with nested braces:
  1   2   3   4 
  5   6   7   8 
  9  10  11  12 

Flat initialization (fills row by row):
  1   2   3 
  4   5   6 

Partial initialization (rest are 0):
  1   0   0 
  4   0   0 
  7   0   0 
```

## Key Takeaways

1. Use nested braces `{{row1}, {row2}, ...}` for clarity
2. Flat initialization fills row by row
3. Partial rows get zeros for remaining columns
4. `{{0}}` zeros the entire 2D array
5. First dimension can be omitted: `int arr[][3] = {{1,2,3},{4,5,6}}`

## Kata Challenge

Initialize a 4×4 identity matrix (1s on diagonal, 0s elsewhere) using designated initializers: `{[0][0]=1, [1][1]=1, ...}`
