---
title: "Bitwise OR Operator"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 102
---

## Concept

The bitwise OR operator (`|`) compares each bit of two operands. The result bit is 1 if either or both corresponding bits are 1.

```
  11001100  (204)
| 10101010  (170)
----------
  11101110  (238)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned int a = 0b11001100;
    unsigned int b = 0b10101010;
    unsigned int result = a | b;
    
    printf("a      = %u (0x%02X)\n", a, a);
    printf("b      = %u (0x%02X)\n", b, b);
    printf("a | b  = %u (0x%02X)\n", result, result);
    
    return 0;
}
```

## Output

```
a      = 204 (0xCC)
b      = 170 (0xAA)
a | b  = 238 (0xEE)
```

## Key Takeaways

1. OR produces 1 when at least one bit is 1
2. Commonly used to set specific bits
3. Combining flags: `flags = FLAG_A | FLAG_B`
4. OR never clears bits, only sets them

## Kata Challenge

Write a program that combines permission flags (READ=1, WRITE=2, EXECUTE=4) using OR.
