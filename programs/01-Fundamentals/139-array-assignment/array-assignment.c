#include <stdio.h>
#include <string.h>

int main(void) {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];
    
    // arr2 = arr1;  // ERROR: arrays cannot be assigned
    
    printf("Cannot do: arr2 = arr1 (compile error)\n\n");
    
    printf("Solution 1: Copy element by element\n");
    for (int i = 0; i < 5; i++) {
        arr2[i] = arr1[i];
    }
    for (int i = 0; i < 5; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }
    
    printf("\nSolution 2: Use memcpy()\n");
    int arr3[5];
    memcpy(arr3, arr1, sizeof(arr1));
    for (int i = 0; i < 5; i++) {
        printf("arr3[%d] = %d\n", i, arr3[i]);
    }
    
    return 0;
}
