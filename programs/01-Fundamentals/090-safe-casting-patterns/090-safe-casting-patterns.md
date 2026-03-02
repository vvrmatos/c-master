---
id: "090"
title: "Safe Casting Patterns"
category: "01-Fundamentals"
tags: ["type-conversion", "casting", "safety", "defensive", "validation"]
difficulty: "intermediate"
---

# Safe Casting Patterns

## Concept

Safe casting means validating that a conversion won't lose data before performing it. This is crucial for:

- Narrowing conversions (larger type → smaller type)
- Float-to-integer conversions
- Any cast where overflow is possible

**Pattern**: Check limits before casting, return error status.

```c
int safe_cast(from_type value, to_type *result) {
    if (value < TO_TYPE_MIN || value > TO_TYPE_MAX) {
        return -1;  // Error: would overflow
    }
    *result = (to_type)value;
    return 0;  // Success
}
```

## Code

```c
// Safe casting patterns

#include <stdio.h>
#include <limits.h>

// Safe int to short conversion
int int_to_short(int value, short *result) {
    if (value < SHRT_MIN || value > SHRT_MAX) {
        return -1;  // Overflow
    }
    *result = (short)value;
    return 0;
}

// Safe double to int conversion
int double_to_int(double value, int *result) {
    if (value < INT_MIN || value > INT_MAX) {
        return -1;  // Overflow
    }
    *result = (int)value;
    return 0;
}

int main(void) {
    // Safe narrowing conversion
    int big = 1000000;
    short small;
    if (int_to_short(big, &small) == 0) {
        printf("Converted: %d -> %d\n", big, small);
    } else {
        printf("Cannot convert %d to short (overflow)\n", big);
    }
    
    int safe_val = 100;
    if (int_to_short(safe_val, &small) == 0) {
        printf("Converted: %d -> %d\n", safe_val, small);
    }
    
    // Safe float to int
    double d = 1e15;
    int i;
    if (double_to_int(d, &i) == 0) {
        printf("Converted: %.0f -> %d\n", d, i);
    } else {
        printf("Cannot convert %.0e to int (overflow)\n", d);
    }
    
    return 0;
}
```

## Output

```
Cannot convert 1000000 to short (overflow)
Converted: 100 -> 100
Cannot convert 1e+15 to int (overflow)
```

## Key Takeaways

1. Always validate before narrowing conversions
2. Use `<limits.h>` constants for range checking
3. Return error codes to signal conversion failure
4. Use output parameters for the converted value
5. This pattern prevents silent data corruption

## Kata Challenge

**Safe Conversion Library**

Create a mini-library of safe conversion functions:

```c
// Your solution here
// Implement these safe converters:

// int safe_long_to_int(long value, int *result);
// int safe_int_to_char(int value, char *result);
// int safe_uint_to_int(unsigned int value, int *result);
// int safe_double_to_long(double value, long *result);

// Each returns 0 on success, -1 on overflow

// Test cases that should fail:
// safe_long_to_int(3000000000L, &i)
// safe_int_to_char(1000, &c)
// safe_uint_to_int(UINT_MAX, &i)
// safe_double_to_long(1e20, &l)
```

Bonus: Create a macro that generates these functions for any numeric types.
