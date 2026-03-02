# 137 - Partial Initialization: Rest Are Zero

## Overview
When an array is **partially initialized**, C guarantees that all unspecified elements are set to zero. This is a fundamental behavior that enables concise initialization.

## The Rule

> If an array has fewer initializers than elements, the remaining elements are initialized to zero.

```c
int arr[10] = {1, 2, 3};
/* Result: {1, 2, 3, 0, 0, 0, 0, 0, 0, 0} */
```

## How It Works

### Integer Arrays
```c
int arr[5] = {10, 20};
/* arr[0] = 10 */
/* arr[1] = 20 */
/* arr[2] = 0  (implicit) */
/* arr[3] = 0  (implicit) */
/* arr[4] = 0  (implicit) */
```

### The Zero Initialization Idiom
```c
int arr[100] = {0};   /* All 100 elements are 0 */
```

This works because:
1. `arr[0]` is explicitly set to 0
2. All remaining elements are implicitly set to 0

### Floating Point Arrays
```c
double arr[4] = {1.5};
/* {1.5, 0.0, 0.0, 0.0} */
```

Zero for floating point is `0.0`.

### Character Arrays
```c
char arr[10] = {'H', 'i'};
/* {'H', 'i', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'} */
```

Zero for characters is `'\0'` (null character).

### Pointer Arrays
```c
int *arr[5] = {NULL};
/* All five pointers are NULL */
```

Zero for pointers is `NULL`.

## Contrast: No Initialization

```c
/* WITH initialization: */
int arr1[5] = {1};     /* {1, 0, 0, 0, 0} - zeroed */

/* WITHOUT initialization: */
int arr2[5];           /* {?, ?, ?, ?, ?} - garbage */
```

Uninitialized arrays contain **garbage** (whatever was in memory).

## Storage Duration Matters

### Automatic (Local) Arrays
```c
void func(void) {
    int arr1[5];        /* Garbage without initializer */
    int arr2[5] = {1};  /* {1, 0, 0, 0, 0} with initializer */
}
```

### Static/Global Arrays
```c
static int arr1[5];     /* {0, 0, 0, 0, 0} - zeroed automatically */
static int arr2[5] = {1}; /* {1, 0, 0, 0, 0} */

int global[5];          /* {0, 0, 0, 0, 0} - zeroed automatically */
```

Static and global arrays are always zeroed if not initialized.

## Practical Applications

### Default Values
```c
/* Histogram with 26 buckets (one per letter), all starting at 0 */
int letter_counts[26] = {0};
```

### Sparse Initialization
```c
/* Array where only first few values matter */
int primes[100] = {2, 3, 5, 7, 11, 13};  /* Rest are 0 */
```

### Sentinel Values
```c
/* Array of pointers with NULL sentinels */
char *strings[10] = {"hello", "world"};  /* Rest are NULL */
```

### Buffer Initialization
```c
/* Clean buffer */
char buffer[1024] = {0};  /* All bytes are 0 */
```

## Empty Braces (C23)

C23 introduces empty brace initialization:
```c
int arr[5] = {};  /* All zeros (C23 only) */
```

For earlier C standards, use `{0}`:
```c
int arr[5] = {0}; /* All zeros (all C versions) */
```

## Struct Arrays

Same rule applies:
```c
struct Point { int x, y; };

struct Point points[5] = {{1, 2}, {3, 4}};
/* points[0] = {1, 2} */
/* points[1] = {3, 4} */
/* points[2] = {0, 0} */
/* points[3] = {0, 0} */
/* points[4] = {0, 0} */
```

## Common Patterns

### Zero-Initialize All
```c
int arr[100] = {0};
double matrix[50] = {0.0};
char buffer[256] = {'\0'};
void *ptrs[10] = {NULL};
```

### Initialize First Few
```c
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months[12] = {31, 28, 31}; /* Only Q1, rest are 0 */
```

### Initialize to Same Value (doesn't work directly)
```c
int arr[5] = {42};  /* Only arr[0] = 42, rest = 0! */

/* For all same value, must loop: */
int arr[5];
for (int i = 0; i < 5; i++) arr[i] = 42;
```

## Important Notes

1. **Must have at least `= {}`** to trigger zero-filling
   ```c
   int arr[5];        /* Garbage */
   int arr[5] = {};   /* All zeros (C23) */
   int arr[5] = {0};  /* All zeros (all versions) */
   ```

2. **Cannot have more initializers than size**
   ```c
   int arr[3] = {1, 2, 3, 4};  /* Error! */
   ```

3. **Applies recursively to nested types**
   ```c
   int arr[2][3] = {{1}};  /* {{1,0,0}, {0,0,0}} */
   ```

---

## Kata Challenge

### Challenge: Partial Initialization Explorer

**Task**: Create a program demonstrating partial initialization behavior across types.

**Requirements**:
1. Create arrays of each type: int, double, char, pointer
2. Use partial initialization with 2-3 elements each
3. Print all elements showing explicit vs. implicit zero values
4. Include one fully uninitialized array (local) to show contrast

**Expected Output**:
```
Integer array[8] = {5, 10}:
  [0]=5, [1]=10, [2]=0, [3]=0, [4]=0, [5]=0, [6]=0, [7]=0
  Explicit: 2, Implicit zeros: 6

Double array[5] = {3.14}:
  [0]=3.14, [1]=0.00, [2]=0.00, [3]=0.00, [4]=0.00
  Explicit: 1, Implicit zeros: 4

Char array[6] = {'X', 'Y'}:
  [0]='X', [1]='Y', [2]='\0', [3]='\0', [4]='\0', [5]='\0'
  Explicit: 2, Implicit zeros: 4

Pointer array[4] = {&a}:
  [0]=0x..., [1]=NULL, [2]=NULL, [3]=NULL
  Explicit: 1, Implicit NULLs: 3
```

**Starter Code**:
```c
#include <stdio.h>

int main(void) {
    int dummy = 42;  /* For pointer example */
    
    /* Create partially initialized arrays */
    
    /* Print and analyze */
    
    return 0;
}
```

---
**Difficulty**: ⭐ (Beginner)  
**Time**: 15 minutes  
**Topics**: Arrays, Initialization, Types
