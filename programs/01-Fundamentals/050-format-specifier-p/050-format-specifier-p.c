#include <stdio.h>

int main(void) {
    int x = 42;
    int *ptr = &x;
    int arr[3] = {10, 20, 30};

    printf("%p\n", (void *)&x);
    printf("%p\n", (void *)ptr);
    printf("%p\n", (void *)&arr[0]);
    printf("%p\n", (void *)&arr[1]);
    printf("%p\n", (void *)NULL);

    return 0;
}
