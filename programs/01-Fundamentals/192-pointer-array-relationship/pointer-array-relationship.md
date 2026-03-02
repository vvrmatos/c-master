# Pointer-Array Relationship

## Overview
In C, arrays and pointers are closely related. In most expressions, an array name "decays" into a pointer to its first element. Understanding this relationship is fundamental to mastering C.

## Key Concepts

### Array Decay
When an array name is used in an expression, it typically converts to a pointer:
```c
int arr[] = {10, 20, 30};
int *ptr = arr;  // arr decays to &arr[0]
```

### Equivalence
These expressions are equivalent:
```c
arr[i]    ≡    *(arr + i)
&arr[i]   ≡    arr + i
*arr      ≡    arr[0]
```

### When Arrays Don't Decay
Arrays retain their array type in these contexts:
1. `sizeof(arr)` - returns full array size
2. `&arr` - address of the entire array
3. String literal initializers

```c
int arr[5];
printf("%lu\n", sizeof(arr));   // 20 (5 * 4 bytes)

int *ptr = arr;
printf("%lu\n", sizeof(ptr));   // 8 (pointer size)
```

### Function Parameters
Arrays always decay when passed to functions:
```c
void func(int arr[]);    // Actually int *arr
void func(int arr[10]);  // Still just int *arr
void func(int *arr);     // Explicit pointer
```

## Memory Layout
```
Array in memory:
arr: [10][20][30][40][50]
      ^
      |
     arr (decays to this address)
     &arr[0] (same address)
```

## Important Distinctions

| Aspect | Array | Pointer |
|--------|-------|---------|
| `sizeof` | Full array size | Pointer size (8 bytes) |
| Assignment | Not assignable | Assignable |
| Address | Stack allocated | Points anywhere |
| `&` operator | Array pointer type | Pointer to pointer |

---

# Kata Challenge

## Challenge: Prove the Decay

Write a program that demonstrates and verifies array-pointer equivalence through multiple tests.

### Requirements
1. Create an array of 5 integers
2. Prove these equivalences with assertions or conditional checks:
   - `arr == &arr[0]`
   - `*arr == arr[0]`
   - `arr + 2 == &arr[2]`
   - `*(arr + 3) == arr[3]`
3. Show the difference between `sizeof(arr)` and `sizeof(ptr)`
4. Demonstrate decay when passing to a function

### Example Output
```
Test 1: arr == &arr[0] ? PASS
Test 2: *arr == arr[0] ? PASS
Test 3: arr + 2 == &arr[2] ? PASS
Test 4: *(arr + 3) == arr[3] ? PASS
sizeof(arr) = 20 bytes
sizeof(ptr) = 8 bytes
In function, sizeof(param) = 8 (decayed!)
```

### Bonus Challenge
Create a function that can determine if it received an array or pointer (trick question - explain why this is impossible).

### Starter Code
```c
#include <stdio.h>

void check_size(int param[]) {
    // What is sizeof(param) here?
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    // Your tests here
    return 0;
}
```
