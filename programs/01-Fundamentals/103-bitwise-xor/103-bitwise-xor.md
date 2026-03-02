---
title: "Bitwise XOR Operator"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 103
---

## Concept

The bitwise XOR (exclusive OR) operator (`^`) compares each bit of two operands. The result bit is 1 only if the corresponding bits are different.

```
  11001100  (204)
^ 10101010  (170)
----------
  01100110  (102)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned int a = 0b11001100;
    unsigned int b = 0b10101010;
    unsigned int result = a ^ b;
    
    printf("a      = %u (0x%02X)\n", a, a);
    printf("b      = %u (0x%02X)\n", b, b);
    printf("a ^ b  = %u (0x%02X)\n", result, result);
    
    int x = 5, y = 10;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("Swapped: x=%d, y=%d\n", x, y);
    
    return 0;
}
```

## Output

```
a      = 204 (0xCC)
b      = 170 (0xAA)
a ^ b  = 102 (0x66)
Swapped: x=10, y=5
```

## Key Takeaways

1. XOR produces 1 when bits are different
2. `a ^ a = 0` (any value XOR itself is zero)
3. `a ^ 0 = a` (any value XOR zero is unchanged)
4. XOR swap trick works without temporary variable
5. Used in encryption and checksums

## Kata Challenge

Write a program that finds the single non-duplicate number in an array where all others appear twice.
