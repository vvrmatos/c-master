---
title: "Else-If Ladder"
topic: "Conditionals"
level: "fundamental"
program_number: 113
---

## Concept

The else-if ladder allows testing multiple exclusive conditions in sequence. Only the first matching condition's block executes.

```c
if (cond1) {
    // first match
} else if (cond2) {
    // second match
} else if (cond3) {
    // third match
} else {
    // no match
}
```

## Code

```c
#include <stdio.h>

int main(void) {
    int score = 75;
    
    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }
    
    return 0;
}
```

## Output

```
Grade: C
```

## Key Takeaways

1. Conditions checked top to bottom
2. First true condition wins
3. Remaining conditions not evaluated
4. Final `else` catches all unmatched cases
5. Order matters for overlapping conditions

## Kata Challenge

Write a program that converts a numeric month (1-12) to its name using else-if.
