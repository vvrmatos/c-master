---
id: "060"
title: "scanf() Return Value"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - scanf
  - input
  - error-handling
  - validation
difficulty: beginner
source: "C11 Standard 7.21.6.2"
---

# 060 — scanf() Return Value

## Concept

`scanf()` returns the number of input items successfully matched and assigned. This is crucial for input validation and error handling.

**Return values:**
| Value | Meaning |
|-------|---------|
| n > 0 | Number of items successfully read |
| 0 | Matching failure (input didn't match format) |
| EOF (-1) | End of file or read error |

**Why check return value?**
- Detect invalid input early
- Prevent using uninitialized variables
- Handle EOF in interactive programs
- Build robust programs

**Input validation pattern:**
```c
int num;
while (scanf("%d", &num) != 1) {
    printf("Invalid. Try again: ");
    while (getchar() != '\n');  // Clear bad input
}
```

**Clearing input buffer:**
After failed scanf, bad input remains in buffer. Clear it with:
```c
while (getchar() != '\n');
```

**EOF detection:**
```c
int val;
while (scanf("%d", &val) == 1) {
    // Process val
}
// Loop ends on EOF or error
```

> **Best Practice:** Always check scanf's return value in production code. Silent failures lead to bugs.

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== scanf() Return Value ===\n\n");
    
    printf("scanf returns number of successfully matched items.\n\n");
    
    int a, b;
    printf("Enter two integers: ");
    int count = scanf("%d %d", &a, &b);
    printf("  Return value: %d\n", count);
    if (count == 2) {
        printf("  Both values read: %d, %d\n\n", a, b);
    } else {
        printf("  Failed to read both values\n\n");
        while (getchar() != '\n');
    }
    
    int x;
    printf("Enter an integer (or text to see failure): ");
    int result = scanf("%d", &x);
    printf("  Return value: %d\n", result);
    if (result == 1) {
        printf("  Successfully read: %d\n\n", x);
    } else if (result == 0) {
        printf("  Matching failure (input wasn't an integer)\n\n");
        while (getchar() != '\n');
    } else {
        printf("  EOF or error\n\n");
    }
    
    printf("Return value meanings:\n");
    printf("  n  - Number of items successfully matched\n");
    printf("  0  - Matching failure (wrong format)\n");
    printf("  EOF (-1) - End of file or read error\n\n");
    
    int num;
    printf("Proper input validation pattern:\n");
    printf("Enter a number: ");
    while (scanf("%d", &num) != 1) {
        printf("  Invalid input. Enter a number: ");
        while (getchar() != '\n');
    }
    printf("  Valid number: %d\n\n", num);
    
    int i1, i2, i3;
    printf("Reading multiple values:\n");
    printf("Enter three integers: ");
    int matched = scanf("%d %d %d", &i1, &i2, &i3);
    printf("  Matched %d of 3 items\n", matched);
    switch (matched) {
        case 3: printf("  All three: %d, %d, %d\n", i1, i2, i3); break;
        case 2: printf("  Only two: %d, %d\n", i1, i2); break;
        case 1: printf("  Only one: %d\n", i1); break;
        case 0: printf("  None matched\n"); break;
        default: printf("  EOF or error\n"); break;
    }
    
    while (getchar() != '\n');
    
    printf("\nSimulating EOF (Ctrl+D on Unix, Ctrl+Z on Windows):\n");
    int val;
    printf("Enter numbers (Ctrl+D/Z to end):\n");
    int total = 0, c = 0;
    while ((result = scanf("%d", &val)) == 1) {
        total += val;
        c++;
        printf("  Read: %d (running total: %d)\n", val, total);
    }
    if (result == EOF) {
        printf("  EOF reached after %d numbers\n", c);
    } else {
        printf("  Matching error after %d numbers\n", c);
    }
    
    printf("\nSummary:\n");
    printf("  Always check scanf return value\n");
    printf("  Clear input buffer after failure\n");
    printf("  Handle EOF for interactive programs\n");
    
    return 0;
}
```

## Output

```
=== scanf() Return Value ===

scanf returns number of successfully matched items.

Enter two integers: 10 20
  Return value: 2
  Both values read: 10, 20

Enter an integer (or text to see failure): hello
  Return value: 0
  Matching failure (input wasn't an integer)

Return value meanings:
  n  - Number of items successfully matched
  0  - Matching failure (wrong format)
  EOF (-1) - End of file or read error

Proper input validation pattern:
Enter a number: abc
  Invalid input. Enter a number: xyz
  Invalid input. Enter a number: 42
  Valid number: 42

Reading multiple values:
Enter three integers: 1 2 three
  Matched 2 of 3 items
  Only two: 1, 2

Simulating EOF (Ctrl+D on Unix, Ctrl+Z on Windows):
Enter numbers (Ctrl+D/Z to end):
  (Press Ctrl+D or Ctrl+Z)
  EOF reached after 0 numbers

Summary:
  Always check scanf return value
  Clear input buffer after failure
  Handle EOF for interactive programs
```

## Compilation

```bash
gcc 060-scanf-return-value.c -o 060-scanf-return-value
./060-scanf-return-value
```

## Key Takeaways

- scanf returns count of successfully matched items
- Return 0 means matching failure (type mismatch)
- Return EOF (-1) means end of file or error
- Always validate scanf return in real programs
- Clear buffer with `while(getchar() != '\n')` after failure
- Use loop for robust input validation

## Challenge

Write a menu-driven program that gracefully handles non-numeric input for menu selections without crashing.

## Related

- [[056-scanf-basics]] — scanf fundamentals
- [[066-input-validation]] — Input validation techniques
