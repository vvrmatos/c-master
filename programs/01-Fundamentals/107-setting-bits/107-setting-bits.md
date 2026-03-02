---
title: "Setting Bits"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 107
---

## Concept

To set (turn on) a specific bit, use the OR assignment operator (`|=`) with a mask. The mask has a 1 in the position you want to set.

```
value |= (1 << position)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned char flags = 0b00000000;
    
    printf("Initial: 0x%02X\n", flags);
    
    flags |= (1 << 0);
    printf("Set bit 0: 0x%02X\n", flags);
    
    flags |= (1 << 3);
    printf("Set bit 3: 0x%02X\n", flags);
    
    flags |= (1 << 7);
    printf("Set bit 7: 0x%02X\n", flags);
    
    flags |= (1 << 3);
    printf("Set bit 3 again: 0x%02X\n", flags);
    
    return 0;
}
```

## Output

```
Initial: 0x00
Set bit 0: 0x01
Set bit 3: 0x09
Set bit 7: 0x89
Set bit 3 again: 0x89
```

## Key Takeaways

1. `|=` with mask sets specific bits to 1
2. `(1 << n)` creates mask with bit n set
3. Setting already-set bit has no effect
4. Other bits remain unchanged
5. Common for enabling flags/features

## Kata Challenge

Write a program that sets multiple bits at once: `flags |= (FLAG_A | FLAG_B | FLAG_C)`.
