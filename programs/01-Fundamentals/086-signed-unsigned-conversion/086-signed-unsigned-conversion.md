---
id: "086"
title: "Signed-Unsigned Conversion"
category: "01-Fundamentals"
tags: ["type-conversion", "signed", "unsigned", "comparison", "dangers"]
difficulty: "intermediate"
---

# Signed-Unsigned Conversion

## Concept

Mixing signed and unsigned integers in expressions is a common source of bugs. The rules are:

**Conversion rule**: When signed and unsigned of the same size interact:
- The **signed value is converted to unsigned**
- Negative numbers become large positive numbers!

**Why this is dangerous**:
- `-1` becomes `UINT_MAX` (4294967295 on 32-bit)
- Comparisons `signed < unsigned` give unexpected results
- Array bounds checks can be bypassed

## Code

```c
// Signed and unsigned conversion dangers

#include <stdio.h>

int main(void) {
    // Unsigned can't be negative - wraps around
    unsigned int u = 0;
    u = u - 1;  // Wraps to UINT_MAX
    printf("0u - 1 = %u\n", u);
    
    // Comparing signed and unsigned
    int s = -1;
    unsigned int us = 1;
    if (s < us) {
        printf("-1 < 1? Yes (expected)\n");
    } else {
        printf("-1 > 1? No! (s was converted to unsigned)\n");
    }
    
    // The actual comparison
    printf("As unsigned: %d -> %u\n", s, (unsigned int)s);
    printf("%u > %u is %s\n", (unsigned int)s, us, 
           (unsigned int)s > us ? "true" : "false");
    
    // Array index danger
    int arr[5] = {10, 20, 30, 40, 50};
    int index = -1;
    if (index < 5) {  // Always true if index is compared as int
        // arr[index] would be UB
        printf("Index %d passes bounds check against 5\n", index);
    }
    
    // Safe pattern: compare against 0 first
    if (index >= 0 && index < 5) {
        printf("Safe: index %d is valid\n", index);
    } else {
        printf("Safe: index %d is invalid\n", index);
    }
    
    return 0;
}
```

## Output

```
0u - 1 = 4294967295
-1 > 1? No! (s was converted to unsigned)
As unsigned: -1 -> 4294967295
4294967295 > 1 is true
Index -1 passes bounds check against 5
Safe: index -1 is invalid
```

## Key Takeaways

1. Signed values are converted to unsigned in mixed comparisons
2. `-1` becomes `UINT_MAX` when converted to unsigned
3. `sizeof()` returns `size_t` (unsigned)—watch comparisons with it
4. Always check `>= 0` before using a signed value as an index
5. Use consistent types or explicit casts to avoid surprises

## Kata Challenge

**Safe Array Access**

Write a function that safely accesses an array element, handling negative and out-of-bounds indices:

```c
// Your solution here
// int safe_array_get(int *arr, size_t size, int index, int *value);
// Returns 0 on success, -1 on invalid index

// Test cases:
// int arr[] = {10, 20, 30, 40, 50};
// safe_array_get(arr, 5, 2, &v)   -> success, v = 30
// safe_array_get(arr, 5, -1, &v)  -> error (negative)
// safe_array_get(arr, 5, 5, &v)   -> error (out of bounds)
// safe_array_get(arr, 5, 10, &v)  -> error (out of bounds)
```

Hint: Check `index >= 0` first (as signed), then compare with size.
