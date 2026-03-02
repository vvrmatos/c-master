---
id: "074"
title: "Integer Division Behavior"
category: "01-Fundamentals"
tags: ["arithmetic", "division", "truncation", "integer"]
difficulty: "beginner"
---

# Integer Division Behavior

## Concept

Integer division in C truncates toward zero, meaning the fractional part is simply discarded. This is different from floor division (rounding toward negative infinity).

**Truncation toward zero**:
- `7 / 3 = 2` (not 2.33...)
- `-7 / 3 = -2` (not -3, which would be floor)
- `7 / -3 = -2`
- `-7 / -3 = 2`

The mathematical relationship always holds: `(a / b) * b + (a % b) == a`

## Code

```c
// Integer division truncation

#include <stdio.h>

int main(void) {
    // Truncation toward zero
    printf("7 / 3 = %d\n", 7 / 3);
    printf("-7 / 3 = %d\n", -7 / 3);
    printf("7 / -3 = %d\n", 7 / -3);
    printf("-7 / -3 = %d\n", -7 / -3);
    
    // The fractional part is discarded
    printf("\n99 / 100 = %d\n", 99 / 100);
    printf("1 / 2 = %d\n", 1 / 2);
    
    // Relationship: (a/b)*b + a%b == a
    int a = 17, b = 5;
    printf("\n%d = (%d/%d)*%d + %d%%%d = %d*%d + %d = %d\n",
           a, a, b, b, a, b, a/b, b, a%b, (a/b)*b + a%b);
    
    return 0;
}
```

## Output

```
7 / 3 = 2
-7 / 3 = -2
7 / -3 = -2
-7 / -3 = 2

99 / 100 = 0
1 / 2 = 0

17 = (17/5)*5 + 17%5 = 3*5 + 2 = 17
```

## Key Takeaways

1. Integer division truncates toward zero (not floor)
2. `-7 / 3 = -2`, not `-3` (would be floor)
3. Any result less than 1 in magnitude becomes 0
4. The identity `(a/b)*b + a%b == a` always holds
5. C99 standardized truncation toward zero; older compilers were implementation-defined

## Kata Challenge

**Digit Extractor**

Write a program that extracts each digit from a 4-digit number using integer division.

```c
// Your solution here
// Input: num = 1234
// Expected output:
// Thousands: 1
// Hundreds: 2
// Tens: 3
// Ones: 4
```

Hint: Use combinations of `/` and `%` with powers of 10.
