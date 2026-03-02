---
id: "100"
title: "C99 bool Type"
category: "01-Fundamentals"
tags: ["boolean", "stdbool", "bool", "true", "false", "C99"]
difficulty: "beginner"
---

# C99 bool Type

## Concept

C99 introduced a proper boolean type. Including `<stdbool.h>` provides:

- **`bool`**: A boolean type (alias for `_Bool`)
- **`true`**: Defined as 1
- **`false`**: Defined as 0

**Key points**:
- `_Bool` is a built-in type since C99 (even without header)
- `<stdbool.h>` adds the convenient `bool`, `true`, `false` macros
- Assigning any non-zero value to bool converts it to 1
- `sizeof(bool)` is typically 1 byte

## Code

```c
// C99 bool type from stdbool.h

#include <stdio.h>
#include <stdbool.h>

bool is_even(int n) {
    return n % 2 == 0;
}

bool is_positive(int n) {
    return n > 0;
}

int main(void) {
    // bool type with true/false keywords
    bool flag = true;
    printf("flag = %d\n", flag);
    
    flag = false;
    printf("flag = %d\n", flag);
    
    // bool in conditions
    bool is_valid = true;
    if (is_valid) {
        printf("\nData is valid\n");
    }
    
    // Functions returning bool
    printf("\n5 is even: %s\n", is_even(5) ? "true" : "false");
    printf("6 is even: %s\n", is_even(6) ? "true" : "false");
    
    // bool stores 0 or 1
    bool b = 42;  // Any non-zero becomes 1
    printf("\nbool b = 42 -> %d\n", b);
    
    b = -1;  // Negative non-zero also becomes 1
    printf("bool b = -1 -> %d\n", b);
    
    // sizeof bool
    printf("\nsizeof(bool) = %zu\n", sizeof(bool));
    printf("sizeof(_Bool) = %zu\n", sizeof(_Bool));
    
    return 0;
}
```

## Output

```
flag = 1
flag = 0

Data is valid

5 is even: false
6 is even: true

bool b = 42 -> 1
bool b = -1 -> 1

sizeof(bool) = 1
sizeof(_Bool) = 1
```

## Key Takeaways

1. Include `<stdbool.h>` to use `bool`, `true`, `false`
2. `bool` is 1 byte and holds only 0 or 1
3. Any non-zero value assigned to bool becomes 1
4. Use bool for flags and predicate functions
5. Makes code more readable and self-documenting

## Kata Challenge

**Boolean Array Operations**

Write functions that work with boolean arrays:

```c
// Your solution here

// bool all_true(bool arr[], int size);
// Returns true if all elements are true

// bool any_true(bool arr[], int size);
// Returns true if at least one element is true

// bool none_true(bool arr[], int size);
// Returns true if no elements are true

// int count_true(bool arr[], int size);
// Returns count of true values

// Test cases:
// bool arr1[] = {true, true, true};
// all_true(arr1, 3)   -> true
// any_true(arr1, 3)   -> true

// bool arr2[] = {false, true, false};
// all_true(arr2, 3)   -> false
// any_true(arr2, 3)   -> true
// count_true(arr2, 3) -> 1
```

Bonus: Implement `bool xor_all(bool arr[], int size)` that returns the XOR of all elements.
