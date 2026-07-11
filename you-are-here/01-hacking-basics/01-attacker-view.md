---
tags: [c, cybersec, hacking]
---

# attacker view — what a system is

To an attacker, a host is not "an app". It is **interfaces that accept input**, run as some **identity**, and talk on a **network**.

## Mental model

```text
                    +------------------+
  network bytes --> | listening socket | --> process (uid/gid)
                    | file / pipe / UI | --> memory, disk, child procs
                    +------------------+
                              |
                              v
                         trust boundary
                    (inside vs outside)
```

Breaks happen when **untrusted input** crosses a boundary and the program treats it as trusted (command, path, size, format).

## Replicate — print your process identity

```c
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("pid=%d uid=%d euid=%d gid=%d\n",
           getpid(), getuid(), geteuid(), getgid());
    return 0;
}
```

Run it as yourself, then (lab only) under another user if you have one. Privilege is "who the kernel thinks you are".

## Try

```bash
cc -Wall -Wextra -o whoami-lite 01-attacker-view.c
./whoami-lite
id
```

Same idea as `id`: map identity before you care about exploits. Exploits often aim to **change** that identity (user → root) or **reuse** a privileged process's trust.

## In the wild — sudoers is a trust map

`/etc/sudoers` is literally "who may run what as whom". Attackers read it after foothold. Defenders harden it.

Ref: `man sudoers` on your machine.
