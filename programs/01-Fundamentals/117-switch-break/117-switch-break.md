---
title: "Switch Break"
topic: "Conditionals"
level: "fundamental"
program_number: 117
---

## Concept

The `break` statement exits the switch block, preventing fall-through to subsequent cases. Without break, execution continues to the next case.

```c
case X:
    // code
    break;  // exit switch
```

## Code

```c
#include <stdio.h>

int main(void) {
    char grade = 'B';
    
    switch (grade) {
        case 'A':
            printf("Excellent!\n");
            break;
        case 'B':
            printf("Good job!\n");
            break;
        case 'C':
            printf("Satisfactory\n");
            break;
        case 'F':
            printf("Failed\n");
            break;
        default:
            printf("Invalid grade\n");
            break;
    }
    
    printf("Grade processed\n");
    
    return 0;
}
```

## Output

```
Good job!
Grade processed
```

## Key Takeaways

1. Break exits switch immediately
2. Missing break causes fall-through (often a bug)
3. Break on default is optional but good style
4. Program continues after switch when break executes
5. Each case should typically end with break

## Kata Challenge

Write a program that demonstrates what happens when you forget break statements.
