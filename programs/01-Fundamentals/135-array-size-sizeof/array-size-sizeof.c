#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    
    size_t total_bytes = sizeof(arr);
    size_t element_bytes = sizeof(arr[0]);
    size_t count = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: {10, 20, 30, 40, 50}\n\n");
    printf("sizeof(arr)    = %zu bytes (total array size)\n", total_bytes);
    printf("sizeof(arr[0]) = %zu bytes (one int)\n", element_bytes);
    printf("Element count  = %zu / %zu = %zu\n", 
           total_bytes, element_bytes, count);
    
    double doubles[] = {1.1, 2.2, 3.3};
    printf("\nDouble array: %zu elements\n", 
           sizeof(doubles) / sizeof(doubles[0]));
    
    return 0;
}
