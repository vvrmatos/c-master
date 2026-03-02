# 147 - Variable Length Arrays (VLA) in C99

## Overview
Variable Length Arrays (VLAs) allow array sizes to be determined at runtime. Introduced in C99 as mandatory, made optional in C11.

## Syntax

```c
int n = 10;
int arr[n];           // VLA - size known at runtime

int rows = 3, cols = 4;
int matrix[rows][cols];  // 2D VLA
```

## Key Characteristics

### Runtime Size
```c
void func(int size) {
    int arr[size];  // Size determined when function called
    // ...
}
```

### Stack Allocation
- VLAs are allocated on the stack
- No malloc/free required
- Automatic cleanup when scope exits

### Function Parameters
```c
// VLA syntax in function parameters
void process(int n, int arr[n]);
void matrix_op(int rows, int cols, int m[rows][cols]);
```

## Example

```c
#include <stdio.h>

void fill_array(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

int main(void) {
    int size;
    scanf("%d", &size);
    
    int data[size];  // VLA
    fill_array(size, data);
    
    return 0;
}
```

## Compiler Support
- GCC: Full support
- Clang: Full support  
- MSVC: Limited/no support
- Compile with: `gcc -std=c99` or `gcc -std=c11`

## When to Use
- Small, temporary arrays with runtime size
- Matrix operations with dynamic dimensions
- When heap allocation overhead is unnecessary

---

# Kata Challenge

## Challenge: Dynamic Identity Matrix
Write a program that:
1. Asks user for matrix dimension N
2. Creates an NxN identity matrix using VLA
3. Prints the matrix
4. Calculates and prints the trace (sum of diagonal)

## Requirements
- Use VLA for the matrix
- Handle dimensions 1-10
- Create a function that accepts VLA parameter

## Expected Output
```
Enter dimension: 4

Identity Matrix (4x4):
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

Trace: 4
```

## Function Signature
```c
void create_identity(int n, int matrix[n][n]);
int calculate_trace(int n, int matrix[n][n]);
```

## Bonus
- Add bounds checking for dimension
- Create other special matrices (zeros, ones, diagonal)
