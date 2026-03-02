# 150 - Array Function Parameters: Arrays Decay to Pointers

## Overview
When you pass an array to a function in C, it **decays** to a pointer to its first element. This is a fundamental concept that affects how you write functions that work with arrays.

## Array Decay

```c
int arr[5] = {1, 2, 3, 4, 5};

// In main:
sizeof(arr)  // Returns 20 (5 * sizeof(int))

// When passed to function:
void func(int arr[]) {
    sizeof(arr)  // Returns 8 (pointer size on 64-bit)
}
```

## Equivalent Function Declarations

```c
// These are ALL equivalent for 1D arrays:
void func(int arr[]);
void func(int arr[5]);    // The 5 is ignored!
void func(int *arr);
```

## Why Size is Lost

```c
void process(int arr[]) {
    // Cannot determine array size here
    // Must pass size as separate parameter
}

// Correct approach:
void process(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        // ...
    }
}
```

## 2D Array Parameters

```c
// Must specify all dimensions except first:
void func(int matrix[][4], int rows);      // OK
void func(int matrix[][4][5], int depth);  // OK for 3D

// Using pointer syntax:
void func(int (*matrix)[4], int rows);     // Pointer to array of 4 ints

// VLA syntax (C99):
void func(int rows, int cols, int matrix[rows][cols]);
```

## Common Patterns

```c
// Pattern 1: Pass size explicitly
void sum_array(int *arr, size_t n);

// Pattern 2: Use sentinel value
void print_strings(char *strings[]);  // NULL-terminated

// Pattern 3: Pass pointer to end
void process(int *begin, int *end);
```

## The `static` Keyword in Parameters

```c
// Tells compiler arr has at least 10 elements
void func(int arr[static 10]) {
    // Compiler may optimize based on this
}
```

---

# Kata Challenge

## Challenge: Generic Array Statistics
Write a set of functions that work with arrays passed as parameters:

1. `double average(int *arr, int size)` - calculate average
2. `int find_max(int arr[], int size)` - find maximum value
3. `void reverse(int *arr, int size)` - reverse in place
4. `int count_if(int arr[], int size, int (*predicate)(int))` - count elements matching condition

## Requirements
- Demonstrate array decay by printing sizeof in main vs function
- Use both `arr[]` and `*arr` syntax
- Handle edge cases (empty array, size 1)

## Expected Output
```
Array: 5 3 8 1 9 2 7
In main: sizeof(arr) = 28 bytes
In function: sizeof(arr) = 8 bytes (pointer)

Average: 5.00
Maximum: 9
After reverse: 7 2 9 1 8 3 5
Even numbers: 2
```

## Predicate Example
```c
int is_even(int x) {
    return x % 2 == 0;
}

int count = count_if(arr, size, is_even);
```

## Bonus
- Implement for 2D arrays
- Add `void transform(int *arr, int size, int (*func)(int))`
