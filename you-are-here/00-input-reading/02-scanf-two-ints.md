---
tags: [c, input]
---

# scanf — two ints

Reading a pair is the pattern behind `host_id port`, `width height`, `start end`. One call, two conversions, return must be `2`.

## Replicate

```c
#include <stdio.h>

int main(void) {
    int lo, hi;

    printf("port range (lo hi): ");
    fflush(stdout);

    if (scanf("%d %d", &lo, &hi) != 2) {
        fprintf(stderr, "need two ints\n");
        return 1;
    }

    if (lo < 1 || hi > 65535 || lo > hi) {
        fprintf(stderr, "bad range\n");
        return 1;
    }

    printf("scan %d..%d (%d ports)\n", lo, hi, hi - lo + 1);
    return 0;
}
```

Whitespace between values can be space or newline (`%d` skips it).

## In the wild — Nmap ratio `n/d`

After reading a services line, Nmap may parse a frequency ratio with a second `sscanf`:

```c
/* nmap services.cc — NPSL */
res = sscanf(ratio_str, "%d/%d", &ratio_n, &ratio_d);
if (res != 2)
    fatal("%s:%d contains invalid port ratio string: %s",
          filename, lineno, ratio_str);
```

Same idea: two ints, check `== 2`, reject garbage.

Ref: https://github.com/nmap/nmap/blob/master/services.cc

## Try

```text
port range (lo hi): 20 25
scan 20..25 (6 ports)
```
