// Increment operator (pre and post)

#include <stdio.h>

int main(void) {
    int a = 5;
    
    // Post-increment: use, then increment
    printf("a = %d\n", a);
    printf("a++ = %d\n", a++);
    printf("a = %d\n\n", a);
    
    // Pre-increment: increment, then use
    a = 5;
    printf("a = %d\n", a);
    printf("++a = %d\n", ++a);
    printf("a = %d\n\n", a);
    
    // In isolation, both just add 1
    int x = 10, y = 10;
    x++;
    ++y;
    printf("x++ then x = %d\n", x);
    printf("++y then y = %d\n", y);
    
    return 0;
}
