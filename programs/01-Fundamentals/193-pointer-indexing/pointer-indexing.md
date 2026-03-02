# Pointer Indexing

## Overview
The subscript operator `[]` works identically with both arrays and pointers. This is because `a[i]` is defined as `*(a + i)` in C.

## Key Concepts

### Basic Pointer Indexing
```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;

printf("%d\n", ptr[0]);  // 10
printf("%d\n", ptr[3]);  // 40
```

### The Equivalence
The expression `ptr[i]` is syntactic sugar for `*(ptr + i)`:
```c
ptr[2]      ≡    *(ptr + 2)
arr[3]      ≡    *(arr + 3)
```

### Negative Indexing
Unlike arrays, pointers can use negative indices if they point into the middle of a block:
```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = &arr[2];  // Points to 30

printf("%d\n", ptr[-2]);  // 10
printf("%d\n", ptr[-1]);  // 20
printf("%d\n", ptr[0]);   // 30
printf("%d\n", ptr[1]);   // 40
```

### The Commutative Trick
Since `a[b]` is `*(a + b)`, and addition is commutative:
```c
arr[2] == 2[arr]  // Both equal *(arr + 2)
```
This is valid C but never use it in real code!

## Pointer Movement and Indexing
```c
int *ptr = arr;
ptr += 2;        // Move pointer forward
ptr[0];          // Now refers to arr[2]
ptr[-1];         // Refers to arr[1]
```

## Visual Representation
```
arr:    [10] [20] [30] [40] [50]
index:    0    1    2    3    4

ptr = &arr[2]:
        [-2] [-1] [0]  [1]  [2]
              ↑
             ptr
```

---

# Kata Challenge

## Challenge: Sliding Window with Pointer Indexing

Implement a function that finds the maximum sum of a contiguous subarray of size `k` using pointer indexing.

### Requirements
1. Function signature: `int max_window_sum(int *arr, int size, int k)`
2. Use pointer indexing (`ptr[i]`) not array indexing on original array name
3. Use a sliding window approach
4. Return -1 if k > size

### Example
```c
int data[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
int result = max_window_sum(data, 9, 4);
// Window sums: [1+4+2+10=17], [4+2+10+23=39], [2+10+23+3=38]...
// Max is 39
```

### Bonus Challenge
Implement a function that reverses elements using only pointer indexing and negative indices:
```c
void reverse_via_pointer(int *middle, int half_size);
// middle points to center, use negative and positive indices
```

### Starter Code
```c
#include <stdio.h>

int max_window_sum(int *arr, int size, int k) {
    if (k > size) return -1;
    
    int *ptr = arr;
    // Your code here using ptr[i] notation
    
    return 0;
}

int main(void) {
    int data[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    printf("Max window sum (k=4): %d\n", max_window_sum(data, 9, 4));
    return 0;
}
```

### Expected Output
```
Max window sum (k=4): 39
```
