---
title: "Do-While Loop"
topic: "Loops"
level: "fundamental"
program_number: 122
---

## Concept

The `do-while` loop checks its condition after each iteration. The body always executes at least once.

```c
do {
    // body executes at least once
} while (condition);
```

## Code

```c
#include <stdio.h>

int main(void) {
    int num = 5;
    int factorial = 1;
    
    do {
        factorial *= num;
        num--;
    } while (num > 0);
    
    printf("5! = %d\n", factorial);
    
    int x = 10;
    do {
        printf("x = %d\n", x);
    } while (x < 5);
    
    return 0;
}
```

## Output

```
5! = 120
x = 10
```

## Key Takeaways

1. Body executes before condition check
2. Always runs at least once
3. Note the semicolon after while(condition);
4. Exit-controlled loop
5. Good for input validation (prompt at least once)

## Kata Challenge

Write a menu system that displays options and prompts for input at least once.
