#include <stdio.h>

int main(void) {
    int x = 15;
    int y = 8;
    
    if (x > 10) {
        if (y > 5) {
            printf("x > 10 AND y > 5\n");
        } else {
            printf("x > 10 AND y <= 5\n");
        }
    } else {
        if (y > 5) {
            printf("x <= 10 AND y > 5\n");
        } else {
            printf("x <= 10 AND y <= 5\n");
        }
    }
    
    return 0;
}
