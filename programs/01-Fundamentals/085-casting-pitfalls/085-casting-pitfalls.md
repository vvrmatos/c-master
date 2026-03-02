---
id: "085"
title: "Casting Pitfalls"
category: "01-Fundamentals"
tags: ["type-conversion", "casting", "pitfalls", "precision", "overflow"]
difficulty: "intermediate"
---

# Casting Pitfalls

## Concept

Type casting can cause data loss or undefined behavior. Understanding these pitfalls prevents subtle bugs:

**Common pitfalls**:
1. **Truncation**: `(int)3.9` → `3`, fractional part lost
2. **Overflow**: Value doesn't fit in target type
3. **Precision loss**: Large integers can't be exactly represented in float
4. **Undefined behavior**: Casting out-of-range float to int
5. **Sign issues**: Signed ↔ unsigned conversions

**Important**: Casting doesn't round—it truncates toward zero!

## Code

```c
// Casting pitfalls - precision loss

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    // Truncation: fractional part lost
    double d = 9.999;
    int i = (int)d;
    printf("Truncation: %.3f -> %d (lost %.3f)\n", d, i, d - i);
    
    // Overflow: value too large for target type
    long big = 3000000000L;
    int small = (int)big;
    printf("Overflow: %ld -> %d (UB on some systems)\n", big, small);
    
    // Precision loss: large int to float
    int precise = 123456789;
    float imprecise = (float)precise;
    printf("Precision: %d -> %.0f (diff: %d)\n", 
           precise, imprecise, precise - (int)imprecise);
    
    // Large double to int
    double huge = 1e20;
    int overflow = (int)huge;  // Undefined behavior!
    printf("Double overflow: %.0e -> %d (UB!)\n", huge, overflow);
    
    // Negative to unsigned
    int neg = -1;
    unsigned int u = (unsigned int)neg;
    printf("Signed to unsigned: %d -> %u\n", neg, u);
    
    return 0;
}
```

## Output

```
Truncation: 9.999 -> 9 (lost 0.999)
Overflow: 3000000000 -> -1294967296 (UB on some systems)
Precision: 123456789 -> 123456792 (diff: -3)
Double overflow: 1e+20 -> [undefined] (UB!)
Signed to unsigned: -1 -> 4294967295
```

## Key Takeaways

1. Truncation loses the fractional part (doesn't round!)
2. Overflow when target type can't hold the value
3. `float` only has ~7 digits of precision for large integers
4. Casting out-of-range float to int is undefined behavior
5. Signed → unsigned conversion wraps around (modulo power of 2)

## Kata Challenge

**Safe Converter**

Write a program with safe conversion functions that check for problems before casting:

```c
// Your solution here
// Implement:
// int safe_double_to_int(double d, int *result);
// Returns 0 on success, -1 if overflow, -2 if truncation would lose significant fraction

// Test cases:
// safe_double_to_int(42.0, &r)    -> success, r = 42
// safe_double_to_int(42.5, &r)    -> truncation warning
// safe_double_to_int(1e20, &r)    -> overflow error
// safe_double_to_int(-1e20, &r)   -> overflow error
```

Hint: Check `d >= INT_MIN && d <= INT_MAX` before casting.
