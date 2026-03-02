/*
 * 135-array-size-sizeof
 * Calculating Array Size with sizeof
 */

#include <stdio.h>

int main(void) {
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double prices[5] = {9.99, 19.99, 29.99, 39.99, 49.99};
    char letters[26];
    
    /* Total bytes */
    printf("Total bytes:\n");
    printf("numbers: %zu bytes\n", sizeof(numbers));
    printf("prices: %zu bytes\n", sizeof(prices));
    printf("letters: %zu bytes\n", sizeof(letters));
    
    /* Element size */
    printf("\nElement sizes:\n");
    printf("sizeof(int): %zu bytes\n", sizeof(numbers[0]));
    printf("sizeof(double): %zu bytes\n", sizeof(prices[0]));
    printf("sizeof(char): %zu bytes\n", sizeof(letters[0]));
    
    /* Number of elements */
    printf("\nNumber of elements:\n");
    printf("numbers: %zu elements\n", sizeof(numbers) / sizeof(numbers[0]));
    printf("prices: %zu elements\n", sizeof(prices) / sizeof(prices[0]));
    printf("letters: %zu elements\n", sizeof(letters) / sizeof(letters[0]));
    
    /* Common idiom for safe looping */
    printf("\nLooping with sizeof:\n");
    size_t n = sizeof(numbers) / sizeof(numbers[0]);
    for (size_t i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
