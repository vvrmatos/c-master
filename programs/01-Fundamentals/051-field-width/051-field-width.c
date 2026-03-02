#include <stdio.h>

int main(void) {
    printf("[%d]\n", 42);
    printf("[%10d]\n", 42);
    printf("[%-10d]\n", 42);
    printf("[%10s]\n", "Hello");
    printf("[%-10s]\n", "Hello");
    printf("[%*d]\n", 15, 42);

    printf("%-10s %10d\n", "Alice", 25);
    printf("%-10s %10d\n", "Bob", 30);

    return 0;
}

