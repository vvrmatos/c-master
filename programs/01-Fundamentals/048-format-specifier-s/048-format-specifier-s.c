#include <stdio.h>

int main(void) {
    char greeting[] = "Hello, World!";
    char name[] = "Alice";

    printf("%s\n", greeting);
    printf("%s\n", name);
    printf("%s %s\n", "Hello", "there");
    printf("[%20s]\n", name);
    printf("[%-20s]\n", name);
    printf("%.5s\n", greeting);

    return 0;
}
