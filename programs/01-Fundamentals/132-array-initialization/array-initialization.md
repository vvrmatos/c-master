---
title: Array Initialization
topic: arrays
level: fundamentals
importance: essential
---

## Concept

Arrays can be initialized at declaration using a brace-enclosed list. When you provide an initializer list, the compiler can automatically determine the array size.

```c
int arr[] = {1, 2, 3};      // Size is 3, inferred
int nums[5] = {1, 2, 3, 4, 5};  // Explicit size
```

## Code

```c
#include <stdio.h>

int main(void) {
    int arr[] = {1, 2, 3};
    int nums[5] = {10, 20, 30, 40, 50};
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    
    printf("arr: %d, %d, %d\n", arr[0], arr[1], arr[2]);
    printf("nums: %d, %d, %d, %d, %d\n", 
           nums[0], nums[1], nums[2], nums[3], nums[4]);
    printf("vowels: %c, %c, %c, %c, %c\n", 
           vowels[0], vowels[1], vowels[2], vowels[3], vowels[4]);
    
    return 0;
}
```

## Output

```
arr: 1, 2, 3
nums: 10, 20, 30, 40, 50
vowels: a, e, i, o, u
```

## Key Takeaways

1. `int arr[] = {1,2,3}` lets compiler count elements
2. Initialization happens once at declaration
3. Cannot use `arr = {1,2,3}` after declaration
4. Brace-enclosed initializer lists set values in order
5. Works with all basic types (int, char, float, etc.)

## Kata Challenge

Initialize an array of 6 prime numbers without specifying the size. Print the array and verify the compiler determined the correct size.
