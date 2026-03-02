---
title: "Bitwise NOT Operator"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 104
---

## Concept

The bitwise NOT operator (`~`) is a unary operator that inverts all bits. Each 0 becomes 1, and each 1 becomes 0.

```
~ 11001100  (204)
----------
  00110011  (51)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned char a = 0b11001100;
    unsigned char result = ~a;
    
    printf("a  = %u (0x%02X)\n", a, a);
    printf("~a = %u (0x%02X)\n", result, result);
    
    unsigned int b = 0;
    printf("~0 = %u (0x%08X)\n", ~b, ~b);
    
    return 0;
}
```

## Output

```
a  = 204 (0xCC)
~a = 51 (0x33)
~0 = 4294967295 (0xFFFFFFFF)
```

## Key Takeaways

1. NOT flips every bit (one's complement)
2. Result depends on the data type size
3. `~0` gives all 1s (useful for max unsigned value)
4. Used with AND to clear bits: `value &= ~mask`
5. `~x + 1` equals `-x` in two's complement

## Kata Challenge

Write a program that creates a mask with all bits set except bit position n.
