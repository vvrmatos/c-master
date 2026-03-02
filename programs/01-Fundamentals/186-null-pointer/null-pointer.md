# NULL Pointer - The NULL Concept

## Overview
NULL is a special pointer value that represents "pointing to nothing." It's used to indicate that a pointer doesn't currently reference any valid memory location.

## What is NULL?
```c
#include <stdio.h>  // or <stdlib.h> or <stddef.h>

int *ptr = NULL;  // Pointer to nothing
```

NULL is typically defined as:
```c
#define NULL ((void*)0)  // Common definition
// or
#define NULL 0           // Alternative
```

## Why NULL Matters

### 1. Safe Initialization
```c
int *ptr = NULL;  // Known state, not garbage
```

### 2. Validity Check
```c
if (ptr != NULL) {
    *ptr = 42;  // Safe to use
}
```

### 3. Error/Not-Found Indicator
```c
int *find(int target) {
    // ... search logic ...
    return NULL;  // Not found
}
```

### 4. End Marker
```c
char *strings[] = {"hello", "world", NULL};  // NULL terminates array
```

## Checking for NULL

```c
// All equivalent:
if (ptr != NULL)
if (ptr != 0)
if (ptr)          // Idiomatic C

// All equivalent:
if (ptr == NULL)
if (ptr == 0)
if (!ptr)         // Idiomatic C
```

## NULL vs Uninitialized

| State | Value | Safe to Check? | Safe to Dereference? |
|-------|-------|----------------|----------------------|
| Uninitialized | Garbage | NO | NO |
| NULL | 0/NULL | YES | NO |
| Valid address | 0x... | YES | YES |

## Common NULL Patterns

### Guard Clause
```c
void process(int *data) {
    if (data == NULL) return;  // Guard
    // Safe to use data
}
```

### Allocation Check
```c
int *ptr = malloc(sizeof(int));
if (ptr == NULL) {
    fprintf(stderr, "Allocation failed\n");
    exit(1);
}
```

### Cleanup
```c
free(ptr);
ptr = NULL;  // Prevent use-after-free
```

---

# Kata Challenge: NULL-Safe Functions

## Objective
Write a library of NULL-safe functions that handle pointer operations gracefully.

## Requirements
1. Implement these NULL-safe functions:
   - `safe_print_int(int *ptr)` - Print value or "NULL"
   - `safe_add(int *a, int *b)` - Return sum or indicate NULL
   - `safe_copy(int *dest, int *src)` - Copy only if both valid
   - `safe_compare(int *a, int *b)` - Compare with NULL handling
2. Return appropriate error codes or values
3. Never crash on NULL input

## Example Output
```
=== safe_print_int ===
safe_print_int(&x): 42
safe_print_int(NULL): (null)

=== safe_add ===
safe_add(&a, &b): 30
safe_add(NULL, &b): Error - NULL pointer
safe_add(&a, NULL): Error - NULL pointer

=== safe_copy ===
safe_copy(&dest, &src): Success, dest = 100
safe_copy(NULL, &src): Error - NULL destination

=== safe_compare ===
safe_compare(&x, &y) where x=5, y=10: x < y
safe_compare(NULL, &y): NULL < any value
safe_compare(NULL, NULL): Both NULL, equal
```

## Hints
- Check for NULL before any operation
- Use return values to indicate success/failure
- Consider using output parameters for results

## Bonus
- Implement a NULL-safe linked list
- Create a string function library with NULL handling
- Add logging for NULL encounters
