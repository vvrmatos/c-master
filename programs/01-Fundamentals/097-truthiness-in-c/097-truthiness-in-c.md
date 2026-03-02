---
id: "097"
title: "Truthiness in C"
category: "01-Fundamentals"
tags: ["boolean", "truthiness", "zero", "non-zero", "conditions"]
difficulty: "beginner"
---

# Truthiness in C

## Concept

C doesn't have a native boolean type (before C99). Instead:
- **Zero (0)** is considered **false**
- **Any non-zero value** is considered **true**

This applies to:
- Integers: `0` is false, any other value is true
- Pointers: `NULL` (0) is false, any valid address is true
- Characters: `'\0'` is false, any other char is true
- Floating-point: `0.0` is false, any other value is true

## Code

```c
// Truthiness in C: 0 is false, non-zero is true

#include <stdio.h>

int main(void) {
    // Integer truth values
    printf("Integer truthiness:\n");
    printf("if (0)  -> %s\n", 0 ? "true" : "false");
    printf("if (1)  -> %s\n", 1 ? "true" : "false");
    printf("if (-1) -> %s\n", -1 ? "true" : "false");
    printf("if (42) -> %s\n", 42 ? "true" : "false");
    
    // Pointers
    printf("\nPointer truthiness:\n");
    int x = 10;
    int *ptr = &x;
    int *null_ptr = NULL;
    printf("if (ptr)      -> %s\n", ptr ? "true" : "false");
    printf("if (null_ptr) -> %s\n", null_ptr ? "true" : "false");
    
    // Characters
    printf("\nCharacter truthiness:\n");
    printf("if ('A') -> %s\n", 'A' ? "true" : "false");
    printf("if ('\\0') -> %s\n", '\0' ? "true" : "false");
    
    // Floating point
    printf("\nFloat truthiness:\n");
    printf("if (0.0)   -> %s\n", 0.0 ? "true" : "false");
    printf("if (0.001) -> %s\n", 0.001 ? "true" : "false");
    
    // Common idiom: loop until zero
    int count = 3;
    printf("\nCountdown: ");
    while (count) {
        printf("%d ", count);
        count--;
    }
    printf("\n");
    
    return 0;
}
```

## Output

```
Integer truthiness:
if (0)  -> false
if (1)  -> true
if (-1) -> true
if (42) -> true

Pointer truthiness:
if (ptr)      -> true
if (null_ptr) -> false

Character truthiness:
if ('A') -> true
if ('\0') -> false

Float truthiness:
if (0.0)   -> false
if (0.001) -> true

Countdown: 3 2 1 
```

## Key Takeaways

1. Zero is the only false value in C
2. Any non-zero value is true (including negative numbers)
3. NULL pointers are false, valid pointers are true
4. The null character `'\0'` is false
5. Comparison operators return 0 or 1, not just any non-zero

## Kata Challenge

**Truthy Value Counter**

Write a function that counts how many elements in an array are "truthy":

```c
// Your solution here
// int count_truthy(int arr[], int size);
// Returns count of non-zero elements

// Test case:
// int arr[] = {0, 1, -1, 0, 42, 0, 7};
// count_truthy(arr, 7) -> 4

// Bonus: Write for an array of pointers
// int count_non_null(void *arr[], int size);
```

Hint: Just use `if (arr[i])` to check truthiness.
