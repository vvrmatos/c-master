---
id: "003"
title: "Return Values from Main"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - main
  - exit-status
  - return
difficulty: beginner
source: "C11 Standard, POSIX"
---

# 003 — Return Values from Main

## Concept

When `main()` returns, it sends an **exit status** (also called exit code or return code) to the operating system. This status tells the OS (and any calling programs) whether your program succeeded or failed.

**Standard exit values:**
- `0` — Success (program completed normally)
- Non-zero — Failure (something went wrong)

The `<stdlib.h>` header defines portable constants:
- `EXIT_SUCCESS` — typically 0
- `EXIT_FAILURE` — typically 1

**Why this matters:**
- Shell scripts check exit codes: `if ./program; then echo "success"; fi`
- Build systems use exit codes to detect failures
- Security tools check if exploitation succeeded

**Checking exit status in shell:**
```bash
./program
echo $?    # prints the exit status of last command
```

You can also use `exit(n)` from anywhere in your program to terminate immediately with status `n`.

## Code

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Testing return values...\n");
    
    int success = 1;
    
    if (success) {
        printf("[+] Operation succeeded\n");
        return EXIT_SUCCESS;
    } else {
        printf("[-] Operation failed\n");
        return EXIT_FAILURE;
    }
}
```

## Output

```
Testing return values...
[+] Operation succeeded
```

Check the exit status:
```bash
./003-return-values-from-main
echo $?
# Output: 0
```

## Key Takeaways

- `return 0` = success, non-zero = failure
- Use `EXIT_SUCCESS` and `EXIT_FAILURE` from `<stdlib.h>` for portability
- Exit status is checked by shells: `$?` in bash
- `exit(n)` can terminate from anywhere with status `n`
- Security tools rely on exit codes to indicate success/failure
- Exit codes range from 0-255 on Unix systems

## Challenge

Write a program that returns different exit codes based on command-line arguments. Return 0 if run with no arguments, 1 if run with one argument, 2 if run with two, etc. Test with `echo $?`.

## Related

- [[002-main-function-anatomy]] — What main() looks like
- [[200-command-line-arguments]] — Processing argc/argv
- [[003-compilation-process]] — Understanding build process
