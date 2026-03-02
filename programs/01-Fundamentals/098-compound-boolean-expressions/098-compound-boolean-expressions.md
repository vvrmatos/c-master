---
id: "098"
title: "Compound Boolean Expressions"
category: "01-Fundamentals"
tags: ["boolean", "logical", "compound", "expressions", "precedence"]
difficulty: "intermediate"
---

# Compound Boolean Expressions

## Concept

Compound boolean expressions combine multiple conditions using `&&`, `||`, and `!`. Understanding operator precedence is crucial:

**Precedence (highest to lowest)**:
1. `!` (NOT)
2. `&&` (AND)
3. `||` (OR)

This means `a || b && c` is parsed as `a || (b && c)`, not `(a || b) && c`.

**Best practice**: Use parentheses to make intent clear, even when not strictly necessary.

## Code

```c
// Compound boolean expressions

#include <stdio.h>

int main(void) {
    int age = 25;
    int income = 50000;
    int credit_score = 700;
    int has_job = 1;
    
    // Multiple AND conditions
    if (age >= 18 && income >= 30000 && credit_score >= 650) {
        printf("Loan pre-qualified (basic)\n");
    }
    
    // AND and OR combined
    if ((age >= 21 && income >= 40000) || credit_score >= 750) {
        printf("Loan pre-qualified (premium)\n");
    }
    
    // Complex business logic
    int is_student = 0;
    int is_senior = 0;
    if ((is_student || is_senior) && age >= 16) {
        printf("Discount eligible\n");
    } else if (age >= 65) {
        printf("Senior discount\n");
    }
    
    // Precedence matters: && binds tighter than ||
    // These are different:
    printf("\nPrecedence demo:\n");
    int a = 0, b = 1, c = 1;
    printf("a || b && c = %d\n", a || b && c);    // a || (b && c) = 1
    printf("(a || b) && c = %d\n", (a || b) && c); // Same result here, but...
    
    a = 1; b = 0; c = 0;
    printf("a || b && c = %d\n", a || b && c);     // 1 || (0 && 0) = 1
    printf("(a || b) && c = %d\n", (a || b) && c); // (1 || 0) && 0 = 0
    
    return 0;
}
```

## Output

```
Loan pre-qualified (basic)
Loan pre-qualified (premium)

Precedence demo:
a || b && c = 1
(a || b) && c = 1
a || b && c = 1
(a || b) && c = 0
```

## Key Takeaways

1. `&&` has higher precedence than `||`
2. `!` has the highest precedence among logical operators
3. Use parentheses to clarify complex expressions
4. All conditions are evaluated left-to-right (with short-circuit)
5. Break complex conditions into intermediate variables for readability

## Kata Challenge

**Eligibility Checker**

Write a function that determines if a user is eligible based on complex criteria:

```c
// Your solution here
// int is_eligible(int age, int income, int credit, int employed, int student);
// Eligible if:
// - (age >= 18 AND income >= 30000 AND credit >= 600) OR
// - (student AND age >= 16 AND credit >= 550) OR
// - (age >= 65 AND credit >= 500)

// Test cases:
// is_eligible(25, 50000, 700, 1, 0) -> 1 (meets first condition)
// is_eligible(17, 0, 600, 0, 1)     -> 1 (student, age 17? No, need 16+)
// is_eligible(70, 10000, 520, 0, 0) -> 1 (senior)
// is_eligible(30, 20000, 700, 1, 0) -> 0 (income too low)
```

Hint: Consider breaking into helper functions for readability.
