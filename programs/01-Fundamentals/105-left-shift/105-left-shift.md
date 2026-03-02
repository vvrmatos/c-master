---
title: "Left Shift Operator"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 105
---

## Concept

The left shift operator (`<<`) shifts bits to the left by a specified number of positions. Zeros fill from the right. Each shift left multiplies by 2.

```
00000001 << 3 = 00001000  (1 -> 8)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned int a = 1;
    
    printf("a      = %u\n", a);
    printf("a << 1 = %u\n", a << 1);
    printf("a << 2 = %u\n", a << 2);
    printf("a << 3 = %u\n", a << 3);
    printf("a << 4 = %u\n", a << 4);
    
    unsigned int b = 5;
    printf("\n%u * 8 = %u (using << 3)\n", b, b << 3);
    
    return 0;
}
```

## Output

```
a      = 1
a << 1 = 2
a << 2 = 4
a << 3 = 8
a << 4 = 16

5 * 8 = 40 (using << 3)
```

## Key Takeaways

1. `x << n` equals `x * 2^n`
2. Bits shifted out on the left are lost
3. Zeros fill in from the right
4. Faster than multiplication for powers of 2
5. `1 << n` creates a mask with bit n set

## Kata Challenge

Write a program that uses left shift to calculate powers of 2 up to 2^10.
