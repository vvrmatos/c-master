---
tags: [c, cybersec, hacking]
---

# trust boundaries — input is hostile

Every byte from the network, a file you did not write, argv, env, or a user is **untrusted** until proven otherwise. Bugs are usually "we trusted it anyway".

## Checklist (use on every toy)

```text
where does data enter?
what identity runs the code that handles it?
what can go wrong if length / charset / meaning is wrong?
did we copy it into a fixed buffer?
did we pass it to a shell, SQL, path, or format string?
```

## Replicate — never trust argv length blindly

Broken pattern (feel why):

```c
char buf[8];
strcpy(buf, argv[1]);  /* argv[1] can be huge */
```

Fixed pattern:

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char buf[8];

    if (argc < 2) {
        fprintf(stderr, "usage: %s <word>\n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) >= sizeof buf) {
        fprintf(stderr, "too long (max %zu)\n", sizeof buf - 1);
        return 1;
    }
    memcpy(buf, argv[1], strlen(argv[1]) + 1);
    printf("ok: %s\n", buf);
    return 0;
}
```

## Try

```bash
cc -Wall -Wextra -o trust 05-trust-boundary.c
./trust hi
./trust this-is-too-long
```

## In the wild — OpenSSH privilege separation

sshd splits: an unprivileged child talks to the network; a privileged monitor does sensitive work. That is an engineered trust boundary, not a vibe.

Ref: https://www.openssh.com/ (privilege separation design notes / source under `sshd.c` monitor pattern)
