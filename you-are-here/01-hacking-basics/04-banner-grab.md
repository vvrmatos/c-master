---
tags: [c, cybersec, hacking, sockets]
---

# banner grab — what speaks on the open port?

After `connect` succeeds, read a few bytes (and maybe send a probe). The **banner** is a hint: product, version, sometimes junk. Hints lie; still useful for prioritization.

## Replicate

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char **argv) {
    int fd, port, n;
    struct sockaddr_in addr;
    char buf[512];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <ipv4> <port>\n", argv[0]);
        return 1;
    }
    port = atoi(argv[2]);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)port);
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
        close(fd);
        return 1;
    }
    if (connect(fd, (struct sockaddr *)&addr, sizeof addr) != 0) {
        perror("connect");
        close(fd);
        return 1;
    }

    /* many services speak first (ssh, smtp). http usually waits for a request. */
    n = (int)read(fd, buf, sizeof buf - 1);
    if (n > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    } else {
        printf("(no banner bytes)\n");
    }
    close(fd);
    return 0;
}
```

## Try

```bash
# terminal A — fake banner
printf 'toy-service 0.1\n' | nc -l 127.0.0.1 9999

# terminal B
cc -Wall -Wextra -o banner-grab 04-banner-grab.c
./banner-grab 127.0.0.1 9999
```

For HTTP on a lab box, you would `write` a request first (`GET / HTTP/1.0\r\n\r\n`), then `read`. Same socket skills.

## In the wild — Nmap service fingerprints

Nmap `-sV` sends probes from `nmap-service-probes` and matches reply patterns. Your grab is the manual, one-probe version of that idea.

Ref: https://nmap.org/book/vscan.html
