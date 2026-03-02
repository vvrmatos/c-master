---
id: "050"
title: "Format Specifier: %p"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - pointers
  - memory
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 050 — Format Specifier: %p (Pointer)

## Concept

`%p` is the format specifier for printing **pointer values** (memory addresses). It displays the address in an implementation-defined format (typically hexadecimal).

**Key facts:**
- Displays memory addresses
- Argument should be cast to `void*` for portability
- Format is implementation-defined (usually `0x...` hex)
- NULL typically prints as `(nil)`, `0x0`, or `0`

**Usage:**
```c
int x = 42;
printf("%p\n", (void*)&x);  // Print address of x
```

**Why cast to void*:**
- Standard requires `%p` argument to be `void*`
- All pointer types can convert to `void*`
- Avoids warnings with `-Wall`

**Common uses:**
- Debugging memory issues
- Verifying pointer relationships
- Understanding memory layout
- Tracking dynamic allocations
- Analyzing stack/heap locations

**Address Space Concepts:**
| Region | Description |
|--------|-------------|
| Stack | Local variables, grows down |
| Heap | malloc'd memory, grows up |
| Data | Global/static variables |
| Text | Program code (read-only) |

## Code

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("=== Format Specifier: %%p (Pointer) ===\n\n");
    
    int x = 42;
    int *ptr = &x;
    
    printf("Basic pointer output:\n");
    printf("  Value of x: %d\n", x);
    printf("  Address of x (&x): %p\n", (void*)&x);
    printf("  Value of ptr: %p\n", (void*)ptr);
    printf("  Value at ptr (*ptr): %d\n", *ptr);
    
    printf("\nDifferent variable addresses:\n");
    int a = 1;
    int b = 2;
    int c = 3;
    printf("  Address of a: %p\n", (void*)&a);
    printf("  Address of b: %p\n", (void*)&b);
    printf("  Address of c: %p\n", (void*)&c);
    
    printf("\nArray element addresses:\n");
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        printf("  arr[%d] at %p = %d\n", i, (void*)&arr[i], arr[i]);
    }
    
    printf("\nPointer arithmetic:\n");
    int *p = arr;
    printf("  p = %p (points to arr[0])\n", (void*)p);
    printf("  p+1 = %p (points to arr[1])\n", (void*)(p+1));
    printf("  p+2 = %p (points to arr[2])\n", (void*)(p+2));
    printf("  Difference: %ld bytes\n", (char*)(p+1) - (char*)p);
    
    printf("\nDynamic memory addresses:\n");
    int *heap = malloc(sizeof(int) * 3);
    if (heap) {
        printf("  Heap allocation at: %p\n", (void*)heap);
        printf("  heap[0] at: %p\n", (void*)&heap[0]);
        printf("  heap[1] at: %p\n", (void*)&heap[1]);
        printf("  heap[2] at: %p\n", (void*)&heap[2]);
        free(heap);
    }
    
    printf("\nNULL pointer:\n");
    int *null_ptr = NULL;
    printf("  NULL = %p\n", (void*)null_ptr);
    
    printf("\nFunction pointer:\n");
    printf("  Address of main: %p\n", (void*)main);
    printf("  Address of printf: %p\n", (void*)printf);
    
    printf("\nString literal address:\n");
    char *str = "Hello";
    printf("  String \"Hello\" at: %p\n", (void*)str);
    
    printf("\nComparing pointers:\n");
    int *p1 = &arr[0];
    int *p2 = &arr[4];
    printf("  p1 = %p, p2 = %p\n", (void*)p1, (void*)p2);
    printf("  p2 - p1 = %ld elements\n", p2 - p1);
    printf("  p1 < p2? %s\n", p1 < p2 ? "yes" : "no");
    
    return 0;
}
```

## Output

```
=== Format Specifier: %p (Pointer) ===

Basic pointer output:
  Value of x: 42
  Address of x (&x): 0x7ff7b1234abc
  Value of ptr: 0x7ff7b1234abc
  Value at ptr (*ptr): 42

Different variable addresses:
  Address of a: 0x7ff7b1234ab8
  Address of b: 0x7ff7b1234ab4
  Address of c: 0x7ff7b1234ab0

Array element addresses:
  arr[0] at 0x7ff7b1234a90 = 10
  arr[1] at 0x7ff7b1234a94 = 20
  arr[2] at 0x7ff7b1234a98 = 30
  arr[3] at 0x7ff7b1234a9c = 40
  arr[4] at 0x7ff7b1234aa0 = 50

Pointer arithmetic:
  p = 0x7ff7b1234a90 (points to arr[0])
  p+1 = 0x7ff7b1234a94 (points to arr[1])
  p+2 = 0x7ff7b1234a98 (points to arr[2])
  Difference: 4 bytes

Dynamic memory addresses:
  Heap allocation at: 0x600001234000
  heap[0] at: 0x600001234000
  heap[1] at: 0x600001234004
  heap[2] at: 0x600001234008

NULL pointer:
  NULL = (nil)

Function pointer:
  Address of main: 0x100003f00
  Address of printf: 0x7ff812345678

String literal address:
  String "Hello" at: 0x100004000

Comparing pointers:
  p1 = 0x7ff7b1234a90, p2 = 0x7ff7b1234aa0
  p2 - p1 = 4 elements
  p1 < p2? yes
```

## Compilation

```bash
gcc 050-format-specifier-p.c -o 050-format-specifier-p
./050-format-specifier-p
```

## Key Takeaways

- `%p` prints memory addresses (pointers)
- Always cast to `(void*)` for portability
- Addresses are typically shown in hexadecimal
- Array elements are contiguous in memory
- Pointer arithmetic accounts for type size
- Understanding addresses is crucial for debugging

## Challenge

Write a program that compares stack addresses vs heap addresses to visualize where each resides in memory.

## Related

- [[049-format-specifier-x-X-o]] — Hex/octal formats
- [[055-printf-return-value]] — printf return value
