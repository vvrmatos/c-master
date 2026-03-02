# 132 - Array Initialization with Initializer Lists

## Overview
**Initializer lists** provide values for array elements at declaration time. This is the recommended way to set initial array values.

## Syntax
```c
type name[size] = {value0, value1, value2, ...};
type name[] = {value0, value1, ...};  /* Size inferred */
```

## How It Works

### Full Initialization
```c
int scores[5] = {90, 85, 78, 92, 88};
```
- Every element gets a specific value
- Number of values must not exceed array size

### Implicit Size
```c
int data[] = {1, 2, 3, 4, 5, 6};  /* Size is 6 */
```
- Compiler counts initializers to determine size
- Convenient but size may be unclear to readers

### How Compiler Processes
```c
int arr[3] = {10, 20, 30};

/* Equivalent to: */
int arr[3];
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
```

## Examples

### Integer Arrays
```c
int fibonacci[8] = {0, 1, 1, 2, 3, 5, 8, 13};
int powers[] = {1, 2, 4, 8, 16, 32, 64, 128};
```

### Character Arrays
```c
char grade_letters[5] = {'A', 'B', 'C', 'D', 'F'};
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
```

### Floating Point Arrays
```c
double constants[] = {3.14159, 2.71828, 1.41421, 1.61803};
float prices[4] = {9.99f, 19.99f, 29.99f, 39.99f};
```

### Negative and Mixed Values
```c
int temps[] = {-5, 0, 10, -3, 8, 15, -1};
int deltas[] = {+1, -1, +2, -2, +3, -3};
```

## Memory Layout

```c
int arr[4] = {10, 20, 30, 40};

Memory:     [ 10 ][ 20 ][ 30 ][ 40 ]
Index:         0     1     2     3
```

At declaration, all values are placed in contiguous memory.

## Important Rules

### 1. Cannot Exceed Declared Size
```c
int arr[3] = {1, 2, 3, 4};  /* Error: too many initializers */
```

### 2. Empty Braces Initialize to Zero
```c
int arr[5] = {};  /* C23: all zeros - not valid in earlier C */
int arr[5] = {0}; /* All versions: first is 0, rest are 0 */
```

### 3. Initializer List Only at Declaration
```c
int arr[3];
arr = {1, 2, 3};  /* Error: cannot assign to array */
```

### 4. Elements Must Match Type
```c
int arr[] = {1, 2, 3.5};  /* 3.5 truncated to 3 */
```

## Static vs Automatic Arrays

### Automatic (Stack) Arrays
```c
void func(void) {
    int arr[] = {1, 2, 3};  /* Initialized each call */
}
```

### Static Arrays
```c
void func(void) {
    static int arr[] = {1, 2, 3};  /* Initialized once */
}
```

### Global Arrays
```c
int global_arr[] = {1, 2, 3};  /* Initialized at program start */
```

## Common Patterns

### Lookup Tables
```c
int days_in_month[] = {31, 28, 31, 30, 31, 30, 
                       31, 31, 30, 31, 30, 31};
```

### ASCII Conversion Tables
```c
int hex_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                    10, 11, 12, 13, 14, 15};  /* 0-9, A-F */
```

### Predefined Data Sets
```c
double test_cases[] = {0.0, 1.0, -1.0, 0.5, 100.0};
```

## Best Practices

1. **Prefer explicit size** when size is meaningful
   ```c
   int rgb[3] = {255, 128, 0};  /* Clearly 3 components */
   ```

2. **Use implicit size** for literal data
   ```c
   char vowels[] = {'a', 'e', 'i', 'o', 'u'};
   ```

3. **Format long lists** readably
   ```c
   int data[] = {
       1, 2, 3, 4, 5,
       6, 7, 8, 9, 10
   };
   ```

4. **Comment the purpose**
   ```c
   int weights[] = {1, 2, 4, 8};  /* Powers of 2 */
   ```

---

## Kata Challenge

### Challenge: Initialize Multiple Arrays

**Task**: Create a program with these initialized arrays:
1. `months`: 12 integers with days per month (non-leap year)
2. `quarters`: 4 integers with days per quarter
3. `grades`: 5 doubles representing GPA values (4.0, 3.0, 2.0, 1.0, 0.0)

**Requirements**:
1. Use appropriate initializer lists
2. Print each array with labels
3. Calculate and print the total days in `months`
4. Verify sum matches 365

**Expected Output**:
```
Days per month: 31 28 31 30 31 30 31 31 30 31 30 31
Days per quarter: 90 91 92 92
GPA values: 4.00 3.00 2.00 1.00 0.00
Total days in year: 365
```

**Starter Code**:
```c
#include <stdio.h>

int main(void) {
    /* Initialize arrays here */
    
    /* Print and calculate here */
    
    return 0;
}
```

---
**Difficulty**: ⭐ (Beginner)  
**Time**: 10 minutes  
**Topics**: Arrays, Initialization, Loops
