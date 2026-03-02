---
title: Array Access
topic: arrays
level: fundamentals
importance: essential
---

## Concept

Array elements are accessed using the **subscript operator** `[]` with an index. Indices are zero-based, meaning the first element is at index 0.

```c
arr[0]  // first element
arr[n-1] // last element (for array of size n)
```

Elements can be read and written using the same syntax.

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[] = {100, 200, 300, 400, 500};
    
    printf("First element:  arr[0] = %d\n", arr[0]);
    printf("Second element: arr[1] = %d\n", arr[1]);
    printf("Last element:   arr[4] = %d\n", arr[4]);
    
    arr[2] = 999;
    printf("\nAfter arr[2] = 999:\n");
    printf("Third element:  arr[2] = %d\n", arr[2]);
    
    int index = 3;
    printf("\nUsing variable index=%d: arr[%d] = %d\n", 
           index, index, arr[index]);
    
    return 0;
}
```

## Output

```
First element:  arr[0] = 100
Second element: arr[1] = 200
Last element:   arr[4] = 500

After arr[2] = 999:
Third element:  arr[2] = 999

Using variable index=3: arr[3] = 400
```

## Key Takeaways

1. Array indexing starts at 0, not 1
2. `arr[i]` reads the value at index i
3. `arr[i] = value` writes to index i
4. Index can be a variable or expression
5. `arr[i]` is equivalent to `*(arr + i)` (pointer arithmetic)

## Kata Challenge

Create an array of 5 integers. Swap the first and last elements using array access. Print the array before and after the swap.
