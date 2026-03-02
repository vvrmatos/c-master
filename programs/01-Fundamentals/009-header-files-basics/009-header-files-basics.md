---
id: "009"
title: "Header Files Basics"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - headers
  - include-guards
  - declarations
difficulty: beginner
source: "C11 Standard, K&R Chapter 4"
---

# 009 — Header Files Basics

## Concept

**Header files** (`.h`) contain **declarations** that are shared between source files:
- Function prototypes
- Type definitions (`struct`, `typedef`, `enum`)
- Macro definitions (`#define`)
- External variable declarations (`extern`)

**What goes in headers (declarations):**
```c
// mylib.h
extern int count;           // Variable declaration
int add(int a, int b);      // Function declaration
#define MAX 100             // Macro
typedef struct {...} Data;  // Type definition
```

**What goes in source files (definitions):**
```c
// mylib.c
#include "mylib.h"
int count = 0;              // Variable definition
int add(int a, int b) {     // Function definition
    return a + b;
}
```

**Include Guards** prevent multiple inclusion problems:
```c
#ifndef MYHEADER_H    // If not already defined
#define MYHEADER_H    // Define it now

// ... declarations ...

#endif                // End the conditional
```

Without guards, if a header is included twice (directly or indirectly), you get duplicate definition errors.

**Modern alternative** (non-standard but widely supported):
```c
#pragma once          // Simpler, but not in C standard
```

## Code

```c
#include <stdio.h>

// This would normally be in myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX_SIZE 100
#define VERSION "1.0.0"

extern int global_counter;

int add(int a, int b);
void print_message(const char *msg);

#endif
// End of header content

// This would normally be in myheader.c
int global_counter = 0;

int add(int a, int b) {
    return a + b;
}

void print_message(const char *msg) {
    printf("[MSG] %s\n", msg);
    global_counter++;
}

// This would be in main.c
int main(void) {
    printf("=== Header Files Demo ===\n\n");
    
    printf("Header guards prevent multiple inclusion:\n");
    printf("  #ifndef MYHEADER_H\n");
    printf("  #define MYHEADER_H\n");
    printf("  ... declarations ...\n");
    printf("  #endif\n\n");
    
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("VERSION = %s\n", VERSION);
    printf("add(3, 4) = %d\n", add(3, 4));
    
    print_message("Hello from header!");
    printf("global_counter = %d\n", global_counter);
    
    return 0;
}
```

## Output

```
=== Header Files Demo ===

Header guards prevent multiple inclusion:
  #ifndef MYHEADER_H
  #define MYHEADER_H
  ... declarations ...
  #endif

MAX_SIZE = 100
VERSION = 1.0.0
add(3, 4) = 7
[MSG] Hello from header!
global_counter = 1
```

## Header File Template

```c
// filename.h
#ifndef FILENAME_H
#define FILENAME_H

// Includes needed for declarations
#include <stddef.h>

// Constants
#define BUFFER_SIZE 1024

// Type definitions
typedef struct {
    int x;
    int y;
} Point;

// Function declarations
Point create_point(int x, int y);
void print_point(Point p);

// External variable declarations
extern int error_count;

#endif // FILENAME_H
```

## Key Takeaways

- Headers contain **declarations**, source files contain **definitions**
- Always use include guards: `#ifndef`, `#define`, `#endif`
- Use `<>` for system headers, `""` for your headers
- Don't put function definitions in headers (usually)
- Headers enable code sharing between source files
- One header per source file is a common pattern

## Challenge

Create a proper `math_ops.h` and `math_ops.c` with add, subtract, multiply functions. Include the header in `main.c` and use the functions.

## Related

- [[005-preprocessor-and-include]] — #include details
- [[008-multiple-source-files]] — Why we need headers
- [[010-makefiles-introduction]] — Building multi-file projects
- [[030-extern-declaration]] — extern keyword
