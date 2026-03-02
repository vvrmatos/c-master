---
id: "089"
title: "Pointer Casting Basics"
category: "01-Fundamentals"
tags: ["pointers", "casting", "void-pointer", "generic"]
difficulty: "intermediate"
---

# Pointer Casting Basics

## Concept

`void*` is C's generic pointer type—it can hold the address of any data type. This enables generic programming patterns.

**Rules**:
- Any pointer can be implicitly converted to `void*`
- `void*` can be implicitly converted back to any pointer type
- You cannot dereference a `void*` directly (no known type)
- Casting to the wrong type is undefined behavior

**Use cases**:
- Generic functions (like `qsort`, `memcpy`)
- Memory allocation (`malloc` returns `void*`)
- Callback functions with user data

## Code

```c
// Pointer casting basics - void*

#include <stdio.h>

int main(void) {
    int x = 42;
    double d = 3.14;
    
    // Any pointer can convert to void*
    void *vp = &x;
    printf("int address: %p\n", vp);
    
    // void* can convert back to original type
    int *ip = vp;
    printf("Value via int*: %d\n", *ip);
    
    // void* to different pointer - works but dangerous!
    vp = &d;
    double *dp = vp;
    printf("Value via double*: %.2f\n", *dp);
    
    // Generic swap using void* (concept preview)
    printf("\nBefore swap: x=%d\n", x);
    int temp = 100;
    vp = &temp;
    ip = vp;
    printf("Temp via void*: %d\n", *ip);
    
    // Warning: casting to wrong type = undefined behavior
    // int *wrong = (int*)&d;  // Compiles but UB if dereferenced
    
    return 0;
}
```

## Output

```
int address: 0x7ffeefbff4bc
Value via int*: 42
Value via double*: 3.14
Temp via void*: 100
```

## Key Takeaways

1. `void*` is a generic pointer that can hold any data address
2. Conversion to/from `void*` is implicit in C (explicit in C++)
3. Cannot dereference `void*` directly—must cast first
4. Casting to wrong type causes undefined behavior
5. `void*` is used throughout the C standard library

## Kata Challenge

**Generic Print Function**

Write a function that prints values of different types using a void pointer and a type indicator:

```c
// Your solution here
// void print_value(void *ptr, char type);
// type: 'i' = int, 'f' = float, 'd' = double, 'c' = char

// Usage:
// int x = 42;
// float f = 3.14f;
// char c = 'A';
// print_value(&x, 'i');  // prints: 42
// print_value(&f, 'f');  // prints: 3.14
// print_value(&c, 'c');  // prints: A
```

Hint: Inside the function, cast the void pointer based on the type character.
