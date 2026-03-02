---
id: "095"
title: "Logical NOT Operator"
category: "01-Fundamentals"
tags: ["logical", "operators", "not", "negation", "boolean"]
difficulty: "beginner"
---

# Logical NOT Operator

## Concept

The `!` operator is the logical NOT (negation) operator:
- Returns 1 if the operand is zero (false)
- Returns 0 if the operand is non-zero (true)

**Truth table**:
| A | !A |
|---|---|
| 0 | 1 |
| non-zero | 0 |

**Common uses**:
- Invert a condition: `if (!is_valid)`
- Check for null/zero: `if (!ptr)`
- Normalize to boolean: `!!value` gives 0 or 1

## Code

```c
// Logical NOT operator

#include <stdio.h>

int main(void) {
    int a = 1, b = 0;
    
    // Basic NOT
    printf("!%d = %d\n", a, !a);
    printf("!%d = %d\n", b, !b);
    
    // Double negation
    printf("!!%d = %d\n", a, !!a);
    printf("!!%d = %d\n", b, !!b);
    
    // Normalize to boolean (0 or 1)
    int x = 42;
    printf("\nx = %d, !!x = %d (normalized)\n", x, !!x);
    
    // Negating conditions
    int is_valid = 1;
    if (!is_valid) {
        printf("Invalid!\n");
    } else {
        printf("\nData is valid\n");
    }
    
    // Toggle boolean
    is_valid = !is_valid;
    printf("After toggle: %d\n", is_valid);
    
    // Common pattern: check for null/zero
    char *ptr = NULL;
    if (!ptr) {
        printf("\nPointer is NULL\n");
    }
    
    return 0;
}
```

## Output

```
!1 = 0
!0 = 1
!!1 = 1
!!0 = 0

x = 42, !!x = 1 (normalized)

Data is valid
After toggle: 0

Pointer is NULL
```

## Key Takeaways

1. `!` converts non-zero to 0 and zero to 1
2. `!!` normalizes any value to 0 or 1
3. `!` has high precedence (unary operator)
4. Commonly used to check for null: `if (!ptr)`
5. Can toggle boolean values: `flag = !flag`

## Kata Challenge

**De Morgan's Laws**

Verify De Morgan's laws with code:
- `!(A && B)` is equivalent to `(!A || !B)`
- `!(A || B)` is equivalent to `(!A && !B)`

```c
// Your solution here
// Write a program that tests all combinations of A and B (0 and 1)
// and verifies De Morgan's laws hold

// For each combination, print:
// A=0, B=0: !(A && B) = ?, (!A || !B) = ? -> match/mismatch
// A=0, B=1: !(A && B) = ?, (!A || !B) = ? -> match/mismatch
// ...
```

Hint: Use nested loops to test all combinations.
