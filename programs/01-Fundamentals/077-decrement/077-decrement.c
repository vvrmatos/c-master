// Decrement operator (pre and post)

#include <stdio.h>

int main(void) {
    int a = 5;
    
    // Post-decrement: use, then decrement
    printf("a = %d\n", a);
    printf("a-- = %d\n", a--);
    printf("a = %d\n\n", a);
    
    // Pre-decrement: decrement, then use
    a = 5;
    printf("a = %d\n", a);
    printf("--a = %d\n", --a);
    printf("a = %d\n\n", a);
    
    // Countdown
    printf("Countdown: ");
    for (int i = 5; i > 0; i--) {
        printf("%d ", i);
    }
    printf("Liftoff!\n");
    
    return 0;
}
