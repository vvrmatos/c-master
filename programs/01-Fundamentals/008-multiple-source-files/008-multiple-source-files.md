---
id: "008"
title: "Multiple Source Files"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - compilation
  - extern
  - separate-compilation
  - linking
difficulty: beginner
source: "C11 Standard, GCC Manual"
---

# 008 — Multiple Source Files

## Concept

Real C projects split code across multiple `.c` files for organization:
- `main.c` — entry point
- `utils.c` — utility functions
- `network.c` — networking code
- etc.

**How it works:**

1. Each `.c` file is compiled separately to an object file (`.o`)
2. The linker combines all object files into one executable
3. **extern** keyword declares variables/functions defined elsewhere

**Separate compilation:**
```bash
gcc -c main.c       # produces main.o
gcc -c helper.c     # produces helper.o
gcc main.o helper.o -o program  # links into executable
```

**Or all at once:**
```bash
gcc main.c helper.c -o program
```

**The `extern` keyword:**
```c
// In main.c - DECLARE (not define)
extern int counter;  // "counter exists somewhere else"

// In helper.c - DEFINE
int counter = 0;     // actual storage here
```

**Declaration vs Definition:**
- **Declaration**: "This thing exists" (no memory allocated)
- **Definition**: "Here's the thing" (memory allocated)

You can have many declarations, but only ONE definition.

## Code

```c
#include <stdio.h>

// In a real project, these would be in separate files
// For demo, we show the pattern in one file

extern int shared_value;  // Declaration
void helper_function(void);  // Declaration

// Definition (would normally be in another .c file)
int shared_value = 100;

void helper_function(void) {
    printf("Helper called! shared_value = %d\n", shared_value);
    shared_value += 10;
}

int main(void) {
    printf("=== Multiple Source Files Demo ===\n\n");
    
    printf("Initial shared_value = %d\n", shared_value);
    
    helper_function();
    
    printf("After helper: shared_value = %d\n", shared_value);
    
    printf("\nIn real projects:\n");
    printf("  - main.c contains main()\n");
    printf("  - helper.c contains helper functions\n");
    printf("  - shared.h declares shared items\n");
    printf("\nCompile: gcc main.c helper.c -o program\n");
    
    return 0;
}
```

## Output

```
=== Multiple Source Files Demo ===

Initial shared_value = 100
Helper called! shared_value = 100
After helper: shared_value = 110

In real projects:
  - main.c contains main()
  - helper.c contains helper functions
  - shared.h declares shared items

Compile: gcc main.c helper.c -o program
```

## Project Structure Example

```
project/
├── main.c          # int main(void) { ... }
├── helper.c        # helper functions
├── helper.h        # declarations for helper.c
├── utils.c         # utility functions
├── utils.h         # declarations for utils.c
└── Makefile        # build automation
```

## Key Takeaways

- Large projects use multiple `.c` files
- Each `.c` compiles to a `.o` object file
- The linker combines object files
- `extern` declares something defined elsewhere
- **One definition rule**: define things in exactly one place
- Use header files (`.h`) to share declarations

## Challenge

Create two files: `main.c` with main() and `math_ops.c` with an add() function. Use `extern` or a header to share the function.

## Related

- [[004-compilation-process]] — Compilation stages
- [[009-header-files-basics]] — Creating headers
- [[010-makefiles-introduction]] — Automating multi-file builds
- [[030-extern-declaration]] — extern in detail
