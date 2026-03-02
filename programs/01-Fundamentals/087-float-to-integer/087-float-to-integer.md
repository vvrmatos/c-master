---
id: "087"
title: "Float to Integer Conversion"
category: "01-Fundamentals"
tags: ["type-conversion", "float", "integer", "truncation", "rounding"]
difficulty: "intermediate"
---

# Float to Integer Conversion

## Concept

Converting a floating-point value to an integer discards the fractional part. This is called **truncation** and always moves toward zero:

- `3.9` → `3` (not 4)
- `-3.9` → `-3` (not -4)

**This is NOT rounding!** Truncation simply removes the decimal part.

**Alternatives in `<math.h>`**:
- `floor()` - round down (toward -∞)
- `ceil()` - round up (toward +∞)
- `round()` - round to nearest
- `trunc()` - truncate toward zero (same as cast)

## Code

```c
// Float to integer conversion (truncation)

#include <stdio.h>
#include <math.h>

int main(void) {
    // Basic truncation (toward zero)
    printf("(int)3.7 = %d\n", (int)3.7);
    printf("(int)3.2 = %d\n", (int)3.2);
    printf("(int)-3.7 = %d\n", (int)-3.7);
    printf("(int)-3.2 = %d\n", (int)-3.2);
    
    // Truncation vs rounding
    double val = 2.6;
    printf("\nValue: %.1f\n", val);
    printf("Truncated: %d\n", (int)val);
    printf("Rounded: %d\n", (int)(val + 0.5));  // Simple rounding
    printf("floor(): %.1f\n", floor(val));
    printf("ceil(): %.1f\n", ceil(val));
    printf("round(): %.1f\n", round(val));
    
    // Negative rounding
    double neg = -2.6;
    printf("\nNegative: %.1f\n", neg);
    printf("Truncated: %d\n", (int)neg);
    printf("floor(): %.1f\n", floor(neg));
    printf("round(): %.1f\n", round(neg));
    
    return 0;
}
```

## Output

```
(int)3.7 = 3
(int)3.2 = 3
(int)-3.7 = -3
(int)-3.2 = -3

Value: 2.6
Truncated: 2
Rounded: 3
floor(): 2.0
ceil(): 3.0
round(): 3.0

Negative: -2.6
Truncated: -2
floor(): -3.0
round(): -3.0
```

## Key Takeaways

1. Cast to int truncates toward zero (removes decimal part)
2. Truncation ≠ rounding (3.9 → 3, not 4)
3. For negative numbers: `-3.9` → `-3` (not -4)
4. Use `round()` for proper rounding, `floor()` for always-down
5. Simple positive rounding: `(int)(x + 0.5)` (doesn't work for negatives)

## Kata Challenge

**Custom Rounding Functions**

Implement different rounding behaviors without using `<math.h>`:

```c
// Your solution here
// Implement:
// int round_nearest(double d);     // Round to nearest integer
// int round_down(double d);        // Always round toward -infinity
// int round_up(double d);          // Always round toward +infinity
// int round_toward_zero(double d); // Truncate (like cast)

// Test with: 2.3, 2.7, -2.3, -2.7
// Expected results for round_nearest:
// 2.3 -> 2, 2.7 -> 3, -2.3 -> -2, -2.7 -> -3
```

Hint: For round_down on negatives, you need extra logic since cast truncates toward zero.
