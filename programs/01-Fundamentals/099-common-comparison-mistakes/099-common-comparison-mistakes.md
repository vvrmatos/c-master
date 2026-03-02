---
id: "099"
title: "Common Comparison Mistakes"
category: "01-Fundamentals"
tags: ["comparison", "mistakes", "bugs", "assignment", "equality"]
difficulty: "intermediate"
---

# Common Comparison Mistakes

## Concept

These are the most common comparison-related bugs in C:

1. **`=` vs `==`**: Assignment vs equality
   - `if (x = 5)` assigns 5 to x, then evaluates to true
   - `if (x == 5)` compares x to 5

2. **Floating-point equality**: Due to precision issues
   - `0.1 + 0.2 == 0.3` is often false!
   - Use epsilon comparison instead

3. **`&` vs `&&`** and **`|` vs `||`**:
   - Single `&` and `|` are bitwise operators
   - Double `&&` and `||` are logical operators

4. **Comparing strings with `==`**:
   - Compares pointers, not contents
   - Use `strcmp()` instead

## Code

```c
// Common comparison mistakes: = vs ==

#include <stdio.h>

int main(void) {
    int x = 5;
    
    // MISTAKE: Assignment instead of comparison
    // This assigns 10 to x, then checks if 10 is true (it is!)
    if (x = 10) {  // WARNING: should be x == 10
        printf("Bug! x is now %d (assigned, not compared)\n", x);
    }
    
    // Correct comparison
    x = 5;
    if (x == 10) {
        printf("x equals 10\n");
    } else {
        printf("x is %d, not 10 (correct comparison)\n", x);
    }
    
    // Yoda conditions: put constant first
    // if (10 == x) { }  // Compiler error if you typo: 10 = x
    
    // MISTAKE: Comparing floating point directly
    double a = 0.1 + 0.2;
    if (a == 0.3) {  // Often fails!
        printf("Equal\n");
    } else {
        printf("\nBug! 0.1 + 0.2 != 0.3 (%.17f)\n", a);
    }
    
    // MISTAKE: Single & instead of &&
    int p = 1, q = 2;
    printf("\nBitwise vs Logical:\n");
    printf("1 & 2 = %d (bitwise AND)\n", p & q);
    printf("1 && 2 = %d (logical AND)\n", p && q);
    
    return 0;
}
```

## Output

```
Bug! x is now 10 (assigned, not compared)
x is 5, not 10 (correct comparison)

Bug! 0.1 + 0.2 != 0.3 (0.30000000000000004)

Bitwise vs Logical:
1 & 2 = 0 (bitwise AND)
1 && 2 = 1 (logical AND)
```

## Key Takeaways

1. `=` is assignment, `==` is comparison—C allows `=` in conditions!
2. Use `-Wparentheses` or Yoda conditions to catch `=` vs `==` bugs
3. Never compare floats with `==`; use epsilon comparison
4. `&` is bitwise, `&&` is logical (same for `|` vs `||`)
5. Enable compiler warnings: `-Wall -Wextra`

## Kata Challenge

**Bug Finder**

Find and fix all the bugs in this code:

```c
// Your solution here - fix these bugs:

int validate_user(int age, double balance, char *name) {
    // Bug 1: Assignment in condition
    if (age = 18) {
        return 0;  // Must be exactly 18
    }
    
    // Bug 2: Float comparison
    if (balance == 0.0) {
        return 0;  // No zero balance
    }
    
    // Bug 3: Wrong operator
    if (age > 0 & balance > 0) {
        // Both positive
    }
    
    // Bug 4: String comparison
    if (name == "admin") {
        return 0;  // Reserved name
    }
    
    return 1;
}
```

Challenge: Rewrite with all bugs fixed and add proper float comparison.
