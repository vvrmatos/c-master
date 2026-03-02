---
title: 2D Array Declaration
topic: arrays
level: fundamentals
importance: essential
---

## Concept

A **2D array** (matrix) is declared with two pairs of brackets:

```c
type name[rows][columns];
```

Think of it as an array of arrays: `matrix[3][4]` is 3 arrays, each containing 4 elements.

## Code

```c
#include <stdio.h>

int main(void) {
    int matrix[3][4];
    
    printf("int matrix[3][4]; declares:\n");
    printf("  - 3 rows\n");
    printf("  - 4 columns\n");
    printf("  - 12 total elements\n\n");
    
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            matrix[row][col] = row * 10 + col;
        }
    }
    
    printf("Matrix contents:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
    
    printf("\nTotal size: %zu bytes\n", sizeof(matrix));
    printf("Row size:   %zu bytes\n", sizeof(matrix[0]));
    
    return 0;
}
```

## Output

```
int matrix[3][4]; declares:
  - 3 rows
  - 4 columns
  - 12 total elements

Matrix contents:
  0   1   2   3 
 10  11  12  13 
 20  21  22  23 

Total size: 48 bytes
Row size:   16 bytes
```

## Key Takeaways

1. First index is row, second is column
2. `matrix[3][4]` = 3 rows × 4 columns = 12 elements
3. Total bytes = rows × columns × sizeof(element)
4. Rows are stored contiguously in memory
5. Can have 3D, 4D, etc. arrays: `arr[a][b][c]`

## Kata Challenge

Declare a 5×5 int matrix. Fill it with values where each cell contains row + column. Print the matrix in a grid format.
