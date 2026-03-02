// Logical AND operator

#include <stdio.h>

int main(void) {
    int a = 1, b = 1, c = 0;
    
    // Basic AND
    printf("%d && %d = %d\n", a, b, a && b);
    printf("%d && %d = %d\n", a, c, a && c);
    printf("%d && %d = %d\n", c, c, c && c);
    
    // Practical use: bounds checking
    int index = 5;
    int size = 10;
    if (index >= 0 && index < size) {
        printf("\nIndex %d is valid (0 to %d)\n", index, size - 1);
    }
    
    // Multiple conditions
    int age = 25;
    int has_license = 1;
    int is_sober = 1;
    if (age >= 18 && has_license && is_sober) {
        printf("Can drive: age=%d, license=%d, sober=%d\n", 
               age, has_license, is_sober);
    }
    
    // Non-boolean values
    int x = 5, y = 10;
    printf("\n5 && 10 = %d (both non-zero = true)\n", x && y);
    printf("5 && 0 = %d\n", x && 0);
    
    return 0;
}
