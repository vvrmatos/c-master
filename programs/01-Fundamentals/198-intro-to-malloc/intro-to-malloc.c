/*
 * Introduction to malloc
 * Basic heap memory allocation
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Allocate memory for a single integer
    int *num = malloc(sizeof(int));
    if (num == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    *num = 42;
    printf("Single int: %d\n", *num);
    free(num);
    
    // Allocate memory for an array
    int size = 5;
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize and use the array
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    
    // Using calloc (zero-initialized)
    int *zeros = calloc(5, sizeof(int));
    if (zeros) {
        printf("Calloc array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", zeros[i]);  // All zeros
        }
        printf("\n");
        free(zeros);
    }
    
    return 0;
}
