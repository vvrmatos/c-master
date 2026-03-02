---
title: "Checking Bits"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 110
---

## Concept

To check if a specific bit is set, use the AND operator (`&`) with a mask. If the result is non-zero, the bit is set.

```
if (value & (1 << position)) { /* bit is set */ }
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned char flags = 0b10100101;
    
    printf("flags = 0x%02X\n\n", flags);
    
    for (int i = 7; i >= 0; i--) {
        if (flags & (1 << i)) {
            printf("Bit %d is SET\n", i);
        } else {
            printf("Bit %d is CLEAR\n", i);
        }
    }
    
    return 0;
}
```

## Output

```
flags = 0xA5

Bit 7 is SET
Bit 6 is CLEAR
Bit 5 is SET
Bit 4 is CLEAR
Bit 3 is CLEAR
Bit 2 is SET
Bit 1 is CLEAR
Bit 0 is SET
```

## Key Takeaways

1. `&` with mask tests if specific bit is set
2. Non-zero result means bit is 1
3. Zero result means bit is 0
4. Use `!=0` for explicit boolean: `(flags & mask) != 0`
5. Does not modify the original value

## Kata Challenge

Write a program that checks if multiple flags are all set using a combined mask.
