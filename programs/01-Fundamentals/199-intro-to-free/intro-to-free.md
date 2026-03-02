# Introduction to free

## Overview
`free` releases memory previously allocated by `malloc`, `calloc`, or `realloc`. Proper memory management is critical in C to prevent memory leaks and undefined behavior.

## Key Concepts

### Basic Usage
```c
int *ptr = malloc(sizeof(int));
*ptr = 42;
// ... use ptr ...
free(ptr);       // Release memory
ptr = NULL;      // Good practice
```

### Rules for free

**1. Only free what you malloc'd:**
```c
int stack_var = 10;
free(&stack_var);  // WRONG! Undefined behavior

int *heap_var = malloc(sizeof(int));
free(heap_var);    // Correct
```

**2. Free exactly once:**
```c
int *ptr = malloc(sizeof(int));
free(ptr);
free(ptr);  // WRONG! Double free - undefined behavior
```

**3. Don't use after free:**
```c
int *ptr = malloc(sizeof(int));
*ptr = 42;
free(ptr);
printf("%d\n", *ptr);  // WRONG! Use after free
```

**4. free(NULL) is safe:**
```c
int *ptr = NULL;
free(ptr);  // Safe, does nothing
```

### Common Memory Errors

| Error | Description | Prevention |
|-------|-------------|------------|
| Memory leak | Never freeing allocated memory | Always pair malloc with free |
| Double free | Freeing same memory twice | Set pointer to NULL after free |
| Use after free | Accessing freed memory | Set pointer to NULL after free |
| Invalid free | Freeing non-heap memory | Only free malloc'd pointers |

### Best Practices
```c
// Pattern: Allocate, check, use, free, nullify
int *data = malloc(size);
if (data == NULL) {
    handle_error();
    return;
}
// Use data...
free(data);
data = NULL;  // Prevents use-after-free and double-free
```

### Freeing Complex Structures
```c
// Free nested allocations from inside out
char **strings = malloc(n * sizeof(char *));
for (int i = 0; i < n; i++) {
    strings[i] = malloc(100);
}

// Free in reverse order
for (int i = 0; i < n; i++) {
    free(strings[i]);
}
free(strings);
```

---

# Kata Challenge

## Challenge: Memory Pool Cleanup

Create a simple memory pool that tracks allocations and can free everything at once.

### Requirements
1. Create a struct:
   ```c
   typedef struct {
       void **allocations;
       int count;
       int capacity;
   } MemoryPool;
   ```

2. Implement these functions:
   - `MemoryPool *pool_create(int initial_capacity)`
   - `void *pool_alloc(MemoryPool *pool, size_t size)` — malloc and track
   - `void pool_free_all(MemoryPool *pool)` — free all tracked allocations
   - `void pool_destroy(MemoryPool *pool)` — free all + destroy pool itself

3. Grow the tracking array as needed

### Example
```c
MemoryPool *pool = pool_create(10);

int *nums = pool_alloc(pool, 5 * sizeof(int));
char *str = pool_alloc(pool, 50);
double *data = pool_alloc(pool, 100 * sizeof(double));

// Use allocations...

pool_destroy(pool);  // Frees everything!
```

### Why This Is Useful
- Simplifies cleanup in complex programs
- Prevents memory leaks
- Common pattern in game engines and parsers

### Bonus Challenge
Add `void pool_free(MemoryPool *pool, void *ptr)` that frees a specific allocation and removes it from tracking.

### Starter Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void **allocations;
    int count;
    int capacity;
} MemoryPool;

MemoryPool *pool_create(int initial_capacity) {
    // Your code here
    return NULL;
}

void *pool_alloc(MemoryPool *pool, size_t size) {
    // Your code here
    return NULL;
}

void pool_free_all(MemoryPool *pool) {
    // Your code here
}

void pool_destroy(MemoryPool *pool) {
    // Your code here
}

int main(void) {
    MemoryPool *pool = pool_create(4);
    
    // Make several allocations
    int *numbers = pool_alloc(pool, 10 * sizeof(int));
    char *name = pool_alloc(pool, 50);
    double *values = pool_alloc(pool, 5 * sizeof(double));
    
    // Use them
    for (int i = 0; i < 10; i++) numbers[i] = i;
    strcpy(name, "Memory Pool Test");
    for (int i = 0; i < 5; i++) values[i] = i * 1.5;
    
    printf("Numbers: ");
    for (int i = 0; i < 10; i++) printf("%d ", numbers[i]);
    printf("\n");
    
    printf("Name: %s\n", name);
    
    printf("Values: ");
    for (int i = 0; i < 5; i++) printf("%.1f ", values[i]);
    printf("\n");
    
    printf("\nAllocations tracked: %d\n", pool->count);
    
    // Single call frees everything
    pool_destroy(pool);
    printf("Pool destroyed - all memory freed!\n");
    
    return 0;
}
```

### Expected Output
```
Numbers: 0 1 2 3 4 5 6 7 8 9 
Name: Memory Pool Test
Values: 0.0 1.5 3.0 4.5 6.0 

Allocations tracked: 3
Pool destroyed - all memory freed!
```
