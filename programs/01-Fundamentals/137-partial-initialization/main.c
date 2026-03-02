/*
 * 137-partial-initialization
 * Partial Initialization - Rest Are Zero
 */

#include <stdio.h>

int main(void) {
    /* Partial initialization: unspecified elements = 0 */
    int arr1[10] = {1, 2, 3};  /* {1, 2, 3, 0, 0, 0, 0, 0, 0, 0} */
    
    /* Just first element, rest are 0 */
    int arr2[5] = {42};        /* {42, 0, 0, 0, 0} */
    
    /* Initialize all to zero */
    int zeros[10] = {0};       /* All zeros */
    
    /* Floating point - same rule */
    double arr3[5] = {1.5, 2.5};  /* {1.5, 2.5, 0.0, 0.0, 0.0} */
    
    /* Print arrays */
    printf("arr1[10] = {1, 2, 3}:\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr1[i]);
    }
    
    printf("\n\narr2[5] = {42}:\n  ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    
    printf("\n\nzeros[10] = {0}:\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", zeros[i]);
    }
    
    printf("\n\narr3[5] = {1.5, 2.5}:\n  ");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", arr3[i]);
    }
    printf("\n");
    
    return 0;
}
