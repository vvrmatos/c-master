/*
 * 136-array-iteration
 * Looping Through Arrays
 */

#include <stdio.h>

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    
    /* For loop - most common */
    printf("For loop (forward):\n");
    for (size_t i = 0; i < size; i++) {
        printf("numbers[%zu] = %d\n", i, numbers[i]);
    }
    
    /* Backward iteration */
    printf("\nFor loop (backward):\n");
    for (size_t i = size; i > 0; i--) {
        printf("numbers[%zu] = %d\n", i - 1, numbers[i - 1]);
    }
    
    /* While loop */
    printf("\nWhile loop:\n");
    size_t j = 0;
    while (j < size) {
        printf("numbers[%zu] = %d\n", j, numbers[j]);
        j++;
    }
    
    /* Sum using iteration */
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += numbers[i];
    }
    printf("\nSum of all elements: %d\n", sum);
    
    /* Find maximum */
    int max = numbers[0];
    for (size_t i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    printf("Maximum element: %d\n", max);
    
    return 0;
}
