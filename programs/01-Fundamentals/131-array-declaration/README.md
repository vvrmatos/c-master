# 131 - Array Declaration in C

## Overview
An **array** is a collection of elements of the same type stored in contiguous memory locations. Array declaration specifies the type and number of elements.

## Syntax
```c
type name[size];
```

- **type**: Data type of all elements (int, char, double, etc.)
- **name**: Identifier for the array
- **size**: Number of elements (must be a constant expression in C89)

## How It Works

### Memory Allocation
When you declare an array:
1. Compiler allocates `size × sizeof(type)` bytes
2. Memory is contiguous (elements side by side)
3. Array name represents address of first element

### Declaration Examples
```c
int scores[100];        /* 100 integers = 400 bytes (typically) */
char buffer[256];       /* 256 characters = 256 bytes */
double matrix[50];      /* 50 doubles = 400 bytes (typically) */
float temps[7];         /* 7 floats = 28 bytes (typically) */
```

### Important Points

1. **Size must be known at compile time** (C89/C90)
   ```c
   const int N = 10;
   int arr[N];        /* Error in C89, OK in C99 as VLA */
   
   #define SIZE 10
   int arr[SIZE];     /* OK - preprocessor constant */
   ```

2. **Arrays are NOT initialized by default**
   ```c
   int nums[5];       /* Contains garbage values */
   ```

3. **Size cannot be zero**
   ```c
   int empty[0];      /* Invalid - undefined behavior */
   ```

4. **Array size is fixed after declaration**
   ```c
   int arr[10];
   /* Cannot resize arr - size is permanent */
   ```

### Memory Layout
```
int arr[4];

Memory:     [????][????][????][????]
Index:        0     1     2     3
Address:    1000  1004  1008  1012  (example addresses)
```

## Common Patterns

### Declaring Multiple Arrays
```c
int a[10], b[20], c[30];    /* Three separate arrays */
```

### Using Symbolic Constants
```c
#define MAX_STUDENTS 100
#define NAME_LENGTH 50

int grades[MAX_STUDENTS];
char names[MAX_STUDENTS][NAME_LENGTH];
```

## Common Mistakes

### 1. Using Variables for Size (C89)
```c
int n = 10;
int arr[n];     /* Error in C89, VLA in C99 */
```

### 2. Forgetting Array Contains Garbage
```c
int arr[5];
int sum = arr[0] + arr[1];  /* Reading garbage! */
```

### 3. Declaring Inside Expressions
```c
int x = (int arr[5], 0);    /* Invalid syntax */
```

## Best Practices

1. **Use meaningful names**: `temperatures`, not `t`
2. **Use #define for sizes**: Makes code maintainable
3. **Initialize arrays** when possible
4. **Comment the purpose** of each array
5. **Consider maximum size** needed

## Quick Reference

| Declaration | Elements | Total Size (typical) |
|------------|----------|---------------------|
| `int a[10]` | 10 ints | 40 bytes |
| `char s[100]` | 100 chars | 100 bytes |
| `double d[5]` | 5 doubles | 40 bytes |
| `float f[20]` | 20 floats | 80 bytes |

---

## Kata Challenge

### Challenge: Declare Arrays for Student Records

**Task**: Write a program that declares appropriate arrays for a classroom:
- Student IDs (integers, max 30 students)
- Test scores (doubles, max 30 students)
- Grade letters (characters, max 30 students)

Print the size of each array in bytes.

**Requirements**:
1. Use `#define` for the class size constant
2. Declare all three arrays
3. Print each array's total size using `sizeof`
4. Calculate and print total memory used

**Expected Output**:
```
Student ID array: 120 bytes
Test scores array: 240 bytes
Grade letters array: 30 bytes
Total memory: 390 bytes
```

**Starter Code**:
```c
#include <stdio.h>

#define CLASS_SIZE 30

int main(void) {
    /* Declare arrays here */
    
    /* Print sizes here */
    
    return 0;
}
```

---
**Difficulty**: ⭐ (Beginner)  
**Time**: 5 minutes  
**Topics**: Arrays, sizeof, Memory
