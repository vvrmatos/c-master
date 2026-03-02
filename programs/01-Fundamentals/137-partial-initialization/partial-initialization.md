---
title: Partial Initialization
topic: arrays
level: fundamentals
importance: important
---

## Concept

When an array is partially initialized (fewer initializers than elements), the remaining elements are automatically set to **zero** (or null for pointers).

```c
int arr[5] = {1, 2};  // arr = {1, 2, 0, 0, 0}
int zeros[100] = {0}; // all 100 elements are 0
```

This is a reliable way to zero-initialize arrays.

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[5] = {1, 2};
    
    printf("int arr[5] = {1, 2};\n\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nZero-initialize all elements:\n");
    int zeros[5] = {0};
    for (int i = 0; i < 5; i++) {
        printf("zeros[%d] = %d\n", i, zeros[i]);
    }
    
    printf("\nPartial char array:\n");
    char chars[4] = {'A', 'B'};
    for (int i = 0; i < 4; i++) {
        printf("chars[%d] = '%c' (%d)\n", i, chars[i], chars[i]);
    }
    
    return 0;
}
```

## Output

```
int arr[5] = {1, 2};

arr[0] = 1
arr[1] = 2
arr[2] = 0
arr[3] = 0
arr[4] = 0

Zero-initialize all elements:
zeros[0] = 0
zeros[1] = 0
zeros[2] = 0
zeros[3] = 0
zeros[4] = 0

Partial char array:
chars[0] = 'A' (65)
chars[1] = 'B' (66)
chars[2] = '' (0)
chars[3] = '' (0)
```

## Key Takeaways

1. Missing initializers default to zero
2. `{0}` is idiomatic for zeroing entire arrays
3. Works for all types: int, char, float, pointers
4. Empty braces `{}` are not valid in standard C (but `{0}` is)
5. Different from uninitialized arrays (which have garbage)

## Kata Challenge

Declare an array of 10 floats, initialize only the first three to 1.5, 2.5, 3.5. Print all elements and verify the rest are 0.0.
