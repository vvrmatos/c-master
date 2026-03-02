---
id: "088"
title: "Integer to Float Conversion"
category: "01-Fundamentals"
tags: ["type-conversion", "integer", "float", "precision", "mantissa"]
difficulty: "intermediate"
---

# Integer to Float Conversion

## Concept

Converting integers to floating-point seems safe, but large integers can lose precision because:

- `float` has only 23 bits of mantissa (~7 decimal digits)
- `double` has 52 bits of mantissa (~15 decimal digits)

**Exact representation limits**:
- `float`: integers up to 2^24 (16,777,216) are exact
- `double`: integers up to 2^53 (9,007,199,254,740,992) are exact

Beyond these limits, some integer values cannot be exactly represented.

## Code

```c
// Integer to float conversion (precision)

#include <stdio.h>
#include <float.h>

int main(void) {
    // Small integers convert exactly
    int small = 42;
    float f_small = small;
    printf("int %d -> float %.1f (exact)\n", small, f_small);
    
    // Large integers may lose precision
    int large = 123456789;
    float f_large = large;
    printf("int %d -> float %.0f (diff: %d)\n", 
           large, f_large, large - (int)f_large);
    
    // double has more precision
    double d_large = large;
    printf("int %d -> double %.0f (diff: %.0f)\n",
           large, d_large, large - d_large);
    
    // The limit of float precision
    printf("\nFloat precision limit:\n");
    for (int i = 16777210; i <= 16777220; i++) {
        float f = i;
        printf("%d -> %.0f %s\n", i, f, (i == (int)f) ? "" : "(lost precision)");
    }
    
    // Why? float has 23-bit mantissa
    printf("\nFloat mantissa: 23 bits = %d distinct values\n", 1 << 23);
    printf("2^24 = %d (largest exact integer in float)\n", 1 << 24);
    
    return 0;
}
```

## Output

```
int 42 -> float 42.0 (exact)
int 123456789 -> float 123456792 (diff: -3)
int 123456789 -> double 123456789 (diff: 0)

Float precision limit:
16777210 -> 16777210 
16777211 -> 16777211 
...
16777216 -> 16777216 
16777217 -> 16777216 (lost precision)
16777218 -> 16777218 
16777219 -> 16777220 (lost precision)
16777220 -> 16777220 

Float mantissa: 23 bits = 8388608 distinct values
2^24 = 16777216 (largest exact integer in float)
```

## Key Takeaways

1. Small integers convert to float exactly
2. Integers > 16,777,216 may not be exact in float
3. Use `double` for larger integer values
4. `double` is exact for all 32-bit integers
5. `long long` values can exceed even double's precision

## Kata Challenge

**Precision Tester**

Write a program that finds the first integer that loses precision when converted:

```c
// Your solution here
// Find the smallest positive integer n where:
// (float)n != n  OR  (int)(float)n != n

// For float: should find around 16777217
// For double: should find around 9007199254740993

// Also: given an arbitrary int, determine if it can be
// exactly represented in float.
```

Hint: Loop from 1 upward and check if round-tripping changes the value.
