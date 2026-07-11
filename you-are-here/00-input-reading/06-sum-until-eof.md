---
tags: [c, input]
---

# read until EOF — sum / filter

Pipes end. Files end. Loops must stop on EOF or parse failure. This is `cat`-adjacent: consume a stream until there is nothing left.

## Replicate

```c
#include <stdio.h>

int main(void) {
    int n, sum = 0, count = 0;

    while (scanf("%d", &n) == 1) {
        sum += n;
        count++;
    }

    printf("count=%d sum=%d\n", count, sum);
    return 0;
}
```

Ctrl-D (empty line context) ends stdin on macOS/Linux.

## In the wild — Redis slurps until EOF

Same loop shape with `fgets` instead of `scanf`:

```c
/* redis src/config.c — RSALv2 / BSDv3 */
while (fgets(buf, CONFIG_READ_LEN + 1, fp) != NULL)
    config = sdscat(config, buf);
```

When `fp` is stdin (`redis-server -`), that is "read config until EOF".

Ref: https://github.com/redis/redis/blob/unstable/src/config.c

## In the wild — BusyBox getc until EOF

```c
/* busybox libbb/get_line_from_file.c — GPLv2 */
while ((ch = getc(file)) != EOF) {
    linebuf[idx++] = (char) ch;
    if (end && ch == '\n')
        break;
}
```

EOF ends the chunk; newline can end it earlier.

Ref: https://github.com/mirror/busybox/blob/master/libbb/get_line_from_file.c

## Try

```bash
printf '10 20 12\n' | ./a.out
# count=3 sum=42
```
