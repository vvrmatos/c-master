// Integer division truncation

#include <stdio.h>

int main(void) {
    // Truncation toward zero
    printf("7 / 3 = %d\n", 7 / 3);
    printf("-7 / 3 = %d\n", -7 / 3);
    printf("7 / -3 = %d\n", 7 / -3);
    printf("-7 / -3 = %d\n", -7 / -3);
    
    // The fractional part is discarded
    printf("\n99 / 100 = %d\n", 99 / 100);
    printf("1 / 2 = %d\n", 1 / 2);
    
    // Relationship: (a/b)*b + a%b == a
    int a = 17, b = 5;
    printf("\n%d = (%d/%d)*%d + %d%%%d = %d*%d + %d = %d\n",
           a, a, b, b, a, b, a/b, b, a%b, (a/b)*b + a%b);
    
    return 0;
}
