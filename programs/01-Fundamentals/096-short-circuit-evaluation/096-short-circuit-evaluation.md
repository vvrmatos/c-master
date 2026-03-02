---
id: "096"
title: "Short-Circuit Evaluation"
category: "01-Fundamentals"
tags: ["logical", "operators", "short-circuit", "evaluation", "optimization"]
difficulty: "intermediate"
---

# Short-Circuit Evaluation

## Concept

Short-circuit evaluation means logical operators stop evaluating as soon as the result is determined:

**For `&&` (AND)**:
- If the first operand is false (0), the result is false
- Second operand is **not evaluated**

**For `||` (OR)**:
- If the first operand is true (non-zero), the result is true
- Second operand is **not evaluated**

**Why it matters**:
- Performance: skip expensive checks
- Safety: avoid operations that would crash (null pointer, out of bounds)
- Side effects: function calls may be skipped

## Code

```c
// Short-circuit evaluation

#include <stdio.h>

int check_a(void) {
    printf("  Checking A...\n");
    return 0;  // false
}

int check_b(void) {
    printf("  Checking B...\n");
    return 1;  // true
}

int main(void) {
    printf("AND short-circuit (false && ?):\n");
    if (check_a() && check_b()) {
        printf("Both true\n");
    } else {
        printf("  B was NOT checked!\n\n");
    }
    
    printf("OR short-circuit (true || ?):\n");
    if (check_b() || check_a()) {
        printf("  A was NOT checked!\n\n");
    }
    
    // Practical use: safe pointer dereference
    int *ptr = NULL;
    if (ptr != NULL && *ptr > 0) {
        printf("Value is positive\n");
    } else {
        printf("Safe: didn't dereference NULL\n");
    }
    
    // Practical use: bounds check before access
    int arr[] = {10, 20, 30};
    int index = 5;
    if (index >= 0 && index < 3 && arr[index] > 0) {
        printf("arr[%d] = %d\n", index, arr[index]);
    } else {
        printf("Safe: didn't access out of bounds\n");
    }
    
    return 0;
}
```

## Output

```
AND short-circuit (false && ?):
  Checking A...
  B was NOT checked!

OR short-circuit (true || ?):
  Checking B...
  A was NOT checked!

Safe: didn't dereference NULL
Safe: didn't access out of bounds
```

## Key Takeaways

1. `&&` stops at first false operand
2. `||` stops at first true operand
3. Order matters—put cheap/safe checks first
4. Use for safe pointer checks: `ptr && *ptr`
5. Functions with side effects may not be called!

## Kata Challenge

**Safe Accessor Chain**

Write a function that safely accesses nested data using short-circuit:

```c
// Your solution here
// Given a structure like:
struct Node {
    int value;
    struct Node *next;
};

// Write: int safe_get_second(struct Node *head, int *result);
// Returns 0 and sets result if head->next exists and has a value
// Returns -1 if head is NULL or head->next is NULL

// Test cases:
// NULL -> returns -1
// {10, NULL} -> returns -1 (no second node)
// {10, {20, NULL}} -> returns 0, result = 20
```

Hint: Chain checks with `&&`: `head && head->next && ...`
