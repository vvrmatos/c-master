#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char cmd[256];
    char name[32];

    if (argc < 2) {
        fprintf(stderr, "usage: %s <name>\n", argv[0]);
        return 1;
    }
    strcpy(name, argv[1]);
    snprintf(cmd, sizeof cmd, "echo hello %s", name);
    system(cmd);
    return 0;
}
