---
tags: [c, cybersec, hacking, memory]
---

# format string — printf trusts the format

`printf(user)` treats user bytes as a **format string**. `%x` / `%n` style tokens read or write in ways the programmer never intended. Always `printf("%s", user)`.

## Broken (study)

```c
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2)
        return 1;
    printf(argv[1]);  /* BAD */
    printf("\n");
    return 0;
}
```

## Replicate (fixed)

```c
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2)
        return 1;
    printf("%s\n", argv[1]);
    return 0;
}
```

## Try

```bash
cc -Wall -Wextra -o fmt 08-format-string.c
./fmt hello
./fmt '%x %x %x'
```

Broken build: `%x` dumps stack-ish values. Fixed: prints the characters `%x %x %x` literally.

Compiler often warns: `-Wformat -Wformat-security`. Listen to it.

## In the wild — logging APIs

Same bug appears as `syslog(priority, user)` or custom log wrappers that pass the message as the format. Pattern: **format string is code; user data is data**. Keep them apart.

Ref: `man 3 printf` (format conversion specifiers).
