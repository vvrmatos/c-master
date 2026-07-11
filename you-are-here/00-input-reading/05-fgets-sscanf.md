---
tags: [c, input]
---

# fgets + sscanf

Production pattern: **read a line, then parse the line**. Leftover newlines stay inside `line`, not in stdin. Failed parse still leaves the raw text for logging.

## Replicate

```c
#include <stdio.h>

int main(void) {
    char line[128];
    char host[64];
    int port;

    printf("host port: ");
    fflush(stdout);

    if (fgets(line, sizeof line, stdin) == NULL)
        return 1;

    if (sscanf(line, "%63s %d", host, &port) != 2) {
        fprintf(stderr, "need: HOST PORT\n");
        return 1;
    }

    if (port < 1 || port > 65535) {
        fprintf(stderr, "bad port\n");
        return 1;
    }

    printf("connect %s:%d\n", host, port);
    return 0;
}
```

No socket yet. Same shape as a tiny connect helper's argv parsing.

## In the wild — Nmap `nmap-services`

This is the canonical cybersec example of the pattern:

```c
/* nmap services.cc — NPSL */
while (fgets(line, sizeof(line), fp)) {
    lineno++;
    /* skip blanks / comments ... */

    res = sscanf(line, "%127s %hu/%15s %31s",
                 servicename, &portno, proto, ratio_str);

    if (res == 3) {
        ratio = 0;
    } else if (res == 4) {
        /* parse ratio_str further */
    } else {
        continue;   /* malformed line: skip */
    }
    /* insert into port/service table */
}
```

Example line from the data file:

```text
http 80/tcp 0.484143
```

Ref: https://github.com/nmap/nmap/blob/master/services.cc

## Try

```text
host port: scanme.nmap.org 80
connect scanme.nmap.org:80
```
