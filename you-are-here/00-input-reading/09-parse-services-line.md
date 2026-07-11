---
tags: [c, input]
---

# parse a services line (Nmap-shaped)

End-to-end: `fgets` + `sscanf` on lines that look like `nmap-services` / `/etc/services`. This is the skill behind loading port databases.

## Replicate

Read lines from stdin until EOF. Skip blanks and `#` comments. Parse `name port/proto`. Print `port  name (proto)`.

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char line[256];
    char name[128];
    char proto[16];
    unsigned port;
    char *p;
    int n;

    while (fgets(line, sizeof line, stdin) != NULL) {
        p = line;
        while (*p && isspace((unsigned char)*p))
            p++;
        if (*p == '\0' || *p == '#')
            continue;

        n = sscanf(p, "%127s %u/%15s", name, &port, proto);
        if (n != 3)
            continue;

        printf("%5u  %-16s (%s)\n", port, name, proto);
    }
    return 0;
}
```

## In the wild — Nmap

```c
/* nmap services.cc — NPSL */
while (fgets(line, sizeof(line), fp)) {
    /* skip whitespace / # comments */
    res = sscanf(line, "%127s %hu/%15s %31s",
                 servicename, &portno, proto, ratio_str);
    if (res < 3)
        continue;
    /* store mapping for -sV / --top-ports / etc. */
}
```

Ref: https://github.com/nmap/nmap/blob/master/services.cc

## Try against the real file

```bash
cc -Wall -Wextra -o services-lite practice.c
grep -E '^(ssh|http|https|domain)\s' /etc/services | ./services-lite
```

Or feed a mini DB:

```text
# lab services
ssh 22/tcp
http 80/tcp
https 443/tcp
```
