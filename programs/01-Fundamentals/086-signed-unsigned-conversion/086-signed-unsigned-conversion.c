// Signed and unsigned conversion dangers

#include <stdio.h>

int main(void) {
    // Unsigned can't be negative - wraps around
    unsigned int u = 0;
    u = u - 1;  // Wraps to UINT_MAX
    printf("0u - 1 = %u\n", u);
    
    // Comparing signed and unsigned
    int s = -1;
    unsigned int us = 1;
    if (s < us) {
        printf("-1 < 1? Yes (expected)\n");
    } else {
        printf("-1 > 1? No! (s was converted to unsigned)\n");
    }
    
    // The actual comparison
    printf("As unsigned: %d -> %u\n", s, (unsigned int)s);
    printf("%u > %u is %s\n", (unsigned int)s, us, 
           (unsigned int)s > us ? "true" : "false");
    
    // Array index danger
    int arr[5] = {10, 20, 30, 40, 50};
    int index = -1;
    if (index < 5) {  // Always true if index is compared as int
        // arr[index] would be UB
        printf("Index %d passes bounds check against 5\n", index);
    }
    
    // Safe pattern: compare against 0 first
    if (index >= 0 && index < 5) {
        printf("Safe: index %d is valid\n", index);
    } else {
        printf("Safe: index %d is invalid\n", index);
    }
    
    return 0;
}
