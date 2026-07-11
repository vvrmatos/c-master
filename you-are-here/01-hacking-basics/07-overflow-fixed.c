#include <stdio.h>
#include <string.h>

void safe_read(void) {
    char buf[16];

    printf("data: ");
    fflush(stdout);
    if (fgets(buf, sizeof buf, stdin) == NULL)
        return;
    buf[strcspn(buf, "\n")] = '\0';
    printf("got: %s\n", buf);
}

int main(void) {
    safe_read();
    return 0;
}
