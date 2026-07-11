#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int safe_host(const char *s) {
    size_t i;
    if (*s == '\0')
        return 0;
    for (i = 0; s[i]; i++) {
        if (!(isalnum((unsigned char)s[i]) || s[i] == '.' || s[i] == '-'))
            return 0;
    }
    return 1;
}

int main(void) {
    char host[64];

    printf("host: ");
    fflush(stdout);
    if (fgets(host, sizeof host, stdin) == NULL)
        return 1;
    host[strcspn(host, "\n")] = '\0';

    if (!safe_host(host)) {
        fprintf(stderr, "rejected\n");
        return 1;
    }
    printf("would ping: %s  (no shell)\n", host);
    return 0;
}
