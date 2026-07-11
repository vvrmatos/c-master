---
tags: [c, input]
---

# fgets — full line

Bounded line read. Keeps spaces. Puts `'\n'` in the buffer if the line fit. This is how configs, probe DBs, and "read until newline" tools usually start.

## Replicate

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char line[128];
    size_t len;

    printf("banner line: ");
    fflush(stdout);

    if (fgets(line, sizeof line, stdin) == NULL)
        return 1;

    len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';

    printf("got (%zu bytes): \"%s\"\n", strlen(line), line);
    return 0;
}
```

Never use `gets`. Cap is always `sizeof buf`.

## In the wild — Redis config from file or stdin

Redis loads `redis.conf` (or stdin) by slurping with `fgets` into a growing string:

```c
/* redis src/config.c — RSALv2 / BSDv3 */
while (fgets(buf, CONFIG_READ_LEN + 1, fp) != NULL)
    config = sdscat(config, buf);

/* also: redis-server -  (config from stdin) */
if (config_from_stdin) {
    fp = stdin;
    while (fgets(buf, CONFIG_READ_LEN + 1, fp) != NULL)
        config = sdscat(config, buf);
}
```

Ref: https://github.com/redis/redis/blob/unstable/src/config.c

## In the wild — Nmap service probes

Nmap fingerprints services by parsing `nmap-service-probes` line by line:

```c
/* nmap service_scan.cc — NPSL */
char line[2048];
fp = fopen(filename, "r");
while (fgets(line, sizeof(line), fp)) {
    lineno++;
    if (*line == '\n' || *line == '#')
        continue;
    /* Probe / ports / rarity / ... */
}
```

Ref: https://github.com/nmap/nmap/blob/master/service_scan.cc

## Try

```text
banner line: SSH-2.0-OpenSSH_9.6
got (20 bytes): "SSH-2.0-OpenSSH_9.6"
```
