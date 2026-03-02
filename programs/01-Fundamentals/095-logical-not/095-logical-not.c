// Logical NOT operator

#include <stdio.h>

int main(void) {
    int a = 1, b = 0;
    
    // Basic NOT
    printf("!%d = %d\n", a, !a);
    printf("!%d = %d\n", b, !b);
    
    // Double negation
    printf("!!%d = %d\n", a, !!a);
    printf("!!%d = %d\n", b, !!b);
    
    // Normalize to boolean (0 or 1)
    int x = 42;
    printf("\nx = %d, !!x = %d (normalized)\n", x, !!x);
    
    // Negating conditions
    int is_valid = 1;
    if (!is_valid) {
        printf("Invalid!\n");
    } else {
        printf("\nData is valid\n");
    }
    
    // Toggle boolean
    is_valid = !is_valid;
    printf("After toggle: %d\n", is_valid);
    
    // Common pattern: check for null/zero
    char *ptr = NULL;
    if (!ptr) {
        printf("\nPointer is NULL\n");
    }
    
    return 0;
}
