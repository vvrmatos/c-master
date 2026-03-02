// C99 bool type from stdbool.h

#include <stdio.h>
#include <stdbool.h>

bool is_even(int n) {
    return n % 2 == 0;
}

bool is_positive(int n) {
    return n > 0;
}

int main(void) {
    // bool type with true/false keywords
    bool flag = true;
    printf("flag = %d\n", flag);
    
    flag = false;
    printf("flag = %d\n", flag);
    
    // bool in conditions
    bool is_valid = true;
    if (is_valid) {
        printf("\nData is valid\n");
    }
    
    // Functions returning bool
    printf("\n5 is even: %s\n", is_even(5) ? "true" : "false");
    printf("6 is even: %s\n", is_even(6) ? "true" : "false");
    
    // bool stores 0 or 1
    bool b = 42;  // Any non-zero becomes 1
    printf("\nbool b = 42 -> %d\n", b);
    
    b = -1;  // Negative non-zero also becomes 1
    printf("bool b = -1 -> %d\n", b);
    
    // sizeof bool
    printf("\nsizeof(bool) = %zu\n", sizeof(bool));
    printf("sizeof(_Bool) = %zu\n", sizeof(_Bool));
    
    return 0;
}
