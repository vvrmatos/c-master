#include <stdio.h>

#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX_SIZE 100

int add(int a, int b);

#endif

int add(int a, int b) {
    return a + b;
}

int main(void) {
    printf("MAX_SIZE: %d\n", MAX_SIZE);
    printf("add(3, 4): %d\n", add(3, 4));
    return 0;
}
