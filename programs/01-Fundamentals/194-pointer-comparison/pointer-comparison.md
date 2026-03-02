# Pointer Comparison

## Overview
Pointers can be compared using equality and relational operators. This is useful for iterating through arrays, checking for NULL, and determining relative positions in memory.

## Key Concepts

### Equality Operators
```c
int *p1 = &arr[2];
int *p2 = &arr[2];
int *p3 = &arr[4];

p1 == p2   // true - same address
p1 != p3   // true - different addresses
```

### Relational Operators
Comparing pointer positions (only valid within same array or allocation):
```c
int arr[5];
int *p1 = &arr[1];
int *p2 = &arr[3];

p1 < p2    // true - p1 points to earlier element
p2 > p1    // true - p2 points to later element
p1 <= p2   // true
p2 >= p1   // true
```

### NULL Comparison
```c
int *ptr = NULL;

if (ptr == NULL) {
    printf("Pointer is null\n");
}

if (!ptr) {  // Equivalent check
    printf("Pointer is null\n");
}
```

### Loop Patterns
Using pointer comparison for iteration:
```c
int arr[] = {1, 2, 3, 4, 5};
int *end = arr + 5;  // One past last element

for (int *p = arr; p < end; p++) {
    printf("%d ", *p);
}
```

## Valid Comparisons
| Comparison | Valid When |
|------------|------------|
| `p1 == p2` | Always valid |
| `p1 != p2` | Always valid |
| `p1 < p2` | Same array/allocation |
| `p1 > p2` | Same array/allocation |
| `p == NULL` | Always valid |

## Undefined Behavior
Comparing pointers from different arrays or allocations with `<`, `>`, `<=`, `>=` is undefined behavior:
```c
int a[5], b[5];
int *p1 = a;
int *p2 = b;
p1 < p2;  // UNDEFINED BEHAVIOR!
```

---

# Kata Challenge

## Challenge: Binary Search with Pointers

Implement binary search using pointer comparison instead of index comparison.

### Requirements
1. Function signature: `int *binary_search(int *start, int *end, int target)`
2. Use pointer arithmetic and comparison
3. `end` points one past the last element
4. Return pointer to found element, or NULL if not found
5. Do not use array indices

### Example
```c
int sorted[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
int *result = binary_search(sorted, sorted + 10, 23);
if (result) {
    printf("Found at position: %ld\n", result - sorted);
}
```

### Hints
- Middle pointer: `int *mid = start + (end - start) / 2;`
- Use `<` and `>` for comparisons between `start` and `end`

### Bonus Challenge
Implement `int *find_range_start(int *start, int *end, int target)` that finds the first occurrence of a value in a sorted array with duplicates.

### Starter Code
```c
#include <stdio.h>

int *binary_search(int *start, int *end, int target) {
    while (start < end) {
        int *mid = start + (end - start) / 2;
        // Your code here
    }
    return NULL;
}

int main(void) {
    int sorted[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    
    int *result = binary_search(sorted, sorted + 10, target);
    
    if (result) {
        printf("Found %d at index %ld\n", target, result - sorted);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}
```

### Expected Output
```
Found 23 at index 5
```
