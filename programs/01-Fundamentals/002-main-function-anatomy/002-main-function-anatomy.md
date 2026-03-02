---
id: "002"
title: "Main Function Anatomy"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - main
  - entry-point
  - function
difficulty: beginner
source: "C11 Standard 5.1.2.2.1"
---

# 002 — Main Function Anatomy

## Concept

The `main()` function is special in C — it's the **only function** that the runtime automatically calls. Every executable C program must have exactly one `main()` function.

**Two valid signatures for main:**

```c
int main(void)              // No command-line arguments
int main(int argc, char *argv[])  // With command-line arguments
```

The return type is `int` because `main()` returns an **exit status** to the operating system:
- `return 0` or `return EXIT_SUCCESS` — program succeeded
- `return 1` (or any non-zero) or `return EXIT_FAILURE` — program failed

**Anatomy breakdown:**
- `int` — return type (status code)
- `main` — function name (must be exactly this)
- `(void)` — parameter list; `void` means no parameters
- `{ }` — function body where your code lives
- `return 0;` — exit status (0 = success)

The `void` in `int main(void)` explicitly says "this function takes no arguments." In C, empty parentheses `()` have different meaning — they mean "unspecified arguments" (legacy behavior).

## Code

```c
#include <stdio.h>

int main(void) {
    printf("Program starting...\n");
    
    int x = 42;
    printf("x = %d\n", x);
    
    printf("Program ending...\n");
    
    return 0;
}
```

## Output

```
Program starting...
x = 42
Program ending...
```

## Key Takeaways

- `main()` is the entry point — execution starts here
- Always use `int main(void)` or `int main(int argc, char *argv[])`
- `void` in parameter list means "no parameters" explicitly
- Empty `()` is different from `(void)` — always prefer `(void)`
- Return `0` for success, non-zero for failure
- Only ONE `main()` per program

## Challenge

What happens if you remove the `return 0;` statement? In C99 and later, reaching the end of `main()` without a return is equivalent to `return 0;`. Try compiling with `-std=c89` to see older behavior.

## Related

- [[001-hello-world]] — First program basics
- [[003-return-values-from-main]] — Exit status in detail
- [[171-function-declaration]] — General function anatomy
- [[200-command-line-arguments]] — Using argc and argv
