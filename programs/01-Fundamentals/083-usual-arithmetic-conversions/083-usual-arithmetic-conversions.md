---
id: "083"
title: "Usual Arithmetic Conversions"
category: "01-Fundamentals"
tags: ["type-conversion", "arithmetic", "mixed-types", "promotion"]
difficulty: "intermediate"
---

# Usual Arithmetic Conversions

## Concept

When operands of different types are used with binary operators, C applies the "usual arithmetic conversions" to bring both operands to a common type.

**Conversion rules** (applied in order):
1. If either operand is `long double`, convert other to `long double`
2. If either operand is `double`, convert other to `double`
3. If either operand is `float`, convert other to `float`
4. Apply integer promotion to both operands, then:
   - If both same type, done
   - If both signed or both unsigned, convert to wider type
   - Special rules for signed/unsigned mixing

## Code

```c
// Usual arithmetic conversions (mixed types)

#include <stdio.h>

int main(void) {
    int i = 5;
    long l = 10L;
    float f = 2.5f;
    double d = 3.5;
    
    // int + long -> long
    long r1 = i + l;
    printf("int + long = %ld (size: %zu)\n", r1, sizeof(i + l));
    
    // long + float -> float
    float r2 = l + f;
    printf("long + float = %.1f (size: %zu)\n", r2, sizeof(l + f));
    
    // float + double -> double
    double r3 = f + d;
    printf("float + double = %.1f (size: %zu)\n", r3, sizeof(f + d));
    
    // int + double -> double
    double r4 = i + d;
    printf("int + double = %.1f (size: %zu)\n", r4, sizeof(i + d));
    
    // Full chain: int + long + float + double -> double
    double r5 = i + l + f + d;
    printf("i + l + f + d = %.1f (size: %zu)\n", r5, sizeof(i + l + f + d));
    
    return 0;
}
```

## Output

```
int + long = 15 (size: 8)
long + float = 12.5 (size: 4)
float + double = 6.0 (size: 8)
int + double = 8.5 (size: 8)
i + l + f + d = 21.0 (size: 8)
```

## Key Takeaways

1. Floating-point types take precedence over integers
2. `double` takes precedence over `float`
3. Among integers, longer types take precedence
4. The result type is the common type after conversion
5. Conversions happen before the operation

## Kata Challenge

**Conversion Predictor**

Predict the type of each expression and verify:

```c
// Your solution here

short s = 10;
int i = 20;
long l = 30L;
unsigned int u = 40U;
float f = 1.5f;
double d = 2.5;

// What is the type of:
// 1. s + i
// 2. i + l
// 3. i + u    // Tricky! What happens with signed + unsigned?
// 4. l + f
// 5. f * d
// 6. s + i + l + f + d

// Check with sizeof and _Generic (C11) or by assigning to different types
```

Hint: For signed/unsigned mixing, the result is unsigned if unsigned type is at least as wide.
