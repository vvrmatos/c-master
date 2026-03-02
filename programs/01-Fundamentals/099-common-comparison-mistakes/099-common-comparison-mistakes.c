// Common comparison mistakes: = vs ==

#include <stdio.h>

int main(void) {
    int x = 5;
    
    // MISTAKE: Assignment instead of comparison
    // This assigns 10 to x, then checks if 10 is true (it is!)
    if (x = 10) {  // WARNING: should be x == 10
        printf("Bug! x is now %d (assigned, not compared)\n", x);
    }
    
    // Correct comparison
    x = 5;
    if (x == 10) {
        printf("x equals 10\n");
    } else {
        printf("x is %d, not 10 (correct comparison)\n", x);
    }
    
    // Yoda conditions: put constant first
    // if (10 == x) { }  // Compiler error if you typo: 10 = x
    
    // MISTAKE: Comparing floating point directly
    double a = 0.1 + 0.2;
    if (a == 0.3) {  // Often fails!
        printf("Equal\n");
    } else {
        printf("\nBug! 0.1 + 0.2 != 0.3 (%.17f)\n", a);
    }
    
    // MISTAKE: Single & instead of &&
    int p = 1, q = 2;
    printf("\nBitwise vs Logical:\n");
    printf("1 & 2 = %d (bitwise AND)\n", p & q);
    printf("1 && 2 = %d (logical AND)\n", p && q);
    
    return 0;
}
