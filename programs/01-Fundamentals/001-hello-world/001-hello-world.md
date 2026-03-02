---
id: "001"
title: "Hello World"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - main
  - first-program
difficulty: beginner
source: "K&R The C Programming Language, Chapter 1"
---

# 001 — Hello World

## Concept

Every C program starts with the `main()` function — this is the **entry point** where execution begins. The operating system calls `main()` when you run your compiled program. Unlike interpreted languages, C must be **compiled** before execution, producing a native binary that runs directly on hardware.

The `#include <stdio.h>` directive tells the preprocessor to include the **Standard Input/Output** library header, which provides `printf()` and other I/O functions. Without this include, the compiler won't know what `printf()` is.

Key components:
- `#include <stdio.h>` — preprocessor directive to include standard I/O
- `int main(void)` — main function returning an integer, taking no arguments
- `printf()` — formatted output function
- `\n` — newline escape sequence
- `return 0` — indicates successful program termination

> **Why C for Security**: C gives you direct memory access and compiles to efficient native code. Most operating systems, embedded systems, and security tools are written in C. Understanding C is fundamental to understanding how computers actually work.

## Code

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    
    printf("Welcome to C programming!\n");
    
    printf("[*] Initializing system...\n");
    printf("[+] Ready.\n");
    
    return 0;
}
```

## Output

```
Hello, World!
Welcome to C programming!
[*] Initializing system...
[+] Ready.
```

## Compilation

```bash
gcc 001-hello-world.c -o 001-hello-world
./001-hello-world
```

## Key Takeaways

- Every C program needs a `main()` function — it's the entry point
- `#include <stdio.h>` makes `printf()` available
- `printf()` outputs formatted text to stdout (standard output)
- `\n` is the newline character — printf does NOT add newlines automatically
- `return 0` signals successful execution to the operating system
- C is **compiled**, not interpreted — very fast execution

## Challenge

Modify the program to print your name and the current date. Use multiple `printf()` calls to format it nicely.

## Related

- [[002-main-function-anatomy]] — Deep dive into main()
- [[003-return-values-from-main]] — What return values mean
- [[004-compilation-process]] — How compilation works
- [[041-printf-basics]] — printf in detail
