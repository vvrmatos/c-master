---
title: "Right Shift Operator"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 106
---

## Concept

The right shift operator (`>>`) shifts bits to the right by a specified number of positions. For unsigned types, zeros fill from the left. Each shift right divides by 2.

```
00010000 >> 2 = 00000100  (16 -> 4)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned int a = 16;
    
    printf("a      = %u\n", a);
    printf("a >> 1 = %u\n", a >> 1);
    printf("a >> 2 = %u\n", a >> 2);
    printf("a >> 3 = %u\n", a >> 3);
    printf("a >> 4 = %u\n", a >> 4);
    
    unsigned int b = 100;
    printf("\n%u / 8 = %u (using >> 3)\n", b, b >> 3);
    
    return 0;
}
```

## Output

```
a      = 16
a >> 1 = 8
a >> 2 = 4
a >> 3 = 2
a >> 4 = 1

100 / 8 = 12 (using >> 3)
```

## Key Takeaways

1. `x >> n` equals `x / 2^n` (integer division)
2. For unsigned: zeros fill from left (logical shift)
3. For signed: implementation-defined (arithmetic vs logical)
4. Bits shifted out on the right are lost
5. Faster than division for powers of 2

## Kata Challenge

Write a program that extracts the upper nibble (4 bits) of a byte using right shift.
