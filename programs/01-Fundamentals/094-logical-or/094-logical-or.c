// Logical OR operator

#include <stdio.h>

int main(void) {
    int a = 1, b = 0, c = 0;
    
    // Basic OR
    printf("%d || %d = %d\n", a, a, a || a);
    printf("%d || %d = %d\n", a, b, a || b);
    printf("%d || %d = %d\n", b, c, b || c);
    
    // Practical use: input validation
    char ch = 'Y';
    if (ch == 'Y' || ch == 'y') {
        printf("\nUser confirmed with '%c'\n", ch);
    }
    
    // Multiple alternatives
    int day = 6;  // Saturday
    if (day == 0 || day == 6) {
        printf("Day %d is a weekend\n", day);
    }
    
    // Checking multiple error conditions
    int error1 = 0, error2 = 1, error3 = 0;
    if (error1 || error2 || error3) {
        printf("\nAt least one error occurred\n");
    }
    
    // Non-boolean values
    printf("\n5 || 0 = %d\n", 5 || 0);
    printf("0 || 0 = %d\n", 0 || 0);
    
    return 0;
}
