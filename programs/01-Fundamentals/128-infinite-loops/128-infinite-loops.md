---
title: "Infinite Loops"
topic: "Loops"
level: "fundamental"
program_number: 128
---

## Concept

Infinite loops run forever until explicitly terminated with `break`, `return`, or external interruption. Common idioms: `for(;;)` and `while(1)`.

```c
for (;;) { /* forever */ }
while (1) { /* forever */ }
```

## Code

```c
#include <stdio.h>

int main(void) {
    int count = 0;
    
    /* for(;;) style */
    for (;;) {
        printf("Loop %d\n", ++count);
        if (count >= 3) break;
    }
    
    /* while(1) style */
    count = 0;
    while (1) {
        printf("While %d\n", ++count);
        if (count >= 3) break;
    }
    
    /* Event loop pattern */
    int running = 1;
    int events = 0;
    while (running) {
        events++;
        if (events >= 3) {
            running = 0;
        }
    }
    printf("Processed %d events\n", events);
    
    return 0;
}
```

## Output

```
Loop 1
Loop 2
Loop 3
While 1
While 2
While 3
Processed 3 events
```

## Key Takeaways

1. `for(;;)` - traditional C style
2. `while(1)` - more readable to some
3. Must have exit condition inside loop
4. Used for servers, event loops, games
5. Accidental infinite loops are bugs

## Kata Challenge

Write a simple command interpreter that loops until user types "quit".
