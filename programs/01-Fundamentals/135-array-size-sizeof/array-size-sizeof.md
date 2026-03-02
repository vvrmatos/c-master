---
title: Array Size with sizeof
topic: arrays
level: fundamentals
importance: essential
---

## Concept

To get the number of elements in an array, divide the total array size by the size of one element:

```c
size_t count = sizeof(arr) / sizeof(arr[0]);
```

This idiom only works when `arr` is an actual array, **not** a pointer.

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    
    size_t total_bytes = sizeof(arr);
    size_t element_bytes = sizeof(arr[0]);
    size_t count = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: {10, 20, 30, 40, 50}\n\n");
    printf("sizeof(arr)    = %zu bytes (total array size)\n", total_bytes);
    printf("sizeof(arr[0]) = %zu bytes (one int)\n", element_bytes);
    printf("Element count  = %zu / %zu = %zu\n", 
           total_bytes, element_bytes, count);
    
    double doubles[] = {1.1, 2.2, 3.3};
    printf("\nDouble array: %zu elements\n", 
           sizeof(doubles) / sizeof(doubles[0]));
    
    return 0;
}
```

## Output

```
Array: {10, 20, 30, 40, 50}

sizeof(arr)    = 20 bytes (total array size)
sizeof(arr[0]) = 4 bytes (one int)
Element count  = 20 / 4 = 5

Double array: 3 elements
```

## Key Takeaways

1. `sizeof(arr)` gives total bytes of the array
2. `sizeof(arr[0])` gives bytes of one element
3. The idiom fails with pointers (decayed arrays)
4. Use `%zu` format specifier for `size_t`
5. Consider a macro: `#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))`

## Kata Challenge

Create a macro `ARRAY_LEN(arr)` that computes array length. Test it with arrays of `int`, `char`, and `double`.
