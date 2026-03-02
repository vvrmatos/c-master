---
title: Array Bounds
topic: arrays
level: fundamentals
importance: critical
---

## Concept

C does **not** perform bounds checking on array accesses. Accessing elements outside the valid range (0 to size-1) causes **undefined behavior**.

This can lead to:
- Reading garbage values
- Overwriting other variables
- Security vulnerabilities (buffer overflow)
- Crashes or silent data corruption

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[3] = {10, 20, 30};
    
    printf("Valid indices:\n");
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);
    printf("arr[2] = %d\n", arr[2]);
    
    printf("\n--- WARNING: Out of bounds access ---\n");
    printf("arr[-1] = %d (undefined behavior!)\n", arr[-1]);
    printf("arr[3]  = %d (undefined behavior!)\n", arr[3]);
    printf("arr[10] = %d (undefined behavior!)\n", arr[10]);
    
    printf("\nC does NOT check array bounds!\n");
    printf("Always ensure: 0 <= index < array_size\n");
    
    return 0;
}
```

## Output

```
Valid indices:
arr[0] = 10
arr[1] = 20
arr[2] = 30

--- WARNING: Out of bounds access ---
arr[-1] = <garbage> (undefined behavior!)
arr[3]  = <garbage> (undefined behavior!)
arr[10] = <garbage> (undefined behavior!)

C does NOT check array bounds!
Always ensure: 0 <= index < array_size
```

## Key Takeaways

1. C has NO runtime bounds checking
2. Accessing `arr[n]` for `arr[n]` (size n) is undefined behavior
3. Negative indices are also undefined behavior
4. Buffer overflows are a major security vulnerability
5. Always validate indices before array access

## Kata Challenge

Write a safe array access function `int safe_get(int arr[], int size, int index)` that returns -1 if the index is out of bounds, or the element value if valid.
