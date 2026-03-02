---
title: 2D Array Iteration
topic: arrays
level: fundamentals
importance: essential
---

## Concept

Use **nested for loops** to iterate over a 2D array:

```c
for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
        // use matrix[row][col]
    }
}
```

Outer loop controls rows, inner loop controls columns.

## Code

```c
#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int rows = 3, cols = 4;
    
    printf("Row-by-row iteration:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%3d ", matrix[r][c]);
        }
        printf("\n");
    }
    
    printf("\nColumn-by-column iteration:\n");
    for (int c = 0; c < cols; c++) {
        printf("Column %d: ", c);
        for (int r = 0; r < rows; r++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
    
    printf("\nSum all elements:\n");
    int sum = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            sum += matrix[r][c];
        }
    }
    printf("Total: %d\n", sum);
    
    return 0;
}
```

## Output

```
Row-by-row iteration:
  1   2   3   4 
  5   6   7   8 
  9  10  11  12 

Column-by-column iteration:
Column 0: 1 5 9 
Column 1: 2 6 10 
Column 2: 3 7 11 
Column 3: 4 8 12 

Sum all elements:
Total: 78
```

## Key Takeaways

1. Outer loop = rows, inner loop = columns (typical)
2. Row-major traversal is cache-friendly in C
3. Swap loop order for column-first traversal
4. Use meaningful names: `row`, `col` or `r`, `c`
5. Works the same for 3D+ arrays (add more nested loops)

## Kata Challenge

Write code to find the maximum value in a 4×4 matrix and print its position (row, column).
