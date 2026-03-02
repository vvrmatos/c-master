---
title: Row-Major Order
topic: arrays
level: fundamentals
importance: important
---

## Concept

C stores 2D arrays in **row-major order**: all elements of row 0 come first, then row 1, etc.

```
Logical:           Memory:
[0][1][2][3]       [0][1][2][3][4][5][6][7][8][9][10][11]
[4][5][6][7]       ^row 0    ^row 1    ^row 2
[8][9][10][11]
```

The element `matrix[r][c]` is at memory offset `r * COLS + c`.

## Code

```c
#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("2D array in memory (row-major order):\n\n");
    printf("Logical view:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            printf("%3d ", matrix[r][c]);
        }
        printf("\n");
    }
    
    printf("\nMemory layout (contiguous):\n");
    int *ptr = &matrix[0][0];
    for (int i = 0; i < 12; i++) {
        printf("Address %p: matrix[%d][%d] = %d\n", 
               (void *)(ptr + i), i / 4, i % 4, ptr[i]);
    }
    
    printf("\nFormula: matrix[r][c] is at offset (r * COLS + c)\n");
    printf("Example: matrix[2][1] = offset %d * 4 + %d = %d\n", 
           2, 1, 2 * 4 + 1);
    printf("Value at offset 9: %d\n", ptr[9]);
    
    return 0;
}
```

## Output

```
2D array in memory (row-major order):

Logical view:
  1   2   3   4 
  5   6   7   8 
  9  10  11  12 

Memory layout (contiguous):
Address 0x...: matrix[0][0] = 1
Address 0x...: matrix[0][1] = 2
Address 0x...: matrix[0][2] = 3
Address 0x...: matrix[0][3] = 4
Address 0x...: matrix[1][0] = 5
Address 0x...: matrix[1][1] = 6
Address 0x...: matrix[1][2] = 7
Address 0x...: matrix[1][3] = 8
Address 0x...: matrix[2][0] = 9
Address 0x...: matrix[2][1] = 10
Address 0x...: matrix[2][2] = 11
Address 0x...: matrix[2][3] = 12

Formula: matrix[r][c] is at offset (r * COLS + c)
Example: matrix[2][1] = offset 2 * 4 + 1 = 9
Value at offset 9: 10
```

## Key Takeaways

1. C uses row-major order (rows are contiguous)
2. Fortran uses column-major order (opposite)
3. Offset formula: `r * num_cols + c`
4. Row-first iteration is cache-efficient
5. Understanding layout helps optimize performance

## Kata Challenge

Given a 1D array of 12 integers, interpret it as a 3×4 matrix and print it in grid format using the row-major offset formula.
