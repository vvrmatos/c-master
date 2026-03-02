/*
 * 133-array-access
 * Array Indexing with []
 */

#include <stdio.h>

int main(void) {
    int scores[5] = {85, 90, 78, 92, 88};
    
    /* Reading elements */
    printf("First element (index 0): %d\n", scores[0]);
    printf("Third element (index 2): %d\n", scores[2]);
    printf("Last element (index 4): %d\n", scores[4]);
    
    /* Writing elements */
    scores[1] = 95;  /* Modify second element */
    printf("Modified second element: %d\n", scores[1]);
    
    /* Using expressions as index */
    int i = 3;
    printf("Element at index %d: %d\n", i, scores[i]);
    printf("Element at index i+1: %d\n", scores[i + 1]);
    
    /* Computing with elements */
    int sum = scores[0] + scores[1] + scores[2] + scores[3] + scores[4];
    printf("Sum of all scores: %d\n", sum);
    
    return 0;
}
