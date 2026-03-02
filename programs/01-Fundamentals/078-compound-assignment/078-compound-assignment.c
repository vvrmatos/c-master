// Compound assignment operators

#include <stdio.h>

int main(void) {
    int x = 10;
    
    x += 5;   // x = x + 5
    printf("After x += 5: %d\n", x);
    
    x -= 3;   // x = x - 3
    printf("After x -= 3: %d\n", x);
    
    x *= 2;   // x = x * 2
    printf("After x *= 2: %d\n", x);
    
    x /= 4;   // x = x / 4
    printf("After x /= 4: %d\n", x);
    
    x %= 3;   // x = x % 3
    printf("After x %%= 3: %d\n", x);
    
    // Chaining (right-to-left)
    int a = 5, b = 10;
    a += b -= 3;  // b = 7, then a = 5 + 7 = 12
    printf("\na += b -= 3: a=%d, b=%d\n", a, b);
    
    return 0;
}
