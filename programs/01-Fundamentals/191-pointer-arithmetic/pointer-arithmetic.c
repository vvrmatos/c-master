/*
 * Pointer Arithmetic
 * Incrementing and decrementing pointers
 */

#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    
    printf("Initial: *ptr = %d\n", *ptr);
    
    ptr++;  // Move to next int
    printf("After ptr++: *ptr = %d\n", *ptr);
    
    ptr += 2;  // Move forward 2 ints
    printf("After ptr += 2: *ptr = %d\n", *ptr);
    
    ptr--;  // Move back one int
    printf("After ptr--: *ptr = %d\n", *ptr);
    
    // Pointer difference
    int *start = arr;
    int *end = &arr[4];
    printf("Elements between: %ld\n", end - start);
    
    return 0;
}
