---
title: "Bitwise AND Operator"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 101
---

## Concept

The bitwise AND operator (`&`) compares each bit of two operands. The result bit is 1 only if both corresponding bits are 1.

```
  11001100  (204)
& 10101010  (170)
----------
  10001000  (136)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned int a = 0b11001100;
    unsigned int b = 0b10101010;
    unsigned int result = a & b;
    
    printf("a      = %u (0x%02X)\n", a, a);
    printf("b      = %u (0x%02X)\n", b, b);
    printf("a & b  = %u (0x%02X)\n", result, result);
    
    return 0;
}
```

## Output

```
a      = 204 (0xCC)
b      = 170 (0xAA)
a & b  = 136 (0x88)
```

## Key Takeaways

1. AND produces 1 only when both bits are 1
2. Commonly used to mask bits (extract specific bits)
3. Use unsigned types to avoid sign-extension issues
4. Binary literals (0b) improve readability

## Kata Challenge

Write a program that uses AND to extract the lower 4 bits (nibble) of a byte.
