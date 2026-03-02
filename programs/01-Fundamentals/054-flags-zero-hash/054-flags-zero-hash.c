#include <stdio.h>

int main(void) {
    printf("[%5d]\n", 42);
    printf("[%05d]\n", 42);
    printf("[%08d]\n", 42);
    printf("[%08x]\n", 255);
    printf("[%#x]\n", 255);
    printf("[%#X]\n", 255);
    printf("[%#o]\n", 64);
    printf("%02d:%02d:%02d\n", 9, 5, 3);

    return 0;
}

