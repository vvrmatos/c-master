---
id: "007"
title: "Compilation Errors vs Warnings"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - gcc
  - errors
  - warnings
  - debugging
difficulty: beginner
source: "GCC Manual"
---

# 007 — Compilation Errors vs Warnings

## Concept

The compiler gives you two types of messages:

**Errors** — The compiler cannot proceed. Something is fundamentally wrong:
- Syntax errors (`int x = ;`)
- Missing semicolons
- Undeclared variables/functions
- Type mismatches that can't be resolved

**Warnings** — The compiler can continue, but something looks suspicious:
- Unused variables
- Implicit type conversions that might lose data
- Using uninitialized variables
- Format string mismatches

**GCC Warning Flags:**

| Flag | Description |
|------|-------------|
| `-Wall` | Enable "all" common warnings (not actually all) |
| `-Wextra` | Enable additional warnings |
| `-Werror` | Treat all warnings as errors (won't compile) |
| `-pedantic` | Strict ISO C compliance warnings |
| `-Wshadow` | Warn when variable shadows another |
| `-Wconversion` | Warn on implicit type conversions |

**Recommended compilation:**
```bash
gcc -Wall -Wextra -std=c17 file.c -o program
```

**For maximum strictness (production code):**
```bash
gcc -Wall -Wextra -Werror -pedantic -std=c17 file.c -o program
```

**Why warnings matter for security:**
- Format string warnings can reveal vulnerabilities
- Uninitialized variables can leak data
- Buffer size warnings hint at overflow potential

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Compilation Warnings Demo ===\n\n");
    
    printf("Compile with: gcc -Wall -Wextra -Werror file.c\n\n");
    
    printf("Common warnings:\n");
    printf("  -Wall    : Enable common warnings\n");
    printf("  -Wextra  : Enable extra warnings\n");
    printf("  -Werror  : Treat warnings as errors\n");
    printf("  -pedantic: Strict ISO C compliance\n\n");
    
    int x = 42;
    printf("This code is clean: x = %d\n", x);
    
    printf("\nAlways compile with -Wall -Wextra!\n");
    printf("Warnings often reveal bugs.\n");
    
    return 0;
}
```

## Output

```
=== Compilation Warnings Demo ===

Compile with: gcc -Wall -Wextra -Werror file.c

Common warnings:
  -Wall    : Enable common warnings
  -Wextra  : Enable extra warnings
  -Werror  : Treat warnings as errors
  -pedantic: Strict ISO C compliance

This code is clean: x = 42

Always compile with -Wall -Wextra!
Warnings often reveal bugs.
```

## Examples That Generate Warnings

```c
// Warning: unused variable
int unused;

// Warning: format specifier mismatch
printf("%d", 3.14);  // %d expects int, got double

// Warning: implicit function declaration
// (if you forget #include <string.h>)
strlen("test");

// Warning: comparison between signed and unsigned
int x = -1;
unsigned int y = 1;
if (x < y) { }  // Might not work as expected!
```

## Key Takeaways

- **Errors** stop compilation; **warnings** don't (by default)
- Always compile with `-Wall -Wextra` at minimum
- Use `-Werror` to force fixing all warnings
- Warnings often indicate real bugs
- `-pedantic` ensures standard compliance
- Format string warnings are security-relevant

## Challenge

Create a file with intentional warnings (unused variable, format mismatch) and compile with different flag combinations to see the messages.

## Related

- [[004-compilation-process]] — How compilation works
- [[041-printf-basics]] — Format specifiers
- [[099-common-comparison-mistakes]] — Warning-prone patterns
