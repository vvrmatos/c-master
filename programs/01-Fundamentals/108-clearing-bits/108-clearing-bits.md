---
title: "Clearing Bits"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 108
---

## Concept

To clear (turn off) a specific bit, use the AND assignment operator (`&=`) with the complement of a mask. The inverted mask has a 0 in the position you want to clear.

```
value &= ~(1 << position)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned char flags = 0b11111111;
    
    printf("Initial: 0x%02X\n", flags);
    
    flags &= ~(1 << 0);
    printf("Clear bit 0: 0x%02X\n", flags);
    
    flags &= ~(1 << 3);
    printf("Clear bit 3: 0x%02X\n", flags);
    
    flags &= ~(1 << 7);
    printf("Clear bit 7: 0x%02X\n", flags);
    
    flags &= ~(1 << 3);
    printf("Clear bit 3 again: 0x%02X\n", flags);
    
    return 0;
}
```

## Output

```
Initial: 0xFF
Clear bit 0: 0xFE
Clear bit 3: 0xF6
Clear bit 7: 0x76
Clear bit 3 again: 0x76
```

## Key Takeaways

1. `&= ~mask` clears specific bits to 0
2. `~(1 << n)` creates mask with all 1s except bit n
3. Clearing already-cleared bit has no effect
4. Other bits remain unchanged
5. Common for disabling flags/features

## Kata Challenge

Write a program that clears the lower 4 bits of a byte while preserving the upper 4.
