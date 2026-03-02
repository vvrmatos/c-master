#include <stdio.h>

int main(void) {
    int age = 17;
    
    if (age >= 18) {
        printf("You can vote\n");
    } else {
        printf("Too young to vote\n");
    }
    
    int number = -5;
    if (number >= 0) {
        printf("Positive or zero\n");
    } else {
        printf("Negative\n");
    }
    
    return 0;
}
