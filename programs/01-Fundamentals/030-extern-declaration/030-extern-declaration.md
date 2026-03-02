---
id: "030"
title: "The extern Declaration"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - extern
  - linkage
  - storage-class
  - multi-file
difficulty: beginner
source: "C11 Standard 6.2.2, 6.7.1"
---

# 030 — The extern Declaration

## Concept

`extern` declares a variable or function that is **defined elsewhere**. It's how C handles sharing variables across multiple source files.

**Declaration vs Definition:**
```c
int x = 10;        // Definition: allocates memory
extern int x;      // Declaration: "x exists somewhere"
```

**Key rule: One Definition Rule**
- A variable can be **declared** many times (`extern int x;`)
- But **defined** only once (`int x = 10;`)

**Multi-file pattern:**

```c
// === globals.h ===
extern int count;         // Declaration (in header)
extern const char *name;

// === globals.c ===
#include "globals.h"
int count = 0;            // Definition (in one .c file)
const char *name = "App";

// === main.c ===
#include "globals.h"      // Now main.c can use count and name
```

**Linkage types:**

| Declaration | Linkage | Visibility |
|-------------|---------|------------|
| `int x;` (file scope) | External | All files |
| `extern int x;` | External | All files |
| `static int x;` | Internal | This file only |
| `int x;` (block scope) | None | This block only |

**Functions are implicitly extern:**
```c
void func(void);         // Implicitly extern
extern void func(void);  // Same thing
static void func(void);  // Internal linkage (file-private)
```

**extern with initialization:**
```c
extern int x = 10;  // This is a DEFINITION (extern ignored)
```
If you initialize an `extern` declaration, it becomes a definition.

## Code

```c
#include <stdio.h>

int global_counter = 100;

extern int external_var;

void increment_counter(void);
void show_external(void);

int external_var = 42;

void increment_counter(void) {
    global_counter++;
}

void show_external(void) {
    printf("  external_var = %d\n", external_var);
}

int main(void) {
    printf("=== The extern Declaration ===\n\n");
    
    printf("--- What is extern? ---\n");
    printf("extern declares a variable without defining it.\n");
    printf("It says: 'This variable exists somewhere else.'\n");
    
    printf("\n--- Declaration vs Definition ---\n");
    printf("int x = 10;       // Definition: allocates memory, initializes\n");
    printf("extern int x;     // Declaration: just announces existence\n");
    printf("extern int x = 10; // Definition (extern ignored when initialized)\n");
    
    printf("\n--- Using extern with Global Variables ---\n");
    printf("global_counter starts at: %d\n", global_counter);
    increment_counter();
    increment_counter();
    printf("After 2 increments:       %d\n", global_counter);
    
    printf("\n--- External Variable in Same File ---\n");
    show_external();
    external_var = 999;
    printf("  After modification: external_var = %d\n", external_var);
    
    printf("\n--- Common Multi-File Pattern ---\n");
    printf("// === config.h ===\n");
    printf("extern int debug_level;      // Declaration\n");
    printf("extern const char *app_name; // Declaration\n");
    printf("\n// === config.c ===\n");
    printf("#include \"config.h\"\n");
    printf("int debug_level = 1;         // Definition\n");
    printf("const char *app_name = \"MyApp\"; // Definition\n");
    printf("\n// === main.c ===\n");
    printf("#include \"config.h\"\n");
    printf("// Can now use debug_level and app_name\n");
    
    printf("\n--- Linkage Types ---\n");
    printf("| Declaration          | Linkage   | Visible To        |\n");
    printf("|----------------------|-----------|-------------------|\n");
    printf("| int x;               | External  | All files         |\n");
    printf("| extern int x;        | External  | All files         |\n");
    printf("| static int x;        | Internal  | This file only    |\n");
    printf("| void func() { int x; } | None    | This function only |\n");
    
    printf("\n--- extern with Functions ---\n");
    printf("Functions are implicitly extern by default:\n");
    printf("  void func(void);        // Implicitly extern\n");
    printf("  extern void func(void); // Same thing, explicit\n");
    printf("  static void func(void); // Internal linkage\n");
    
    printf("\n--- Best Practices ---\n");
    printf("1. Declare extern variables in header files\n");
    printf("2. Define them in exactly one .c file\n");
    printf("3. Use static for file-private variables\n");
    printf("4. Minimize global variables (prefer passing parameters)\n");
    
    printf("\n--- One Definition Rule ---\n");
    printf("A variable can be DECLARED multiple times (extern)\n");
    printf("but DEFINED only once across all files.\n");
    printf("Violating this causes linker errors.\n");
    
    return 0;
}
```

## Output

```
=== The extern Declaration ===

--- What is extern? ---
extern declares a variable without defining it.
It says: 'This variable exists somewhere else.'

--- Declaration vs Definition ---
int x = 10;       // Definition: allocates memory, initializes
extern int x;     // Declaration: just announces existence
extern int x = 10; // Definition (extern ignored when initialized)

--- Using extern with Global Variables ---
global_counter starts at: 100
After 2 increments:       102

--- External Variable in Same File ---
  external_var = 42
  After modification: external_var = 999

--- Common Multi-File Pattern ---
// === config.h ===
extern int debug_level;      // Declaration
extern const char *app_name; // Declaration

// === config.c ===
#include "config.h"
int debug_level = 1;         // Definition
const char *app_name = "MyApp"; // Definition

// === main.c ===
#include "config.h"
// Can now use debug_level and app_name

--- Linkage Types ---
| Declaration          | Linkage   | Visible To        |
|----------------------|-----------|-------------------|
| int x;               | External  | All files         |
| extern int x;        | External  | All files         |
| static int x;        | Internal  | This file only    |
| void func() { int x; } | None    | This function only |

--- extern with Functions ---
Functions are implicitly extern by default:
  void func(void);        // Implicitly extern
  extern void func(void); // Same thing, explicit
  static void func(void); // Internal linkage

--- Best Practices ---
1. Declare extern variables in header files
2. Define them in exactly one .c file
3. Use static for file-private variables
4. Minimize global variables (prefer passing parameters)

--- One Definition Rule ---
A variable can be DECLARED multiple times (extern)
but DEFINED only once across all files.
Violating this causes linker errors.
```

## Key Takeaways

- `extern` declares a variable without defining it
- Use for sharing variables across multiple .c files
- Put `extern` declarations in header files
- Put the actual definition in exactly one .c file
- Functions are implicitly `extern` (no keyword needed)
- Use `static` at file scope for file-private symbols
- One Definition Rule: declare many times, define once

## Challenge

Create a three-file program: `config.h` (extern declarations), `config.c` (definitions), and `main.c` (uses the variables). Include a counter that's incremented by functions in different files to demonstrate shared state.

## Related

- [[028-static-variables]] — static for internal linkage
- [[009-header-files-basics]] — header file basics
- [[008-multiple-source-files]] — multi-file programs
