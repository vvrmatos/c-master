# 133 - Array Indexing with []

## Overview
The **subscript operator** `[]` accesses individual array elements by index. Arrays use zero-based indexing in C.

## Syntax
```c
array[index]          /* Access element at position */
array[index] = value  /* Assign to element */
```

## How It Works

### Zero-Based Indexing
```c
int arr[5] = {10, 20, 30, 40, 50};
/*  Index:    0   1   2   3   4   */

arr[0]  /* First element: 10 */
arr[4]  /* Last element: 50 */
```

### Address Calculation
The subscript operation `arr[i]` translates to:
```
address of arr[i] = base_address + (i × sizeof(element))
```

Example:
```c
int arr[5];  /* Assume starts at address 1000 */
arr[0]       /* Address: 1000 + 0*4 = 1000 */
arr[2]       /* Address: 1000 + 2*4 = 1008 */
arr[4]       /* Address: 1000 + 4*4 = 1016 */
```

## Reading Elements

### Direct Access
```c
int values[4] = {100, 200, 300, 400};

int first = values[0];   /* 100 */
int last = values[3];    /* 400 */
```

### Using Variables as Index
```c
int idx = 2;
int val = values[idx];   /* 300 */
```

### Using Expressions as Index
```c
int val = values[1 + 1];          /* values[2] = 300 */
int val = values[idx - 1];        /* Depends on idx */
int val = values[some_func()];    /* Index from function */
```

## Writing Elements

### Direct Assignment
```c
int arr[3];
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
```

### Modify Existing Values
```c
arr[1] = arr[1] + 5;    /* Increment by 5 */
arr[2] *= 2;            /* Double it */
arr[0]++;               /* Increment by 1 */
```

### Compound Assignment
```c
int arr[3] = {10, 20, 30};

arr[0] += 5;    /* arr[0] is now 15 */
arr[1] -= 10;   /* arr[1] is now 10 */
arr[2] *= 2;    /* arr[2] is now 60 */
```

## Practical Examples

### Swap Elements
```c
int arr[5] = {1, 2, 3, 4, 5};
int temp = arr[0];
arr[0] = arr[4];
arr[4] = temp;  /* Now: {5, 2, 3, 4, 1} */
```

### Find Maximum
```c
int data[5] = {23, 45, 12, 67, 34};
int max = data[0];
for (int i = 1; i < 5; i++) {
    if (data[i] > max) {
        max = data[i];
    }
}
/* max = 67 */
```

### Accumulate Sum
```c
int numbers[4] = {10, 20, 30, 40};
int sum = 0;
for (int i = 0; i < 4; i++) {
    sum += numbers[i];
}
/* sum = 100 */
```

## The Equivalence: arr[i] and *(arr + i)

In C, array subscripting is pointer arithmetic:
```c
arr[i]  ≡  *(arr + i)
```

This means these are equivalent:
```c
int arr[3] = {10, 20, 30};

arr[1]      /* 20 */
*(arr + 1)  /* 20 */
1[arr]      /* 20 - unusual but valid! */
```

## Common Index Patterns

### First Element
```c
arr[0]                      /* Always first */
```

### Last Element
```c
arr[size - 1]               /* Last valid index */
```

### Middle Element
```c
arr[size / 2]               /* Middle (truncated) */
```

### From End
```c
arr[size - 1]               /* Last */
arr[size - 2]               /* Second to last */
```

## Important Considerations

### 1. Indices Are Integers
```c
int arr[5];
arr[2.5] = 10;    /* Error or truncated to arr[2] */
arr['A'] = 10;    /* Valid: 'A' is 65, so arr[65] */
```

### 2. Negative Indices
```c
arr[-1]           /* Undefined behavior - out of bounds */
```

### 3. No Range Checking
```c
int arr[5];
arr[10] = 99;     /* Compiles but causes problems! */
```

## Use as L-value and R-value

### L-value (Left of Assignment)
```c
arr[2] = 100;     /* Writing to array element */
```

### R-value (Right side / Reading)
```c
int x = arr[2];   /* Reading from array element */
```

### In Expressions
```c
arr[0] = arr[1] + arr[2];  /* Both L-value and R-value */
```

---

## Kata Challenge

### Challenge: Array Index Operations

**Task**: Create a program that:
1. Initializes an array of 10 integers (1-10)
2. Uses indexing to:
   - Print the first and last elements
   - Swap the first and last elements
   - Double every even-indexed element
   - Calculate the sum using index access

**Requirements**:
1. Use only `[]` notation (no pointers)
2. Print the array after each operation
3. All operations via indexing

**Expected Output**:
```
Original: 1 2 3 4 5 6 7 8 9 10
First: 1, Last: 10
After swap: 10 2 3 4 5 6 7 8 9 1
After doubling even indices: 20 2 6 4 10 6 14 8 18 1
Sum: 89
```

**Starter Code**:
```c
#include <stdio.h>

int main(void) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    /* Operations here */
    
    return 0;
}
```

---
**Difficulty**: ⭐⭐ (Easy)  
**Time**: 15 minutes  
**Topics**: Arrays, Indexing, Loops
