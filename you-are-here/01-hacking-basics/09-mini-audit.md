---
tags: [c, cybersec, hacking]
---

# mini audit — walk a tiny program like a hunter

Put the pack together. You get a short C program. You list entry points, trust mistakes, and a fix. Same habit as a code review or CTF binary glance.

## Target (intentionally weak)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char cmd[256];
    char name[32];

    if (argc < 2) {
        fprintf(stderr, "usage: %s <name>\n", argv[0]);
        return 1;
    }
    strcpy(name, argv[1]);
    snprintf(cmd, sizeof cmd, "echo hello %s", name);
    system(cmd);
    return 0;
}
```

## Replicate — your audit notes

Fill this (example answers below, write your own first):

```text
entries: argv[1]
identity: whatever user runs the binary
bugs:
  1) ...
  2) ...
impact: ...
fixes: ...
test: ...
```

### Example audit (check after you try)

```text
entries: argv[1]
identity: caller uid
bugs:
  1) strcpy into name[32] — overflow if argv[1] longer
  2) system(shell) with unsanitized name — command injection
impact: crash and/or arbitrary commands as the process user
fixes: reject long input; do not call system; printf("%s\n", name) or execve echo with args
test: ./toy $(python3 -c 'print("A"*80)')
      ./toy 'x; id'
```

## Try

1. Save as `09-weak-echo.c`, compile, poke with long and metachar inputs **only on your machine**.
2. Rewrite a hardened `09-weak-echo-fixed.c`.
3. Optional: point `03`/`04` at a local `nc` listener and write a 5-line recon note (port, banner, guess).

## Next packs (when you want them)

- `02-sockets-recon/` deeper enum + HTTP probe
- `03-memory-corruption/` stack frames, canaries, deliberate crash analysis with a debugger
- web/app injection track if you want HTTP next instead of more C

Say which direction and we build the next flat pack the same way.
