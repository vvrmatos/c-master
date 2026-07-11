---
tags: [c, input]
---

# getchar — one byte (and the Enter behind it)

`getchar` returns **one byte** as `int`, or `EOF`. The terminal is line-buffered: you type a char, press Enter, then the program sees bytes. First `getchar` is usually your char. Second is usually `'\n'`.

## Replicate

```c
#include <stdio.h>

int main(void) {
    int c;

    printf("char: ");
    fflush(stdout);

    c = getchar();
    if (c == EOF) {
        fprintf(stderr, "EOF\n");
        return 1;
    }

    if (c == '\n')
        printf("1st: '\\n' (%d)\n", c);
    else
        printf("1st: '%c' (%d)\n", c, c);

    /* Enter is still in the stdin buffer from the same line */
    c = getchar();
    if (c == EOF) {
        printf("2nd: EOF\n");
        return 0;
    }
    if (c == '\n')
        printf("2nd: '\\n' (%d)  <- that was Enter\n", c);
    else
        printf("2nd: '%c' (%d)\n", c, c);

    return 0;
}
```

Return type is `int` so `EOF` (-1) is not confused with a real byte.

## Try

```bash
cc -Wall -Wextra -o practice 00-getchar-echo.c
./practice
```

Type `A` then Enter:

```text
char: A
1st: 'A' (65)
2nd: '\n' (10)  <- that was Enter
```

Not a second run of the program. Same run, second `getchar`.

## In the wild — BusyBox line reader

BusyBox keeps calling `getc` until `'\n'` (or `'\0'`), i.e. it consumes the whole line on purpose:

```c
/* busybox libbb/get_line_from_file.c — GPLv2 */
while ((ch = getc(file)) != EOF) {
    if (!(idx & 0xff))
        linebuf = xrealloc(linebuf, idx + 0x100);
    linebuf[idx++] = (char) ch;
    if (ch == '\0')
        break;
    if (end && ch == '\n')
        break;
}
```

Ref: https://github.com/mirror/busybox/blob/master/libbb/get_line_from_file.c
