#include <stdio.h>

int main(void) {
    char buffer[100];

    sprintf(buffer, "Hello, World!");
    printf("%s\n", buffer);

    int age = 25;
    sprintf(buffer, "Age: %d", age);
    printf("%s\n", buffer);

    sprintf(buffer, "%04d-%02d-%02d", 2024, 3, 15);
    printf("%s\n", buffer);

    sprintf(buffer, "%02d:%02d:%02d", 9, 5, 3);
    printf("%s\n", buffer);

    char path[100];
    sprintf(path, "%s/%s", "/home/user", "file.txt");
    printf("%s\n", path);

    int len = sprintf(buffer, "Count: %d", 42);
    printf("%d chars\n", len);

    return 0;
}

