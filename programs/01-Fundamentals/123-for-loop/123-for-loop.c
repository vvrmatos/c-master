#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 5; i++) {
        printf("i = %d\n", i);
    }
    
    printf("\nEven numbers: ");
    for (int n = 2; n <= 10; n += 2) {
        printf("%d ", n);
    }
    printf("\n");
    
    printf("Countdown: ");
    for (int c = 5; c >= 1; c--) {
        printf("%d ", c);
    }
    printf("\n");
    
    return 0;
}
