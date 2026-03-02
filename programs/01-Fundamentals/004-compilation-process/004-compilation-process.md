---
id: "004"
title: "Compilation Process"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - compilation
  - gcc
  - preprocessor
  - linker
difficulty: beginner
source: "GCC Manual"
---

# 004 — Compilation Process

## Concept

Unlike interpreted languages (Python, JavaScript), C code must be **compiled** before it can run. Compilation transforms human-readable source code into machine code that the CPU can execute directly.

**The Four Stages of Compilation:**

1. **Preprocessing** (`gcc -E`)
   - Handles `#include` directives (inserts header file contents)
   - Expands `#define` macros
   - Processes conditional compilation (`#ifdef`, `#ifndef`)
   - Removes comments
   - Output: Preprocessed C code (still text)

2. **Compilation** (`gcc -S`)
   - Parses C code and checks syntax
   - Generates assembly language for target architecture
   - Output: Assembly file (`.s`)

3. **Assembly** (`gcc -c`)
   - Converts assembly to machine code
   - Output: Object file (`.o`) — binary but not yet executable

4. **Linking** (`gcc file.o -o program`)
   - Combines object files
   - Resolves external references (like `printf`)
   - Links with libraries (libc, etc.)
   - Output: Executable binary

**GCC Commands:**
```bash
gcc -E file.c -o file.i    # Preprocess only
gcc -S file.c              # Compile to assembly (.s)
gcc -c file.c              # Compile to object (.o)
gcc file.c -o program      # Full compilation
gcc -v file.c              # Verbose (show all steps)
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== C Compilation Process Demo ===\n\n");
    
    printf("Stage 1: Preprocessing\n");
    printf("  - #include files are inserted\n");
    printf("  - #define macros are expanded\n\n");
    
    printf("Stage 2: Compilation\n");
    printf("  - C code -> Assembly code\n\n");
    
    printf("Stage 3: Assembly\n");
    printf("  - Assembly -> Object code (.o)\n\n");
    
    printf("Stage 4: Linking\n");
    printf("  - Object files + libraries -> Executable\n\n");
    
    printf("Compile commands:\n");
    printf("  gcc -E file.c        # Preprocess only\n");
    printf("  gcc -S file.c        # Compile to assembly\n");
    printf("  gcc -c file.c        # Compile to object file\n");
    printf("  gcc file.c -o prog   # Full compilation\n");
    
    return 0;
}
```

## Output

```
=== C Compilation Process Demo ===

Stage 1: Preprocessing
  - #include files are inserted
  - #define macros are expanded

Stage 2: Compilation
  - C code -> Assembly code

Stage 3: Assembly
  - Assembly -> Object code (.o)

Stage 4: Linking
  - Object files + libraries -> Executable

Compile commands:
  gcc -E file.c        # Preprocess only
  gcc -S file.c        # Compile to assembly
  gcc -c file.c        # Compile to object file
  gcc file.c -o prog   # Full compilation
```

## Key Takeaways

- C compilation has 4 stages: Preprocess → Compile → Assemble → Link
- `gcc -E` shows preprocessor output (useful for debugging macros)
- `gcc -S` produces assembly (useful for understanding optimizations)
- `gcc -c` produces object files (for separate compilation)
- Object files (`.o`) are binary but need linking to run
- The linker combines everything and resolves external symbols

## Challenge

Run each stage separately on this file:
1. `gcc -E 004-compilation-process.c -o output.i` — examine the preprocessed output
2. `gcc -S 004-compilation-process.c` — look at the assembly in `.s` file
3. `gcc -c 004-compilation-process.c` — check the size of the `.o` file
4. Compare sizes at each stage

## Related

- [[005-preprocessor-and-include]] — Preprocessor details
- [[007-compilation-errors-vs-warnings]] — Understanding errors
- [[008-multiple-source-files]] — Separate compilation
- [[010-makefiles-introduction]] — Automating builds
