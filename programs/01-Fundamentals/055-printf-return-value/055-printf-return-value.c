#include <stdio.h>

int main(void) {
    int count;

    count = printf("Hello\n");
    printf("Printed: %d\n", count);

    count = printf("Number: %d\n", 42);
    printf("Printed: %d\n", count);

    count = printf("");
    printf("Empty: %d\n", count);

    return 0;
}

