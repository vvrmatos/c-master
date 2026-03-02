---
title: Array Iteration
topic: arrays
level: fundamentals
importance: essential
---

## Concept

The most common way to iterate over an array is with a **for loop**. Use an index variable that starts at 0 and goes up to (but not including) the array size.

```c
for (int i = 0; i < size; i++) {
    // use arr[i]
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[] = {5, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Forward iteration:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nBackward iteration:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nSum of elements: ");
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    
    return 0;
}
```

## Output

```
Forward iteration:
arr[0] = 5
arr[1] = 10
arr[2] = 15
arr[3] = 20
arr[4] = 25

Backward iteration:
arr[4] = 25
arr[3] = 20
arr[2] = 15
arr[1] = 10
arr[0] = 5

Sum of elements: 75
```

## Key Takeaways

1. Use `i < size` (not `i <= size`) to avoid off-by-one errors
2. Forward loop: `for (i = 0; i < n; i++)`
3. Backward loop: `for (i = n-1; i >= 0; i--)`
4. Always compute size once before loop
5. while loops can also iterate arrays

## Kata Challenge

Write a function that takes an array and its size, then prints only the even-indexed elements (indices 0, 2, 4, ...).
