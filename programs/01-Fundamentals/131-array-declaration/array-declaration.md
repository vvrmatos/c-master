---
title: Array Declaration
topic: arrays
level: fundamentals
importance: essential
---

## Concept

An **array** is a collection of elements of the same type stored in contiguous memory locations. To declare an array, specify the type, name, and size in square brackets.

```c
type name[size];
```

The size must be a positive integer constant (or compile-time constant expression).

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[5];
    
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    printf("Array elements:\n");
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);
    printf("arr[2] = %d\n", arr[2]);
    printf("arr[3] = %d\n", arr[3]);
    printf("arr[4] = %d\n", arr[4]);
    
    return 0;
}
```

## Output

```
Array elements:
arr[0] = 10
arr[1] = 20
arr[2] = 30
arr[3] = 40
arr[4] = 50
```

## Key Takeaways

1. Arrays are declared with `type name[size]`
2. Array indices start at 0 and end at size-1
3. Uninitialized arrays contain garbage values
4. Array size must be known at compile time (for static arrays)
5. Memory is allocated contiguously

## Kata Challenge

Declare an array of 7 `double` values representing daily temperatures. Assign values to each element and print them.
