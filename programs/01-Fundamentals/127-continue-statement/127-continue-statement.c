#include <stdio.h>

int main(void) {
    printf("Odd numbers 1-10: ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    printf("\nSkip multiples of 3:\n");
    for (int i = 1; i <= 15; i++) {
        if (i % 3 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
