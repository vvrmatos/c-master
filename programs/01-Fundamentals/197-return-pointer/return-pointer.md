# Return Pointer

## Overview
Functions can return pointers to give callers access to data. However, you must be careful about what the pointer points to—returning a pointer to a local variable is a classic bug in C.

## Key Concepts

### Safe Ways to Return Pointers

**1. Pointer to Static Variable:**
```c
int *get_counter(void) {
    static int count = 0;
    count++;
    return &count;
}
```
Safe but the data is shared across all calls.

**2. Pointer to Heap Memory:**
```c
int *create_int(int value) {
    int *p = malloc(sizeof(int));
    if (p) *p = value;
    return p;  // Caller must free
}
```

**3. Pointer Within Passed Parameter:**
```c
int *find_max(int *arr, int size) {
    int *max = arr;
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) max = &arr[i];
    }
    return max;  // Points within arr
}
```

**4. Pointer to Global Variable:**
```c
int global_data;
int *get_global(void) {
    return &global_data;
}
```

### Dangerous: Returning Pointer to Local
```c
int *bad_function(void) {
    int local = 42;
    return &local;  // DANGER! Undefined behavior
}
```
The local variable is destroyed when the function returns, leaving a dangling pointer.

### Return NULL on Failure
```c
int *find(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return &arr[i];
    }
    return NULL;  // Not found
}
```

## Memory Lifetime Summary
| Source | Lifetime | Safe to Return? |
|--------|----------|-----------------|
| Local variable | Function scope | NO |
| Static variable | Program lifetime | Yes (shared) |
| Heap (malloc) | Until free() | Yes (caller frees) |
| Parameter data | Caller controls | Yes (if caller keeps) |
| Global | Program lifetime | Yes |

---

# Kata Challenge

## Challenge: String Builder

Create a string builder that dynamically constructs strings and returns a pointer to the result.

### Requirements
1. Function: `char *build_greeting(const char *name, int times)`
2. Creates a string like "Hello, Alice! Hello, Alice! Hello, Alice!"
3. Number of repetitions based on `times` parameter
4. Must allocate exact memory needed (no waste)
5. Caller is responsible for freeing the memory
6. Return NULL if allocation fails or times <= 0

### Example
```c
char *msg = build_greeting("World", 3);
// Returns: "Hello, World! Hello, World! Hello, World!"
printf("%s\n", msg);
free(msg);
```

### Hints
- Calculate total length first: `strlen("Hello, ") + strlen(name) + strlen("! ")` × times
- Use `malloc` for allocation
- Use `strcat` or pointer arithmetic to build

### Bonus Challenge
Create `char *join_strings(char **strings, int count, const char *separator)` that joins an array of strings with a separator:
```c
char *words[] = {"apple", "banana", "cherry"};
char *result = join_strings(words, 3, ", ");
// Returns: "apple, banana, cherry"
```

### Starter Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *build_greeting(const char *name, int times) {
    if (times <= 0) return NULL;
    
    // Calculate needed size
    // "Hello, " + name + "! " = base length per repetition
    
    // Your code here
    
    return NULL;
}

int main(void) {
    char *msg = build_greeting("World", 3);
    
    if (msg) {
        printf("Result: %s\n", msg);
        printf("Length: %lu\n", strlen(msg));
        free(msg);
    } else {
        printf("Failed to build string\n");
    }
    
    return 0;
}
```

### Expected Output
```
Result: Hello, World! Hello, World! Hello, World! 
Length: 42
```
