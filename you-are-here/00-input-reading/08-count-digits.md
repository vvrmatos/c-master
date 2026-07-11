---
tags: [c, input]
---

# getchar until EOF — count digits

Char classifiers over a stream: count digits, strip non-printables, hex-dump filters. Same loop as BusyBox's `getc` reader, but you act on each byte.

## Replicate

```c
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c, digits = 0, other = 0;

    while ((c = getchar()) != EOF) {
        if (isdigit((unsigned char)c))
            digits++;
        else if (c != '\n' && c != '\r')
            other++;
    }

    printf("digits=%d other=%d\n", digits, other);
    return 0;
}
```

Cast to `unsigned char` before `isdigit` (required when `char` may be signed).

## In the wild — BusyBox builds lines with getc

```c
/* busybox libbb/get_line_from_file.c — GPLv2 */
while ((ch = getc(file)) != EOF) {
    linebuf[idx++] = (char) ch;
    if (ch == '\0')
        break;
    if (end && ch == '\n')
        break;
}
```

Your version classifies; theirs accumulates. Same skeleton: `while ((c = getc(...)) != EOF)`.

Ref: https://github.com/mirror/busybox/blob/master/libbb/get_line_from_file.c

## Real application ideas

- Count printable vs non-printable in a banner grab dump
- Strip ANSI color codes (detect ESC sequences byte-wise)
- Hex filter: print only `[0-9a-fA-F]`

## Try

```bash
printf 'ssh 22\nhttp 80\n' | ./a.out
# digits=4 other=10   (approx; spaces/letters count as other)
```
