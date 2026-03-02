#include <stdio.h>

int main(void) {
    int choice = 2;
    
    /* Switch: best for discrete values */
    switch (choice) {
        case 1: printf("Option 1\n"); break;
        case 2: printf("Option 2\n"); break;
        case 3: printf("Option 3\n"); break;
    }
    
    /* If-else: best for ranges and complex conditions */
    int score = 75;
    if (score >= 90) {
        printf("A\n");
    } else if (score >= 80) {
        printf("B\n");
    } else if (score >= 70) {
        printf("C\n");
    } else {
        printf("Below C\n");
    }
    
    return 0;
}
