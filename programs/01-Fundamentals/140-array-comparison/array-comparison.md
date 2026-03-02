---
title: Array Comparison
topic: arrays
level: fundamentals
importance: important
---

## Concept

You **cannot** compare arrays directly with `==`:

```c
if (arr1 == arr2)  // WRONG! Compares addresses, not content
```

Array names decay to pointers, so this compares memory addresses, which are always different for distinct arrays.

To compare arrays, loop through elements or use `memcmp()`.

## Code

```c
#include <stdio.h>
#include <string.h>

int arrays_equal(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {1, 2, 3, 4, 9};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("arr1 == arr2 compares addresses, not content!\n");
    printf("arr1 == arr2: %s\n\n", arr1 == arr2 ? "true" : "false");
    
    printf("Correct: Compare element by element\n");
    printf("arrays_equal(arr1, arr2): %s\n", 
           arrays_equal(arr1, arr2, size) ? "true" : "false");
    printf("arrays_equal(arr1, arr3): %s\n", 
           arrays_equal(arr1, arr3, size) ? "true" : "false");
    
    printf("\nUsing memcmp():\n");
    printf("memcmp(arr1, arr2, size): %d (0 = equal)\n", 
           memcmp(arr1, arr2, sizeof(arr1)));
    printf("memcmp(arr1, arr3, size): %d (non-zero = different)\n", 
           memcmp(arr1, arr3, sizeof(arr1)));
    
    return 0;
}
```

## Output

```
arr1 == arr2 compares addresses, not content!
arr1 == arr2: false

Correct: Compare element by element
arrays_equal(arr1, arr2): true
arrays_equal(arr1, arr3): false

Using memcmp():
memcmp(arr1, arr2, size): 0 (0 = equal)
memcmp(arr1, arr3, size): -1 (non-zero = different)
```

## Key Takeaways

1. `==` compares addresses, not array contents
2. Write a loop to compare elements
3. `memcmp(a, b, n)` returns 0 if n bytes are equal
4. memcmp compares byte-by-byte (safe for integers)
5. Always ensure arrays have same size before comparing

## Kata Challenge

Write a function `int find_diff_index(int a[], int b[], int size)` that returns the first index where arrays differ, or -1 if they are equal.
