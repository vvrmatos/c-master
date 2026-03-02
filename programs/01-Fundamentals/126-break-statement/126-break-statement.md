---
title: "Break Statement"
topic: "Loops"
level: "fundamental"
program_number: 126
---

## Concept

The `break` statement immediately exits the innermost loop, transferring control to the statement following the loop.

```c
while (condition) {
    if (exit_condition) {
        break;  // exit loop immediately
    }
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int numbers[] = {4, 2, 7, 1, 9, 3, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 9;
    int found = 0;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            printf("Found %d at index %d\n", target, i);
            found = 1;
            break;
        }
        printf("Checked index %d\n", i);
    }
    
    if (!found) {
        printf("Not found\n");
    }
    
    return 0;
}
```

## Output

```
Checked index 0
Checked index 1
Checked index 2
Checked index 3
Found 9 at index 4
```

## Key Takeaways

1. Exits only the innermost loop
2. Skips remaining iterations
3. Loop's else clause (if any in other languages) not executed
4. Common for early termination on success
5. In nested loops, use flags or goto for outer break

## Kata Challenge

Write a program that finds the first prime number greater than 100 using break.
