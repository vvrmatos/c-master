/*
 * Pointer-Array Relationship
 * Arrays decay to pointers in most contexts
 */

#include <stdio.h>

void print_array(int *arr, int size) {
    printf("In function: arr = %p\n", (void *)arr);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    
    // Array name decays to pointer
    printf("arr = %p\n", (void *)arr);
    printf("&arr[0] = %p\n", (void *)&arr[0]);
    
    // These are equivalent
    printf("*arr = %d\n", *arr);
    printf("arr[0] = %d\n", arr[0]);
    
    // Array vs pointer size
    printf("sizeof(arr) = %lu (full array)\n", sizeof(arr));
    
    int *ptr = arr;
    printf("sizeof(ptr) = %lu (just pointer)\n", sizeof(ptr));
    
    // Passing to function - decays to pointer
    print_array(arr, 5);
    
    return 0;
}
