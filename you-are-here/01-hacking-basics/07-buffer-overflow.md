---
tags: [c, cybersec, hacking, memory]
---

# buffer overflow — too much data, fixed space

A buffer holds N bytes. If the program writes more than N without checking, adjacent memory is corrupted. On the stack that can smash a saved return address. Modern OS defenses (ASLR, NX, stack canaries) make reliable exploitation harder. The **bug class** is still everywhere in C.

This note: make it **crash** on purpose in a toy. No shellcode, no remote exploit kit. Understand the failure mode, then fix it.

## Broken (study)

```c
#include <stdio.h>
#include <string.h>

void vulnerable(void) {
    char buf[16];

    printf("data: ");
    fflush(stdout);
    gets(buf);  /* DEPRECATED and unbounded — lab demo only */
    printf("got: %s\n", buf);
}

int main(void) {
    vulnerable();
    return 0;
}
```

`gets` cannot know the buffer size. Long input → overflow → often SIGSEGV.

## Replicate (fixed)

```c
#include <stdio.h>
#include <string.h>

void safe_read(void) {
    char buf[16];

    printf("data: ");
    fflush(stdout);
    if (fgets(buf, sizeof buf, stdin) == NULL)
        return;
    buf[strcspn(buf, "\n")] = '\0';
    printf("got: %s\n", buf);
}

int main(void) {
    safe_read();
    return 0;
}
```

## Try

```bash
cc -Wall -Wextra -o boom 07-overflow-broken.c   # expect gets warning
printf 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n' | ./boom

cc -Wall -Wextra -o ok 07-overflow-fixed.c
printf 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n' | ./ok
```

Broken: crash or garbage. Fixed: truncates, survives.

## Attacker vs defender (one line each)

- Attacker: control bytes past the buffer → influence control flow or data.
- Defender: bounded copies (`fgets`, `memcpy` with length), compiler flags (`-fstack-protector`), never `gets`.

## In the wild — why `gets` was removed

C11 removed `gets` from the standard library for this reason. Teaching copies still show it so you recognize it in old code and CTFs.

Ref: man page `gets(3)` on your system (marked obsolete / removed).
