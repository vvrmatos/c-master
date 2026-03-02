/*
 * Pass by Pointer
 * Modifying variables via pointers in functions
 */

#include <stdio.h>

// Pass by value - cannot modify original
void try_modify_value(int x) {
    x = 100;
    printf("Inside try_modify_value: x = %d\n", x);
}

// Pass by pointer - can modify original
void modify_via_pointer(int *x) {
    *x = 100;
    printf("Inside modify_via_pointer: *x = %d\n", *x);
}

// Swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Multiple outputs via pointers
void get_min_max(int *arr, int size, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main(void) {
    int num = 42;
    
    printf("Original: num = %d\n\n", num);
    
    try_modify_value(num);
    printf("After try_modify_value: num = %d\n\n", num);
    
    modify_via_pointer(&num);
    printf("After modify_via_pointer: num = %d\n\n", num);
    
    // Swap example
    int a = 5, b = 10;
    printf("Before swap: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("After swap: a=%d, b=%d\n\n", a, b);
    
    // Multiple outputs
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int min, max;
    get_min_max(arr, 8, &min, &max);
    printf("Min: %d, Max: %d\n", min, max);
    
    return 0;
}
