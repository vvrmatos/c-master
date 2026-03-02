/*
 * Pointer Comparison
 * Comparing pointers with relational operators
 */

#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int *p1 = &arr[1];
    int *p2 = &arr[3];
    int *p3 = &arr[1];
    
    // Equality comparison
    printf("p1 == p3: %s\n", (p1 == p3) ? "true" : "false");
    printf("p1 == p2: %s\n", (p1 == p2) ? "true" : "false");
    
    // Relational comparison (within same array)
    printf("\np1 < p2: %s\n", (p1 < p2) ? "true" : "false");
    printf("p2 > p1: %s\n", (p2 > p1) ? "true" : "false");
    printf("p1 <= p3: %s\n", (p1 <= p3) ? "true" : "false");
    
    // NULL comparison
    int *null_ptr = NULL;
    printf("\nnull_ptr == NULL: %s\n", (null_ptr == NULL) ? "true" : "false");
    
    // Iterating with pointer comparison
    printf("\nArray traversal with pointer comparison:\n");
    int *end = arr + 5;
    for (int *p = arr; p < end; p++) {
        printf("%d ", *p);
    }
    printf("\n");
    
    return 0;
}
