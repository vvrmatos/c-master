#include <stdio.h>
#include <string.h>

int main(void) {
    char simulated[] = "Hello, World!\nLine 2\nLine 3";
    char line[50];
    char *pos = simulated;

    while (sscanf(pos, "%49[^\n]", line) == 1) {
        line[strcspn(line, "\n")] = '\0';
        printf("[%s] len=%zu\n", line, strlen(line));
        pos = strchr(pos, '\n');
        if (pos) pos++;
        else break;
    }

    char buffer[10];
    char longtext[] = "This is a longer string";
    strncpy(buffer, longtext, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Truncated: [%s]\n", buffer);

    return 0;
}

