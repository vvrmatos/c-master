// Truthiness in C: 0 is false, non-zero is true

#include <stdio.h>

int main(void) {
    // Integer truth values
    printf("Integer truthiness:\n");
    printf("if (0)  -> %s\n", 0 ? "true" : "false");
    printf("if (1)  -> %s\n", 1 ? "true" : "false");
    printf("if (-1) -> %s\n", -1 ? "true" : "false");
    printf("if (42) -> %s\n", 42 ? "true" : "false");
    
    // Pointers
    printf("\nPointer truthiness:\n");
    int x = 10;
    int *ptr = &x;
    int *null_ptr = NULL;
    printf("if (ptr)      -> %s\n", ptr ? "true" : "false");
    printf("if (null_ptr) -> %s\n", null_ptr ? "true" : "false");
    
    // Characters
    printf("\nCharacter truthiness:\n");
    printf("if ('A') -> %s\n", 'A' ? "true" : "false");
    printf("if ('\\0') -> %s\n", '\0' ? "true" : "false");
    
    // Floating point
    printf("\nFloat truthiness:\n");
    printf("if (0.0)   -> %s\n", 0.0 ? "true" : "false");
    printf("if (0.001) -> %s\n", 0.001 ? "true" : "false");
    
    // Common idiom: loop until zero
    int count = 3;
    printf("\nCountdown: ");
    while (count) {
        printf("%d ", count);
        count--;
    }
    printf("\n");
    
    return 0;
}
