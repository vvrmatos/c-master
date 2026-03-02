#include <stdio.h>

int main(void) {
    int num = 5;
    int factorial = 1;
    
    do {
        factorial *= num;
        num--;
    } while (num > 0);
    
    printf("5! = %d\n", factorial);
    
    int x = 10;
    do {
        printf("x = %d\n", x);
    } while (x < 5);
    
    return 0;
}
