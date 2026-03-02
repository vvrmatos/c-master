// Multiplication operator

#include <stdio.h>

int main(void) {
    int a = 6, b = 7;
    int product = a * b;
    
    printf("%d * %d = %d\n", a, b, product);
    
    double price = 19.99;
    int quantity = 3;
    printf("Total: $%.2f\n", price * quantity);
    
    // Chained multiplication
    printf("2 * 3 * 4 = %d\n", 2 * 3 * 4);
    
    return 0;
}
