---
title: Designated Initializers
topic: arrays
level: fundamentals
importance: important
---

## Concept

C99 introduced **designated initializers** that let you specify which indices to initialize:

```c
int arr[5] = {[2] = 100, [4] = 200};
```

This sets `arr[2]` to 100 and `arr[4]` to 200. Unspecified elements are zero.

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[5] = {[2] = 100, [4] = 200};
    
    printf("int arr[5] = {[2] = 100, [4] = 200};\n\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nMixed initialization:\n");
    int mixed[6] = {1, 2, [4] = 99, 100};
    for (int i = 0; i < 6; i++) {
        printf("mixed[%d] = %d\n", i, mixed[i]);
    }
    
    printf("\nSkipping elements:\n");
    int sparse[10] = {[0] = 1, [5] = 5, [9] = 9};
    for (int i = 0; i < 10; i++) {
        printf("sparse[%d] = %d\n", i, sparse[i]);
    }
    
    return 0;
}
```

## Output

```
int arr[5] = {[2] = 100, [4] = 200};

arr[0] = 0
arr[1] = 0
arr[2] = 100
arr[3] = 0
arr[4] = 200

Mixed initialization:
mixed[0] = 1
mixed[1] = 2
mixed[2] = 0
mixed[3] = 0
mixed[4] = 99
mixed[5] = 100

Skipping elements:
sparse[0] = 1
sparse[1] = 0
sparse[2] = 0
sparse[3] = 0
sparse[4] = 0
sparse[5] = 5
sparse[6] = 0
sparse[7] = 0
sparse[8] = 0
sparse[9] = 9
```

## Key Takeaways

1. Syntax: `[index] = value`
2. Can mix designated and sequential initializers
3. After `[n] = x`, next value goes to index n+1
4. Unspecified indices are zero-initialized
5. C99 feature (not available in C89)

## Kata Challenge

Use designated initializers to create an array where only indices 0, 3, 7 have non-zero values (use values 10, 30, 70). Print all elements.
