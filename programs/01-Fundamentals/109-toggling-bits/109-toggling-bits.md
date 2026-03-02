---
title: "Toggling Bits"
topic: "Bitwise Operators"
level: "fundamental"
program_number: 109
---

## Concept

To toggle (flip) a specific bit, use the XOR assignment operator (`^=`) with a mask. The bit changes from 0 to 1 or from 1 to 0.

```
value ^= (1 << position)
```

## Code

```c
#include <stdio.h>

int main(void) {
    unsigned char flags = 0b10100101;
    
    printf("Initial:      0x%02X\n", flags);
    
    flags ^= (1 << 0);
    printf("Toggle bit 0: 0x%02X\n", flags);
    
    flags ^= (1 << 0);
    printf("Toggle bit 0: 0x%02X\n", flags);
    
    flags ^= (1 << 7);
    printf("Toggle bit 7: 0x%02X\n", flags);
    
    flags ^= 0xFF;
    printf("Toggle all:   0x%02X\n", flags);
    
    return 0;
}
```

## Output

```
Initial:      0xA5
Toggle bit 0: 0xA4
Toggle bit 0: 0xA5
Toggle bit 7: 0x25
Toggle all:   0xDA
```

## Key Takeaways

1. `^=` with mask flips specific bits
2. Toggle twice returns to original value
3. XOR with all 1s inverts entire value
4. Other bits remain unchanged
5. Useful for alternating states (LED blink, etc.)

## Kata Challenge

Write a program that implements a simple toggle switch that alternates between ON (1) and OFF (0) states.
