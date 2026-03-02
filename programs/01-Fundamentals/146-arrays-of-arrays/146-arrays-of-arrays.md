# 146 - Arrays of Arrays: Understanding 2D as 1D

## Overview
In C, multidimensional arrays are stored in **row-major order** as contiguous memory. A 2D array is essentially an array of 1D arrays, all laid out sequentially in memory.

## Memory Layout

```
int arr[2][3] = {{1,2,3}, {4,5,6}};

Memory layout:
Address:  [0]  [1]  [2]  [3]  [4]  [5]
Value:     1    2    3    4    5    6
          |---row 0---|---row 1---|
```

## Key Concepts

### Row-Major Order
- Elements are stored row by row
- `arr[i][j]` is at offset `i * num_cols + j`
- Consecutive elements in a row are adjacent in memory

### Array Decay
- `arr` decays to pointer to first row (`int (*)[3]`)
- `arr[0]` decays to pointer to first element (`int *`)
- `&arr[0][0]` gives address of first `int`

### Index Calculation
```c
int matrix[ROWS][COLS];
// matrix[i][j] == *(&matrix[0][0] + i * COLS + j)
```

## Common Patterns

```c
// Iterate as 1D
int *flat = &arr[0][0];
for (int i = 0; i < rows * cols; i++) {
    process(flat[i]);
}

// Convert 1D index to 2D
int row = flat_index / cols;
int col = flat_index % cols;
```

## Why This Matters
- Cache-friendly traversal (iterate by rows)
- Passing to functions that expect flat arrays
- Understanding memory debuggers
- Optimizing nested loops

---

# Kata Challenge

## Challenge: Matrix Flattener
Write a program that:
1. Creates a 3x4 matrix with values 1-12
2. Prints it as a 2D grid
3. Using only a single pointer and 1D indexing, print all elements
4. Given a flat index, compute and print the 2D coordinates

## Requirements
- Use pointer arithmetic only for flat access
- Demonstrate row-major formula
- Handle edge cases (first/last element)

## Expected Output
```
Matrix (3x4):
 1  2  3  4
 5  6  7  8
 9 10 11 12

Flat access:
Index 0: value=1, position=(0,0)
Index 5: value=6, position=(1,1)
Index 11: value=12, position=(2,3)
```

## Bonus
- Implement column-major access pattern
- Compare iteration performance
