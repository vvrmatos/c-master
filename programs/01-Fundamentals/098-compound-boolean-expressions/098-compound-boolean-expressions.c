// Compound boolean expressions

#include <stdio.h>

int main(void) {
    int age = 25;
    int income = 50000;
    int credit_score = 700;
    int has_job = 1;
    
    // Multiple AND conditions
    if (age >= 18 && income >= 30000 && credit_score >= 650) {
        printf("Loan pre-qualified (basic)\n");
    }
    
    // AND and OR combined
    if ((age >= 21 && income >= 40000) || credit_score >= 750) {
        printf("Loan pre-qualified (premium)\n");
    }
    
    // Complex business logic
    int is_student = 0;
    int is_senior = 0;
    if ((is_student || is_senior) && age >= 16) {
        printf("Discount eligible\n");
    } else if (age >= 65) {
        printf("Senior discount\n");
    }
    
    // Precedence matters: && binds tighter than ||
    // These are different:
    printf("\nPrecedence demo:\n");
    int a = 0, b = 1, c = 1;
    printf("a || b && c = %d\n", a || b && c);    // a || (b && c) = 1
    printf("(a || b) && c = %d\n", (a || b) && c); // Same result here, but...
    
    a = 1; b = 0; c = 0;
    printf("a || b && c = %d\n", a || b && c);     // 1 || (0 && 0) = 1
    printf("(a || b) && c = %d\n", (a || b) && c); // (1 || 0) && 0 = 0
    
    return 0;
}
