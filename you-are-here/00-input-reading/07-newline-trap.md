---
tags: [c, input]
---

# leftover newline trap

After `scanf("%d", ...)`, the Enter key's `'\n'` is still in the buffer. A following `%c` often reads that newline instead of the user's answer.

## Broken (feel it once)

```c
scanf("%d", &choice);
scanf("%c", &confirm);   /* often gets '\n' */
```

## Replicate (fixed)

```c
#include <stdio.h>

int main(void) {
    int choice;
    char confirm;

    printf("1) connect  2) quit\n");
    printf("choice: ");
    fflush(stdout);
    if (scanf("%d", &choice) != 1)
        return 1;

    printf("confirm (y/n): ");
    fflush(stdout);
    if (scanf(" %c", &confirm) != 1)  /* leading space skips whitespace */
        return 1;

    printf("choice=%d confirm=%c\n", choice, confirm);
    return 0;
}
```

## In the wild — tools use line then parse

Nmap never does interactive `scanf` + `%c`. It `fgets` a whole line, then `sscanf`:

```c
/* nmap services.cc — NPSL */
while (fgets(line, sizeof(line), fp)) {
    lineno++;
    /* skip blanks / # ... */
    res = sscanf(line, "%127s %hu/%15s %31s",
                 servicename, &portno, proto, ratio_str);
    if (res < 3)
        continue;
}
```

Ref: https://github.com/nmap/nmap/blob/master/services.cc

Redis config: `fgets` only, no leftover cross-prompt state:

```c
/* redis src/config.c — RSALv2 / BSDv3 */
while (fgets(buf, CONFIG_READ_LEN + 1, fp) != NULL)
    config = sdscat(config, buf);
```

Ref: https://github.com/redis/redis/blob/unstable/src/config.c

## Try

Run the broken version, type `1` Enter. Confirm never waits. Then run the fixed one.
