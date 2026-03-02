# Pointer Arithmetic

## Overview
Pointer arithmetic allows you to navigate through memory by incrementing or decrementing pointers. The compiler automatically scales the arithmetic based on the pointer's type size.

## Key Concepts

### Increment and Decrement
```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;

ptr++;      // Moves forward by sizeof(int) bytes
ptr--;      // Moves backward by sizeof(int) bytes
ptr += 3;   // Moves forward by 3 * sizeof(int) bytes
ptr -= 2;   // Moves backward by 2 * sizeof(int) bytes
```

### Type-Aware Scaling
The compiler automatically scales pointer arithmetic:
- `int *` increments by 4 bytes (typically)
- `char *` increments by 1 byte
- `double *` increments by 8 bytes

### Pointer Subtraction
Subtracting two pointers yields the number of elements between them:
```c
int *p1 = &arr[1];
int *p2 = &arr[4];
ptrdiff_t diff = p2 - p1;  // Result: 3
```

## Valid Operations
| Operation | Description |
|-----------|-------------|
| `ptr + n` | Move forward n elements |
| `ptr - n` | Move backward n elements |
| `ptr++` | Post-increment |
| `++ptr` | Pre-increment |
| `ptr1 - ptr2` | Distance between pointers |

## Invalid Operations
- Adding two pointers
- Multiplying or dividing pointers
- Pointer arithmetic on `void *`

## Common Pitfalls
1. **Out of bounds**: Moving past array boundaries
2. **Dangling pointers**: Arithmetic on freed memory
3. **Type mismatch**: Comparing pointers of different types

---

# Kata Challenge

## Challenge: Array Sum with Pointer Arithmetic

Write a function that calculates the sum of an integer array using only pointer arithmetic (no array indexing `[]`).

### Requirements
1. Function signature: `int sum_array(int *arr, int size)`
2. Use only pointer increment/decrement
3. Do not use array indexing notation
4. Handle empty arrays (size 0)

### Example
```c
int numbers[] = {5, 10, 15, 20, 25};
int result = sum_array(numbers, 5);
// result should be 75
```

### Bonus Challenge
Implement `int *find_max(int *arr, int size)` that returns a pointer to the maximum element using only pointer arithmetic.

### Starter Code
```c
#include <stdio.h>

int sum_array(int *arr, int size) {
    // Your code here
}

int main(void) {
    int numbers[] = {5, 10, 15, 20, 25};
    printf("Sum: %d\n", sum_array(numbers, 5));
    return 0;
}
```

### Expected Output
```
Sum: 75
```
