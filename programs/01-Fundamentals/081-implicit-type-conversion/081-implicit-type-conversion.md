---
id: "081"
title: "Implicit Type Conversion"
category: "01-Fundamentals"
tags: ["type-conversion", "implicit", "promotion", "coercion"]
difficulty: "intermediate"
---

# Implicit Type Conversion

## Concept

Implicit type conversion (also called automatic promotion or coercion) happens automatically when values of different types are mixed in an expression. The compiler converts the "narrower" type to the "wider" type.

**Conversion hierarchy** (narrow to wide):
```
char < short < int < long < long long < float < double < long double
```

When different types are mixed:
- Smaller types are promoted to larger types
- Integer types are promoted to floating-point when needed
- No data loss in this direction (usually)

## Code

```c
// Implicit type conversion (automatic promotion)

#include <stdio.h>

int main(void) {
    int i = 10;
    double d = 3.5;
    
    // int is promoted to double
    double result = i + d;
    printf("int + double: %d + %.1f = %.1f\n", i, d, result);
    
    // char promoted to int
    char c = 'A';
    int sum = c + 1;
    printf("char + int: '%c' + 1 = %d ('%c')\n", c, sum, sum);
    
    // float promoted to double in expressions
    float f = 1.5f;
    double mixed = f + d;
    printf("float + double: %.1f + %.1f = %.1f\n", f, d, mixed);
    
    // int to float (automatic)
    float quotient = i;
    printf("int to float: %d -> %.1f\n", i, quotient);
    
    return 0;
}
```

## Output

```
int + double: 10 + 3.5 = 13.5
char + int: 'A' + 1 = 66 ('B')
float + double: 1.5 + 3.5 = 5.0
int to float: 10 -> 10.0
```

## Key Takeaways

1. C automatically promotes smaller types to larger types
2. Integer + float = float
3. `char` is treated as a small integer in arithmetic
4. float is promoted to double in expressions with double
5. Implicit conversion happens in assignments too

## Kata Challenge

**Type Mixer**

Predict the type and value of each result:

```c
// Your solution here
// Determine the type and value:

char c = 100;
short s = 200;
int i = 300;
float f = 1.5f;
double d = 2.5;

// 1. c + s           → type: ?, value: ?
// 2. i + f           → type: ?, value: ?
// 3. f + d           → type: ?, value: ?
// 4. c + i + f       → type: ?, value: ?
// 5. c + s + i + f + d → type: ?, value: ?

// Verify with printf and sizeof()!
```

Hint: Use `sizeof()` to check the type of each expression.
