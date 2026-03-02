#include <stdio.h>

int main(void) {
    printf("Count up: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Count down: ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Step by 2: ");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Step by 3: ");
    for (int i = 0; i <= 15; i += 3) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Powers of 2: ");
    for (int i = 1; i <= 256; i *= 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
