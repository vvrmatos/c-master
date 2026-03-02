---
title: "Common Loop Mistakes"
topic: "Loops"
level: "fundamental"
program_number: 130
---

## Concept

Common loop errors include off-by-one errors, infinite loops from wrong conditions, and fence-post problems.

| Mistake | Issue |
|---------|-------|
| `i <= size` | One iteration too many |
| `i = 1` start | Misses first element |
| Forgetting update | Infinite loop |
| Wrong comparison | Unexpected termination |

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    /* Off-by-one: accessing arr[5] is undefined */
    printf("Correct (0 to size-1):\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    /* Wrong: <= causes one extra iteration */
    /* for (int i = 0; i <= size; i++) - BUG! */
    
    /* Wrong: starting at 1 misses first element */
    /* for (int i = 1; i < size; i++) - BUG! */
    
    printf("\nFence post: %d items, %d separators\n", size, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
    
    return 0;
}
```

## Output

```
Correct (0 to size-1):
arr[0] = 10
arr[1] = 20
arr[2] = 30
arr[3] = 40
arr[4] = 50

Fence post: 5 items, 4 separators
10, 20, 30, 40, 50
```

## Key Takeaways

1. Arrays are 0-indexed; last index is size-1
2. Use `<` not `<=` with size
3. Fence-post: n items need n-1 separators
4. Test boundary conditions (first, last, empty)
5. Trace through edge cases manually

## Kata Challenge

Write a program that prints array elements with commas but no trailing comma.
