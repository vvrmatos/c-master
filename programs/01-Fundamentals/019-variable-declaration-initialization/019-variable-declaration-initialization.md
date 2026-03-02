---
id: "019"
title: "Variable Declaration & Initialization"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - variables
  - declaration
  - initialization
difficulty: beginner
source: "K&R Chapter 2, C11 Standard"
---

# 019 — Variable Declaration & Initialization

## Concept

**Declaration** creates a variable (reserves memory). **Initialization** gives it an initial value.

```c
int x;          // Declaration only (value undefined!)
int y = 10;     // Declaration + initialization
x = 5;          // Assignment (after declaration)
```

**Critical rule: Uninitialized local variables have UNDEFINED values!**

```c
int garbage;
printf("%d", garbage);  // Could print anything! Undefined behavior!
```

**Why this matters:**
- Uninitialized variables are a common source of bugs
- Can leak sensitive data from stack
- Security vulnerability: info leaks from uninitialized memory

**Best practices:**
```c
// GOOD: Initialize at declaration
int count = 0;
char *ptr = NULL;
double sum = 0.0;

// BAD: Uninitialized
int count;      // What's in count? Who knows!
char *ptr;      // Dangling pointer!
```

**C99 allows declaration anywhere:**
```c
// C89: all declarations at start of block
int main(void) {
    int x = 0;
    int y = 0;
    // ... code ...
}

// C99+: declare when needed
int main(void) {
    // ... code ...
    int x = 0;  // Can declare here
    // ... more code ...
}
```

**Declaration vs Definition:**
- Declaration: "this variable exists"
- Definition: "create storage for this variable"
- For locals, declaration = definition

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Variable Declaration & Initialization ===\n\n");
    
    int a;
    printf("Declared but not initialized:\n");
    printf("  int a; (value is UNDEFINED - garbage!)\n\n");
    
    int b = 10;
    printf("Declared and initialized:\n");
    printf("  int b = 10; -> b = %d\n\n", b);
    
    int x, y, z;
    x = 1;
    y = 2;
    z = 3;
    printf("Declared, then assigned:\n");
    printf("  int x, y, z;\n");
    printf("  x = %d, y = %d, z = %d\n\n", x, y, z);
    
    int p = 5, q = 10, r = 15;
    printf("Multiple declarations with initialization:\n");
    printf("  int p = 5, q = 10, r = 15;\n");
    printf("  p = %d, q = %d, r = %d\n\n", p, q, r);
    
    const int MAX = 100;
    printf("Constant (must be initialized):\n");
    printf("  const int MAX = %d;\n", MAX);
    
    return 0;
}
```

## Output

```
=== Variable Declaration & Initialization ===

Declared but not initialized:
  int a; (value is UNDEFINED - garbage!)

Declared and initialized:
  int b = 10; -> b = 10

Declared, then assigned:
  int x, y, z;
  x = 1, y = 2, z = 3

Multiple declarations with initialization:
  int p = 5, q = 10, r = 15;
  p = 5, q = 10, r = 15

Constant (must be initialized):
  const int MAX = 100;
```

## Key Takeaways

- Always initialize variables when declaring
- Uninitialized local variables have undefined values
- `const` variables MUST be initialized
- C99+ allows declarations anywhere in a block
- Uninitialized memory is a security risk
- Global and static variables ARE auto-initialized to 0

## Challenge

Create a program that deliberately reads an uninitialized variable. Run it multiple times — do you get different values? Compile with `-Wall -Wuninitialized` to see the warning.

## Related

- [[020-multiple-variable-declaration]] — Declaration syntax
- [[025-const-qualifier]] — Constant variables
- [[028-static-variables]] — Auto-initialized to 0
