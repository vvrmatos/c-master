/*
 * 134-array-bounds
 * No Bounds Checking - The Danger
 */

#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int other = 999;  /* Adjacent memory */
    
    printf("Array elements (valid indices 0-4):\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nOther variable: %d\n", other);
    
    /* Demonstrating the danger (reading out of bounds) */
    printf("\n--- Dangerous accesses (undefined behavior!) ---\n");
    printf("arr[5] (out of bounds) = %d\n", arr[5]);
    printf("arr[-1] (negative index) = %d\n", arr[-1]);
    
    /* The safe way: always check bounds */
    printf("\n--- Safe access pattern ---\n");
    int index = 3;
    int size = 5;
    
    if (index >= 0 && index < size) {
        printf("Safe access arr[%d] = %d\n", index, arr[index]);
    } else {
        printf("Index %d out of bounds!\n", index);
    }
    
    return 0;
}
