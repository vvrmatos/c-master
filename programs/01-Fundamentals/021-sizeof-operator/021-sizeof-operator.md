---
id: "021"
title: "The sizeof Operator"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - sizeof
  - operators
  - data-types
  - memory
difficulty: beginner
source: "C11 Standard 6.5.3.4"
---

# 021 — The sizeof Operator

## Concept

`sizeof` is a **compile-time operator** that returns the size of a type or variable in bytes. It's essential for:

- Memory allocation (`malloc(sizeof(struct Node))`)
- Array element counting (`sizeof(arr) / sizeof(arr[0])`)
- Portable code across different platforms

**Syntax:**
```c
sizeof(type)      // Parentheses required for types
sizeof expression // Parentheses optional for expressions
sizeof(variable)  // Common style: always use parentheses
```

**Key facts:**
- Returns type `size_t` (unsigned integer)
- Use `%zu` format specifier for printing
- Evaluated at compile time (no runtime overhead)
- `sizeof(char)` is **always** 1 by definition
- For arrays: returns total bytes, not element count
- For pointers: returns pointer size, not what it points to

**Common pattern for array length:**
```c
int arr[10];
size_t len = sizeof(arr) / sizeof(arr[0]);  // = 10
```

**Warning:** This pattern fails with function parameters:
```c
void func(int arr[]) {
    // sizeof(arr) gives pointer size, not array size!
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int i = 42;
    double d = 3.14159;
    char c = 'A';
    char str[] = "Hello";
    int arr[10];
    
    printf("=== The sizeof Operator ===\n\n");
    
    printf("sizeof on fundamental types:\n");
    printf("  sizeof(char)        = %zu byte\n", sizeof(char));
    printf("  sizeof(short)       = %zu bytes\n", sizeof(short));
    printf("  sizeof(int)         = %zu bytes\n", sizeof(int));
    printf("  sizeof(long)        = %zu bytes\n", sizeof(long));
    printf("  sizeof(long long)   = %zu bytes\n", sizeof(long long));
    printf("  sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("  sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("  sizeof(long double) = %zu bytes\n", sizeof(long double));
    
    printf("\nsizeof on variables:\n");
    printf("  sizeof(i) = %zu bytes (int)\n", sizeof(i));
    printf("  sizeof(d) = %zu bytes (double)\n", sizeof(d));
    printf("  sizeof(c) = %zu byte (char)\n", sizeof(c));
    
    printf("\nsizeof on arrays:\n");
    printf("  sizeof(str) = %zu bytes (includes null terminator)\n", sizeof(str));
    printf("  sizeof(arr) = %zu bytes (10 ints)\n", sizeof(arr));
    printf("  Number of elements in arr: %zu\n", sizeof(arr) / sizeof(arr[0]));
    
    printf("\nsizeof on pointers:\n");
    printf("  sizeof(int *)    = %zu bytes\n", sizeof(int *));
    printf("  sizeof(char *)   = %zu bytes\n", sizeof(char *));
    printf("  sizeof(double *) = %zu bytes\n", sizeof(double *));
    printf("  sizeof(void *)   = %zu bytes\n", sizeof(void *));
    
    printf("\nCompile-time vs runtime:\n");
    printf("  sizeof is evaluated at compile time (mostly)\n");
    printf("  Result type is size_t (use %%zu format specifier)\n");
    
    return 0;
}
```

## Output

```
=== The sizeof Operator ===

sizeof on fundamental types:
  sizeof(char)        = 1 byte
  sizeof(short)       = 2 bytes
  sizeof(int)         = 4 bytes
  sizeof(long)        = 8 bytes
  sizeof(long long)   = 8 bytes
  sizeof(float)       = 4 bytes
  sizeof(double)      = 8 bytes
  sizeof(long double) = 16 bytes

sizeof on variables:
  sizeof(i) = 4 bytes (int)
  sizeof(d) = 8 bytes (double)
  sizeof(c) = 1 byte (char)

sizeof on arrays:
  sizeof(str) = 6 bytes (includes null terminator)
  sizeof(arr) = 40 bytes (10 ints)
  Number of elements in arr: 10

sizeof on pointers:
  sizeof(int *)    = 8 bytes
  sizeof(char *)   = 8 bytes
  sizeof(double *) = 8 bytes
  sizeof(void *)   = 8 bytes

Compile-time vs runtime:
  sizeof is evaluated at compile time (mostly)
  Result type is size_t (use %zu format specifier)
```

## Key Takeaways

- `sizeof` returns size in bytes, evaluated at compile time
- Use `%zu` format specifier for `size_t` return type
- `sizeof(char)` is always 1 by definition
- All pointer types have the same size on a given platform
- Use `sizeof(arr)/sizeof(arr[0])` to count array elements
- This pattern fails when arrays decay to pointers in functions

## Challenge

Create a macro `ARRAY_LEN(arr)` that calculates array length safely. Research how to add a compile-time check that fails if passed a pointer instead of an array.

## Related

- [[012-integer-variants]] — Integer sizes
- [[016-floating-point-float]] — Float sizes
- [[022-integer-limits]] — Limit constants
