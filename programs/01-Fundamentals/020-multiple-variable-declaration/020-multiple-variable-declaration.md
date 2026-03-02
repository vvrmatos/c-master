---
id: "020"
title: "Multiple Variable Declaration"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - variables
  - declaration
  - style
difficulty: beginner
source: "K&R Chapter 2"
---

# 020 — Multiple Variable Declaration

## Concept

You can declare multiple variables of the same type in one statement:

```c
int a, b, c;                    // Three ints
int x = 1, y = 2, z = 3;        // With initialization
double width, height, depth;    // Three doubles
```

**THE BIG GOTCHA — Pointers:**

```c
int* p, q;    // WRONG thinking: p and q are both int*
              // REALITY: p is int*, q is int!

int *p, *q;   // CORRECT: both are int*
```

The `*` binds to the variable name, not the type. This is why many style guides recommend:

```c
int *p;       // * with variable name
// rather than
int* p;       // * with type (misleading in multi-declaration)
```

**Best practice: One variable per line**

```c
// Clear and unambiguous
int width = 10;
int height = 20;
int *data = NULL;

// Instead of
int width = 10, height = 20, *data = NULL;  // Confusing
```

**When multiple declaration is OK:**
- Loop variables: `int i, j, k;`
- Related variables: `int min, max;`
- Temporary variables in tight scope

**Initialization in multi-declaration:**
```c
int a = 1, b = 2, c;  // a=1, b=2, c=undefined!
int x, y = 5, z;      // Only y is initialized!
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Multiple Variable Declaration ===\n\n");
    
    int a, b, c;
    a = 1; b = 2; c = 3;
    printf("Same type, declared together:\n");
    printf("  int a, b, c;\n");
    printf("  a = %d, b = %d, c = %d\n\n", a, b, c);
    
    int x = 10, y = 20, z = 30;
    printf("With initialization:\n");
    printf("  int x = 10, y = 20, z = 30;\n");
    printf("  x = %d, y = %d, z = %d\n\n", x, y, z);
    
    printf("GOTCHA with pointers:\n");
    printf("  int* p, q;    // p is pointer, q is int!\n");
    printf("  int *p, *q;   // Both are pointers\n\n");
    
    int *p1, *p2;
    int value = 100;
    p1 = &value;
    p2 = &value;
    printf("Correct pointer declaration:\n");
    printf("  int *p1, *p2;\n");
    printf("  *p1 = %d, *p2 = %d\n\n", *p1, *p2);
    
    printf("Best practice: One declaration per line\n");
    printf("  int width = 10;\n");
    printf("  int height = 20;\n");
    printf("  int *ptr = NULL;\n");
    
    return 0;
}
```

## Output

```
=== Multiple Variable Declaration ===

Same type, declared together:
  int a, b, c;
  a = 1, b = 2, c = 3

With initialization:
  int x = 10, y = 20, z = 30;
  x = 10, y = 20, z = 30

GOTCHA with pointers:
  int* p, q;    // p is pointer, q is int!
  int *p, *q;   // Both are pointers

Correct pointer declaration:
  int *p1, *p2;
  *p1 = 100, *p2 = 100

Best practice: One declaration per line
  int width = 10;
  int height = 20;
  int *ptr = NULL;
```

## Key Takeaways

- Multiple variables can share one declaration
- **Pointer gotcha**: `int *p, q;` — only p is a pointer!
- The `*` binds to the variable, not the type
- Best practice: one declaration per line
- Initialize variables when declaring
- Uninitialized variables in multi-declaration are easy to miss

## Challenge

What are the types of each variable in: `int *a, b, **c, d[10];`? (Answer: a is `int*`, b is `int`, c is `int**`, d is `int[10]`)

## Related

- [[019-variable-declaration-initialization]] — Basic declaration
- [[181-pointer-concept]] — Pointer syntax
- [[182-pointer-declaration]] — Pointer details
