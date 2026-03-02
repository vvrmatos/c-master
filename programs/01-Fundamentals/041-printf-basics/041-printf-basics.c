#include <stdio.h>

int main(void) {
    int count = 42;
    float price = 19.99f;
    char grade = 'A';

    printf("Hello, World!\n");
    printf("%d\n", count);
    printf("%f\n", price);
    printf("%c\n", grade);
    printf("%d items at $%.2f each\n", count, price);
    printf("Line1\nLine2\tTabbed\n");
    printf("Backslash: \\ Quote: \" Percent: %%\n");

    return 0;
}
