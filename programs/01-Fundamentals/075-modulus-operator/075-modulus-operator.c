// Modulus (remainder) operator

#include <stdio.h>

int main(void) {
    // Basic modulus
    printf("17 %% 5 = %d\n", 17 % 5);
    printf("20 %% 5 = %d\n", 20 % 5);
    printf("3 %% 5 = %d\n", 3 % 5);
    
    // Check even/odd
    int n = 7;
    printf("\n%d is %s\n", n, (n % 2 == 0) ? "even" : "odd");
    
    // Negative operands
    printf("\n-17 %% 5 = %d\n", -17 % 5);
    printf("17 %% -5 = %d\n", 17 % -5);
    
    // Wrap around (clock arithmetic)
    int hour = 23;
    printf("\n%d + 3 hours = %d o'clock\n", hour, (hour + 3) % 24);
    
    return 0;
}
