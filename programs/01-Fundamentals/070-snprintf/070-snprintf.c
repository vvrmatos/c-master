#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char small[10];
    int needed;

    needed = snprintf(small, sizeof(small), "Hello!");
    printf("[%s] needed %d\n", small, needed);

    needed = snprintf(small, sizeof(small), "This is too long");
    printf("[%s] needed %d, truncated=%s\n", small, needed,
           needed >= (int)sizeof(small) ? "yes" : "no");

    needed = snprintf(NULL, 0, "Value: %d", 12345);
    char *buf = malloc(needed + 1);
    if (buf) {
        snprintf(buf, needed + 1, "Value: %d", 12345);
        printf("%s\n", buf);
        free(buf);
    }

    char path[50];
    needed = snprintf(path, sizeof(path), "%s/%s", "/home/user", "file.txt");
    printf("%s\n", path);

    return 0;
}

