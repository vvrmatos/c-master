# Pointer to Pointer (Double Pointer)

## Overview
A pointer to pointer (double pointer) stores the address of another pointer. This adds another level of indirection and is commonly used for dynamic 2D arrays, modifying pointers in functions, and arrays of strings.

## Key Concepts

### Declaration and Initialization
```c
int value = 42;
int *ptr = &value;     // Single pointer
int **pptr = &ptr;     // Double pointer
int ***ppptr = &pptr;  // Triple pointer (rare)
```

### Dereferencing Levels
```c
int value = 42;
int *ptr = &value;
int **pptr = &ptr;

pptr     // Address of ptr
*pptr    // Value of ptr (address of value)
**pptr   // Value of value (42)
```

### Memory Layout
```
value:  [42]        <- address 0x1000
         ^
         |
ptr:    [0x1000]    <- address 0x2000
         ^
         |
pptr:   [0x2000]    <- address 0x3000
```

### Common Use Cases

**1. Modifying a pointer in a function:**
```c
void allocate(int **ptr) {
    *ptr = malloc(sizeof(int));
}
```

**2. Array of strings:**
```c
char *names[] = {"Alice", "Bob", "Carol"};
char **ptr = names;
```

**3. Dynamic 2D arrays:**
```c
int **matrix = malloc(rows * sizeof(int *));
for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
}
```

## Type Breakdown
| Expression | Type | Meaning |
|------------|------|---------|
| `pptr` | `int **` | Pointer to pointer |
| `*pptr` | `int *` | Pointer to int |
| `**pptr` | `int` | The integer value |

---

# Kata Challenge

## Challenge: Swap Pointers

Write a function that swaps two integer pointers (not the values they point to, but the pointers themselves).

### Requirements
1. Function signature: `void swap_pointers(int **pp1, int **pp2)`
2. After calling, each pointer should point to what the other originally pointed to
3. Do not swap the values at the memory locations

### Example
```c
int a = 10, b = 20;
int *p1 = &a;
int *p2 = &b;

printf("Before: *p1=%d, *p2=%d\n", *p1, *p2);
swap_pointers(&p1, &p2);
printf("After: *p1=%d, *p2=%d\n", *p1, *p2);

// Output:
// Before: *p1=10, *p2=20
// After: *p1=20, *p2=10
// (p1 now points to b, p2 now points to a)
```

### Bonus Challenge
Create a function `void sort_by_pointer(int **arr, int n)` that sorts an array of pointers based on the values they point to.

```c
int a=30, b=10, c=20;
int *ptrs[] = {&a, &b, &c};
sort_by_pointer(ptrs, 3);
// ptrs now ordered: &b, &c, &a (pointing to 10, 20, 30)
```

### Starter Code
```c
#include <stdio.h>

void swap_pointers(int **pp1, int **pp2) {
    // Your code here
}

int main(void) {
    int a = 10, b = 20;
    int *p1 = &a;
    int *p2 = &b;
    
    printf("Before swap:\n");
    printf("p1 points to: %d\n", *p1);
    printf("p2 points to: %d\n", *p2);
    
    swap_pointers(&p1, &p2);
    
    printf("\nAfter swap:\n");
    printf("p1 points to: %d\n", *p1);
    printf("p2 points to: %d\n", *p2);
    
    return 0;
}
```

### Expected Output
```
Before swap:
p1 points to: 10
p2 points to: 20

After swap:
p1 points to: 20
p2 points to: 10
```
