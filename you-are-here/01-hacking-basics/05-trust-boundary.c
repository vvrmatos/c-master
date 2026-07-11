#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char buf[8];

    if (argc < 2) {
        fprintf(stderr, "usage: %s <word>\n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) >= sizeof buf) {
        fprintf(stderr, "too long (max %zu)\n", sizeof buf - 1);
        return 1;
    }
    memcpy(buf, argv[1], strlen(argv[1]) + 1);
    printf("ok: %s\n", buf);
    return 0;
}
