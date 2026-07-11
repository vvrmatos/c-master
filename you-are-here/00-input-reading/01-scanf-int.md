---
tags: [c, input]
---

# scanf — one int

`scanf` applies a **format** to stdin. Good for quick tools and learning the format language. Serious parsers usually do `fgets` then `sscanf` (same format codes, controlled buffer). Still: knowing `%d` and checking the return is mandatory either way.

## Replicate

```c
#include <stdio.h>

int main(void) {
    int n;

    printf("port: ");
    fflush(stdout);

    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "need an int\n");
        return 1;
    }

    if (n < 1 || n > 65535) {
        fprintf(stderr, "port out of range\n");
        return 1;
    }

    printf("ok port=%d\n", n);
    return 0;
}
```

Real-ish use: validate a TCP/UDP port before you open a socket. Pass `&n`. Return must be `1`.

## In the wild — same format language in Nmap

Nmap does not drive interactive `scanf` for this, but it **does** parse ints out of text with `sscanf` (same `%` language). From `nmap-services` loading:

```c
/* nmap services.cc — NPSL */
res = sscanf(line, "%127s %hu/%15s %31s",
             servicename, &portno, proto, ratio_str);
```

`%hu` is unsigned short (port). Width limits (`%127s`) are intentional.

Ref: https://github.com/nmap/nmap/blob/master/services.cc

## Try

```text
port: 443
ok port=443
```

```text
port: http
need an int
```
