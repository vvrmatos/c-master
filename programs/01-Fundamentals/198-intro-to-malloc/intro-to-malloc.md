# Introduction to malloc

## Overview
`malloc` (memory allocation) allocates a block of memory on the heap. Unlike stack variables, heap memory persists until explicitly freed and can be resized or shared across function calls.

## Key Concepts

### Basic malloc Usage
```c
#include <stdlib.h>

int *ptr = malloc(sizeof(int));  // Allocate 4 bytes (typically)
if (ptr == NULL) {
    // Handle allocation failure
}
*ptr = 42;  // Use the memory
free(ptr);  // Release when done
```

### Allocating Arrays
```c
int n = 10;
int *arr = malloc(n * sizeof(int));

// Use like a regular array
for (int i = 0; i < n; i++) {
    arr[i] = i * 2;
}

free(arr);
```

### malloc vs calloc
| Function | Initialization | Syntax |
|----------|---------------|--------|
| `malloc` | Uninitialized (garbage) | `malloc(size)` |
| `calloc` | Zero-initialized | `calloc(count, size)` |

```c
// These allocate same size, but calloc zeros memory
int *p1 = malloc(10 * sizeof(int));      // Contains garbage
int *p2 = calloc(10, sizeof(int));       // Contains zeros
```

### Always Check for NULL
```c
int *data = malloc(1000000 * sizeof(int));
if (data == NULL) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
}
```

### Common Patterns
```c
// Allocate struct
struct Point *p = malloc(sizeof(struct Point));

// Allocate string (don't forget +1 for null terminator)
char *str = malloc(strlen(source) + 1);

// Allocate 2D array (array of pointers)
int **matrix = malloc(rows * sizeof(int *));
for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
}
```

## Stack vs Heap

| Aspect | Stack | Heap (malloc) |
|--------|-------|---------------|
| Allocation | Automatic | Manual |
| Deallocation | Automatic | Manual (free) |
| Size | Limited, fixed | Large, flexible |
| Speed | Fast | Slower |
| Lifetime | Function scope | Until freed |

---

# Kata Challenge

## Challenge: Dynamic Integer Array

Create a simple dynamic array structure that grows as needed.

### Requirements
1. Create a struct:
   ```c
   typedef struct {
       int *data;
       int size;      // Current number of elements
       int capacity;  // Total allocated space
   } DynamicArray;
   ```

2. Implement these functions:
   - `DynamicArray *create_array(int initial_capacity)`
   - `int append(DynamicArray *arr, int value)` — returns 0 on success, -1 on failure
   - `int get(DynamicArray *arr, int index)` — returns value at index
   - `void destroy_array(DynamicArray *arr)` — frees all memory

3. Double capacity when array is full

### Example
```c
DynamicArray *arr = create_array(4);
append(arr, 10);
append(arr, 20);
append(arr, 30);
printf("Element 1: %d\n", get(arr, 1));  // 20
destroy_array(arr);
```

### Bonus Challenge
Add `int insert(DynamicArray *arr, int index, int value)` that inserts at a specific position, shifting elements right.

### Starter Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *create_array(int initial_capacity) {
    // Your code here
    return NULL;
}

int append(DynamicArray *arr, int value) {
    // Your code here
    return -1;
}

int get(DynamicArray *arr, int index) {
    // Your code here
    return 0;
}

void destroy_array(DynamicArray *arr) {
    // Your code here
}

int main(void) {
    DynamicArray *arr = create_array(2);
    
    for (int i = 0; i < 10; i++) {
        append(arr, i * 10);
        printf("Added %d, size=%d, capacity=%d\n", i * 10, arr->size, arr->capacity);
    }
    
    printf("\nElements: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", get(arr, i));
    }
    printf("\n");
    
    destroy_array(arr);
    return 0;
}
```

### Expected Output
```
Added 0, size=1, capacity=2
Added 10, size=2, capacity=2
Added 20, size=3, capacity=4
Added 30, size=4, capacity=4
Added 40, size=5, capacity=8
...
Elements: 0 10 20 30 40 50 60 70 80 90
```
