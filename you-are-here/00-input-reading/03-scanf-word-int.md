---
tags: [c, input]
---

# scanf — word + int

`%s` reads one whitespace-delimited token. Cap the width (`%31s`) or you invite overflow. This is the shape of `service port`, `user uid`, `iface mtu`.

## Replicate

```c
#include <stdio.h>

int main(void) {
    char service[32];
    int port;

    printf("service: ");
    fflush(stdout);
    if (scanf("%31s", service) != 1)
        return 1;

    printf("port: ");
    fflush(stdout);
    if (scanf("%d", &port) != 1)
        return 1;

    printf("%s -> %d/tcp\n", service, port);
    return 0;
}
```

`%31s` into `char[32]` leaves room for `'\0'`. Full names with spaces need `fgets` instead.

## In the wild — `/etc/services` style lines

Nmap maps names to ports by parsing lines like:

```text
https 443/tcp 0.084
ssh   22/tcp  0.182
```

```c
/* nmap services.cc — NPSL */
res = sscanf(line, "%127s %hu/%15s %31s",
             servicename, &portno, proto, ratio_str);
```

That is "word + number + word" in one shot. Your two-prompt version is the interactive cousin.

Ref: https://github.com/nmap/nmap/blob/master/services.cc

On a Mac/Linux box you can peek at the same idea:

```bash
grep -E '^(https|ssh)\s' /etc/services | head
```

## Try

```text
service: ssh
port: 22
ssh -> 22/tcp
```
