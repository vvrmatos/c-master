---
id: "006"
title: "Comments"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - comments
  - documentation
difficulty: beginner
source: "C11 Standard Section 6.4.9"
---

# 006 — Comments

## Concept

Comments are text ignored by the compiler. They're for **human readers** — explaining code, documenting intent, or temporarily disabling code.

**Two Types of Comments in C:**

1. **Single-line comments** (C99 and later):
   ```c
   // This comment goes to end of line
   int x = 10;  // Can also follow code
   ```

2. **Multi-line (block) comments** (Original C):
   ```c
   /* This comment can span
      multiple lines and is
      closed with */
   ```

**Important Rules:**
- Comments are removed during preprocessing
- Block comments **cannot be nested**: `/* outer /* inner */ oops */` breaks
- Single-line comments end at newline
- In C89/C90, only `/* */` comments are valid

**Best Practices:**
- Comment **why**, not **what** (code shows what)
- Keep comments updated when code changes
- Use comments for TODO, FIXME, HACK markers
- Document function purpose, parameters, return values

**Note:** Our learning programs use **no comments in .c files** — explanations go in the accompanying .md file. This keeps code clean and readable.

## Code

```c
#include <stdio.h>

/* Note: This file is shown without comments as per project rules.
   In practice, you would see comments like:
   
   // Single-line comment
   
   /* Multi-line
      comment */
   
   int x = 10;  // Inline comment
*/

int main(void) {
    printf("=== Comments in C ===\n\n");
    
    int x = 10;
    int y = 20;
    int sum = x + y;
    
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("sum = %d\n", sum);
    
    printf("\nComments are removed by the preprocessor.\n");
    printf("They don't affect the compiled program.\n");
    
    return 0;
}
```

## Output

```
=== Comments in C ===

x = 10
y = 20
sum = 30

Comments are removed by the preprocessor.
They don't affect the compiled program.
```

## Comment Styles Example

```c
// Single-line: good for short notes

/* Multi-line: good for longer explanations
   or temporarily disabling blocks of code */

int calculate(int x) {  // inline comment after code
    return x * 2;
}

/* 
 * Function: process_data
 * -----------------------
 * Documented function header style
 * 
 * Parameters:
 *   data - pointer to data buffer
 *   len  - length of data
 * 
 * Returns: 0 on success, -1 on error
 */
```

## Key Takeaways

- `//` is single-line (C99+), `/* */` is multi-line
- Comments are removed by the preprocessor
- Block comments don't nest — be careful when commenting out code
- Comment **why**, not **what**
- For C89 compatibility, use only `/* */`
- Good comments explain intent, not mechanics

## Challenge

Try to nest block comments and see the compiler error:
```c
/* outer /* inner */ still in comment? */
```

## Related

- [[004-compilation-process]] — When comments are removed
- [[005-preprocessor-and-include]] — Preprocessor stage
