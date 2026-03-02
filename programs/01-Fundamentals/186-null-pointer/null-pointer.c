/*
 * NULL Pointer - Understanding the NULL concept
 */

#include <stdio.h>
#include <stdlib.h>

int *find_value(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return &arr[i];  // Found: return address
        }
    }
    return NULL;  // Not found: return NULL
}

int main(void) {
    printf("NULL Pointer Concept:\n\n");
    
    // NULL represents "points to nothing"
    int *ptr = NULL;
    
    printf("int *ptr = NULL;\n");
    printf("ptr = %p\n", (void*)ptr);
    printf("ptr == NULL: %s\n", ptr == NULL ? "true" : "false");
    printf("ptr == 0: %s\n\n", ptr == 0 ? "true" : "false");
    
    // Safe NULL check before dereference
    printf("Safe dereferencing:\n");
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
    } else {
        printf("Cannot dereference: ptr is NULL\n");
    }
    
    // NULL as return value for "not found"
    printf("\nUsing NULL as 'not found' indicator:\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int *found = find_value(numbers, size, 30);
    if (found != NULL) {
        printf("Found 30 at address %p, value: %d\n", (void*)found, *found);
    }
    
    found = find_value(numbers, size, 99);
    if (found == NULL) {
        printf("99 not found in array\n");
    }
    
    return 0;
}
