---
title: 2D Array Access
topic: arrays
level: fundamentals
importance: essential
---

## Concept

Access 2D array elements using two indices:

```c
matrix[row][col]
```

- `row` selects which row (0 to rows-1)
- `col` selects which column (0 to cols-1)

Same syntax for reading and writing.

## Code

```c
#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("Accessing elements with matrix[row][col]:\n\n");
    printf("matrix[0][0] = %d (top-left)\n", matrix[0][0]);
    printf("matrix[0][3] = %d (top-right)\n", matrix[0][3]);
    printf("matrix[2][0] = %d (bottom-left)\n", matrix[2][0]);
    printf("matrix[2][3] = %d (bottom-right)\n", matrix[2][3]);
    printf("matrix[1][2] = %d (middle area)\n", matrix[1][2]);
    
    printf("\nModifying matrix[1][1] from %d to 99\n", matrix[1][1]);
    matrix[1][1] = 99;
    
    printf("\nUpdated matrix:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## Output

```
Accessing elements with matrix[row][col]:

matrix[0][0] = 1 (top-left)
matrix[0][3] = 4 (top-right)
matrix[2][0] = 9 (bottom-left)
matrix[2][3] = 12 (bottom-right)
matrix[1][2] = 7 (middle area)

Modifying matrix[1][1] from 6 to 99

Updated matrix:
  1   2   3   4 
  5  99   7   8 
  9  10  11  12 
```

## Key Takeaways

1. `matrix[r][c]` accesses row r, column c
2. First index is row (vertical), second is column (horizontal)
3. Both indices are zero-based
4. Bounds checking is your responsibility
5. `matrix[i]` alone gives a pointer to row i

## Kata Challenge

Given a 3×3 matrix, write code to swap two rows (e.g., row 0 and row 2). Print before and after.
