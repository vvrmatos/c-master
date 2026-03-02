#include <stdio.h>

int main(void) {
    char data[] = "10 20 30 -1 40";
    int num, sum = 0, count = 0;
    char *pos = data;
    int offset;

    while (sscanf(pos, "%d%n", &num, &offset) == 1) {
        if (num == -1)
            break;
        sum += num;
        count++;
        pos += offset;
    }

    printf("Sum of %d numbers: %d\n", count, sum);

    char lines[] = "Line1\nLine2\nLine3\n\nLine4";
    char line[50];
    pos = lines;
    count = 0;
    while (sscanf(pos, "%49[^\n]%n", line, &offset) == 1) {
        printf("[%s]\n", line);
        count++;
        pos += offset;
        if (*pos == '\n') pos++;
        if (*pos == '\n' || *pos == '\0') break;
    }
    printf("Read %d lines\n", count);

    return 0;
}

