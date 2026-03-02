#include <stdio.h>

int main(void) {
    /* Multiple variables */
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("i=%d, j=%d\n", i, j);
    }
    
    printf("\n");
    
    /* Omitted initialization */
    int k = 0;
    for (; k < 3; k++) {
        printf("k=%d\n", k);
    }
    
    /* Omitted update */
    printf("\n");
    for (int m = 0; m < 3; ) {
        printf("m=%d\n", m);
        m++;
    }
    
    return 0;
}
