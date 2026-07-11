---
tags: [c, cybersec, hacking, injection]
---

# command injection — data becomes a command

If user input is concatenated into a string passed to `system` / a shell, metacharacters can run **extra** commands. Classic class: injection.

Lab only: your toy binary. Goal: see the bug, then remove the shell.

## Broken (study)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char host[64];
    char cmd[128];

    printf("host: ");
    fflush(stdout);
    if (fgets(host, sizeof host, stdin) == NULL)
        return 1;
    host[strcspn(host, "\n")] = '\0';

    /* BAD: shell sees metacharacters in host */
    snprintf(cmd, sizeof cmd, "ping -c 1 %s", host);
    system(cmd);
    return 0;
}
```

Input like `127.0.0.1; echo PWN` is not "a hostname". The shell runs two commands.

## Replicate (fixed idea)

Do not call a shell. Validate strictly, or use APIs that take argv arrays (`execve` with fixed binary + separate args). Minimal fix for the toy: allow only safe chars.

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int safe_host(const char *s) {
    size_t i;
    if (*s == '\0')
        return 0;
    for (i = 0; s[i]; i++) {
        if (!(isalnum((unsigned char)s[i]) || s[i] == '.' || s[i] == '-'))
            return 0;
    }
    return 1;
}

int main(void) {
    char host[64];

    printf("host: ");
    fflush(stdout);
    if (fgets(host, sizeof host, stdin) == NULL)
        return 1;
    host[strcspn(host, "\n")] = '\0';

    if (!safe_host(host)) {
        fprintf(stderr, "rejected\n");
        return 1;
    }
    printf("would ping: %s  (no shell)\n", host);
    return 0;
}
```

## Try

Run the broken build in a throwaway dir. Try `127.0.0.1` then a metachar payload. Then run the fixed one. Same input, no shell.

## In the wild — shells amplify bugs

Black Hat Bash and every pentest notes the same rule: `system`, backticks, and `os.system` turn string bugs into RCE. Prefer `execve`-style or libraries that never invoke `/bin/sh`.
