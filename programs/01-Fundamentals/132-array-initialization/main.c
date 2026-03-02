/*
 * 132-array-initialization
 * Array Initialization with Initializer Lists
 */

#include <stdio.h>

int main(void) {
    /* Full initialization */
    int numbers[5] = {10, 20, 30, 40, 50};
    
    /* Size inferred from initializer */
    int primes[] = {2, 3, 5, 7, 11, 13};
    
    /* Character array initialization */
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    
    /* Double array */
    double temps[] = {98.6, 99.1, 97.8, 100.2};
    
    printf("numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    
    printf("\nprimes (%zu elements): ", sizeof(primes)/sizeof(primes[0]));
    for (int i = 0; i < 6; i++) {
        printf("%d ", primes[i]);
    }
    
    printf("\nvowels: ");
    for (int i = 0; i < 5; i++) {
        printf("%c ", vowels[i]);
    }
    
    printf("\ntemps: ");
    for (int i = 0; i < 4; i++) {
        printf("%.1f ", temps[i]);
    }
    printf("\n");
    
    return 0;
}
