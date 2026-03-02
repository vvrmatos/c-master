/*
 * 131-array-declaration
 * Array Declaration in C
 */

#include <stdio.h>

int main(void) {
    int numbers[5];          /* Array of 5 integers */
    double prices[10];       /* Array of 10 doubles */
    char letters[26];        /* Array of 26 chars */
    
    /* Arrays contain garbage until initialized */
    printf("Array 'numbers' declared with %zu elements\n", 
           sizeof(numbers)/sizeof(numbers[0]));
    printf("Array 'prices' declared with %zu elements\n",
           sizeof(prices)/sizeof(prices[0]));
    printf("Array 'letters' declared with %zu elements\n",
           sizeof(letters)/sizeof(letters[0]));
    
    /* Assign values to first element */
    numbers[0] = 42;
    prices[0] = 9.99;
    letters[0] = 'A';
    
    printf("\nFirst elements: %d, %.2f, %c\n", 
           numbers[0], prices[0], letters[0]);
    
    return 0;
}
