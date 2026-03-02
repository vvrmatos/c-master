---
title: Array Assignment
topic: arrays
level: fundamentals
importance: important
---

## Concept

In C, you **cannot** assign one array to another directly:

```c
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];
arr2 = arr1;  // ERROR!
```

This is because array names decay to pointers, and you cannot assign to an array.

To copy arrays, use a loop or `memcpy()`.

## Code

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];
    
    // arr2 = arr1;  // ERROR: arrays cannot be assigned
    
    printf("Cannot do: arr2 = arr1 (compile error)\n\n");
    
    printf("Solution 1: Copy element by element\n");
    for (int i = 0; i < 5; i++) {
        arr2[i] = arr1[i];
    }
    for (int i = 0; i < 5; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }
    
    printf("\nSolution 2: Use memcpy()\n");
    int arr3[5];
    memcpy(arr3, arr1, sizeof(arr1));
    for (int i = 0; i < 5; i++) {
        printf("arr3[%d] = %d\n", i, arr3[i]);
    }
    
    return 0;
}
```

## Output

```
Cannot do: arr2 = arr1 (compile error)

Solution 1: Copy element by element
arr2[0] = 1
arr2[1] = 2
arr2[2] = 3
arr2[3] = 4
arr2[4] = 5

Solution 2: Use memcpy()
arr3[0] = 1
arr3[1] = 2
arr3[2] = 3
arr3[3] = 4
arr3[4] = 5
```

## Key Takeaways

1. `arr2 = arr1` is a compile-time error
2. Array names are not modifiable lvalues
3. Use a for loop to copy element by element
4. Use `memcpy(dest, src, n_bytes)` for efficient copying
5. Structs containing arrays CAN be assigned (whole struct copy)

## Kata Challenge

Write a function `void copy_array(int *dest, int *src, int n)` that copies n elements from src to dest. Test it by copying an array and printing both.
