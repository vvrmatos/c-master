---
id: "094"
title: "Logical OR Operator"
category: "01-Fundamentals"
tags: ["logical", "operators", "or", "boolean"]
difficulty: "beginner"
---

# Logical OR Operator

## Concept

The `||` operator performs a logical OR operation:
- Returns 1 if **at least one** operand is non-zero (true)
- Returns 0 only if **both** operands are zero (false)

**Truth table**:
| A | B | A \|\| B |
|---|---|----------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

**Key feature**: Short-circuit evaluation—if the first operand is true, the second is not evaluated.

## Code

```c
// Logical OR operator

#include <stdio.h>

int main(void) {
    int a = 1, b = 0, c = 0;
    
    // Basic OR
    printf("%d || %d = %d\n", a, a, a || a);
    printf("%d || %d = %d\n", a, b, a || b);
    printf("%d || %d = %d\n", b, c, b || c);
    
    // Practical use: input validation
    char ch = 'Y';
    if (ch == 'Y' || ch == 'y') {
        printf("\nUser confirmed with '%c'\n", ch);
    }
    
    // Multiple alternatives
    int day = 6;  // Saturday
    if (day == 0 || day == 6) {
        printf("Day %d is a weekend\n", day);
    }
    
    // Checking multiple error conditions
    int error1 = 0, error2 = 1, error3 = 0;
    if (error1 || error2 || error3) {
        printf("\nAt least one error occurred\n");
    }
    
    // Non-boolean values
    printf("\n5 || 0 = %d\n", 5 || 0);
    printf("0 || 0 = %d\n", 0 || 0);
    
    return 0;
}
```

## Output

```
1 || 1 = 1
1 || 0 = 1
0 || 0 = 0

User confirmed with 'Y'
Day 6 is a weekend

At least one error occurred

5 || 0 = 1
0 || 0 = 0
```

## Key Takeaways

1. `||` returns 1 if at least one operand is true
2. Short-circuits: stops at first true operand
3. Commonly used for checking alternatives
4. Lower precedence than `&&`
5. Use for default values: `value = input || default;`

## Kata Challenge

**Vowel Checker**

Write a function that checks if a character is a vowel (case-insensitive):

```c
// Your solution here
// int is_vowel(char c);
// Returns 1 if c is a vowel (a, e, i, o, u), 0 otherwise
// Should work for both uppercase and lowercase

// Test cases:
// is_vowel('a') -> 1
// is_vowel('E') -> 1
// is_vowel('x') -> 0
// is_vowel('Z') -> 0
```

Hint: Use multiple `||` conditions or convert to lowercase first.
