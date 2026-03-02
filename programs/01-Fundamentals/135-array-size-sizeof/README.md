# 135 - Array Size with sizeof

## Overview
The expression `sizeof(arr) / sizeof(arr[0])` calculates the number of elements in an array. This idiom is essential for writing maintainable C code.

## The Formula

```c
size_t count = sizeof(array) / sizeof(array[0]);
```

- `sizeof(array)`: Total bytes of the array
- `sizeof(array[0])`: Bytes of one element
- Result: Number of elements

## How It Works

```c
int arr[5] = {10, 20, 30, 40, 50};

sizeof(arr)     /* 20 bytes (5 × 4 bytes per int) */
sizeof(arr[0])  /* 4 bytes (one int) */

20 / 4 = 5 elements
```

## Alternative Notations

```c
/* All equivalent: */
sizeof(arr) / sizeof(arr[0])
sizeof(arr) / sizeof(*arr)
sizeof(arr) / sizeof(int)      /* Less flexible */
```

The first two are preferred because they work even if the type changes.

## Practical Examples

### Integer Array
```c
int scores[] = {85, 90, 78, 92, 88, 95, 100};
size_t count = sizeof(scores) / sizeof(scores[0]);
printf("Count: %zu\n", count);  /* 7 */
```

### Double Array
```c
double temps[] = {98.6, 99.1, 97.8};
size_t count = sizeof(temps) / sizeof(temps[0]);
/* sizeof(temps) = 24, sizeof(double) = 8, count = 3 */
```

### Character Array
```c
char vowels[] = {'a', 'e', 'i', 'o', 'u'};
size_t count = sizeof(vowels) / sizeof(vowels[0]);
/* sizeof(vowels) = 5, sizeof(char) = 1, count = 5 */
```

### Structure Array
```c
struct Point { int x, y; };
struct Point points[100];
size_t count = sizeof(points) / sizeof(points[0]);
/* count = 100 */
```

## Common Macro Definition

```c
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* Usage: */
int data[20];
for (size_t i = 0; i < ARRAY_SIZE(data); i++) {
    data[i] = i;
}
```

## The Importance of This Idiom

### Without It (Fragile Code)
```c
int arr[10];

for (int i = 0; i < 10; i++) {  /* Magic number */
    arr[i] = 0;
}

/* If array size changes to 20, must update loop too */
```

### With It (Robust Code)
```c
int arr[10];

for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    arr[i] = 0;
}

/* If array size changes, loop automatically adapts */
```

## When It DOESN'T Work

### 1. After Array Decays to Pointer
```c
void func(int arr[]) {  /* arr is actually int* */
    sizeof(arr);        /* Returns pointer size (8), not array size! */
}

int numbers[100];
func(numbers);          /* Array decays to pointer */
```

### 2. With Dynamically Allocated Memory
```c
int *arr = malloc(100 * sizeof(int));
sizeof(arr);            /* Returns 8 (pointer size), not 400! */
```

### 3. With Pointers
```c
int *ptr;
int arr[10];
ptr = arr;
sizeof(ptr);            /* 8 (pointer size) */
sizeof(arr);            /* 40 (array size) */
```

## Safe Usage Pattern

```c
/* Good: sizeof works on actual arrays */
int arr[10];
size_t size = sizeof(arr) / sizeof(arr[0]);  /* 10 */

/* Bad: sizeof fails on pointers */
int *ptr = arr;
size_t size = sizeof(ptr) / sizeof(ptr[0]);  /* Wrong! */
```

## Working with Functions

Since arrays decay to pointers, pass size separately:

```c
void process_array(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main(void) {
    int data[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(data) / sizeof(data[0]);
    
    process_array(data, size);  /* Pass size explicitly */
    
    return 0;
}
```

## Compile-Time Evaluation

`sizeof` is evaluated at compile time (except for VLAs), so:

```c
int arr[100];
size_t n = sizeof(arr) / sizeof(arr[0]);  /* n = 100 at compile time */

/* No runtime cost for the division */
```

## Summary Table

| Expression | Array int arr[10] | Pointer int *ptr |
|-----------|------------------|-----------------|
| `sizeof(x)` | 40 bytes | 8 bytes |
| `sizeof(x[0])` | 4 bytes | 4 bytes |
| `sizeof(x)/sizeof(x[0])` | 10 (correct) | 2 (wrong!) |

---

## Kata Challenge

### Challenge: Generic Array Statistics

**Task**: Write a program that calculates statistics for multiple arrays using the sizeof idiom.

**Requirements**:
1. Create arrays of different types (int, double, char)
2. Create a macro `ARRAY_SIZE(arr)`
3. For each array, print:
   - Total bytes
   - Element size
   - Element count
   - Sum (for numeric arrays)
   - Average (for numeric arrays)

**Expected Output**:
```
Integer array: [5, 10, 15, 20, 25]
  Total bytes: 20
  Element size: 4 bytes
  Count: 5 elements
  Sum: 75
  Average: 15.00

Double array: [1.5, 2.5, 3.5, 4.5]
  Total bytes: 32
  Element size: 8 bytes
  Count: 4 elements
  Sum: 12.00
  Average: 3.00

Character array: ['H', 'e', 'l', 'l', 'o']
  Total bytes: 5
  Element size: 1 byte
  Count: 5 elements
```

**Starter Code**:
```c
#include <stdio.h>

#define ARRAY_SIZE(arr) /* Implement this */

int main(void) {
    int integers[] = {5, 10, 15, 20, 25};
    double doubles[] = {1.5, 2.5, 3.5, 4.5};
    char chars[] = {'H', 'e', 'l', 'l', 'o'};
    
    /* Calculate and print statistics */
    
    return 0;
}
```

---
**Difficulty**: ⭐⭐ (Easy)  
**Time**: 15 minutes  
**Topics**: sizeof, Arrays, Macros
