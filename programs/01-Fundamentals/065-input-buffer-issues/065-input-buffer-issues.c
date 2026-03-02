#include <stdio.h>
#include <string.h>

int main(void) {
    char input[] = "42\nA\nHello World";
    int num;
    char ch;
    char line[50];

    sscanf(input, "%d", &num);
    printf("Number: %d\n", num);

    char *pos = strchr(input, '\n') + 1;
    sscanf(pos, " %c", &ch);
    printf("Char: %c\n", ch);

    pos = strchr(pos, '\n') + 1;
    sscanf(pos, "%49[^\n]", line);
    printf("Line: %s\n", line);

    return 0;
}

