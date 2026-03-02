/*
 * Introduction to free
 * Releasing dynamically allocated memory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Basic free usage
    int *num = malloc(sizeof(int));
    *num = 42;
    printf("Value: %d\n", *num);
    free(num);
    num = NULL;  // Good practice: nullify after free
    
    // Freeing an array
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    
    // Freeing a string
    char *str = malloc(20);
    strcpy(str, "Hello, World!");
    printf("String: %s\n", str);
    free(str);
    str = NULL;
    
    // free(NULL) is safe - does nothing
    int *null_ptr = NULL;
    free(null_ptr);  // Safe, no crash
    printf("free(NULL) is safe\n");
    
    // Demonstrating proper cleanup pattern
    int *data = malloc(100 * sizeof(int));
    if (data == NULL) {
        printf("Allocation failed\n");
        return 1;
    }
    // ... use data ...
    free(data);
    data = NULL;
    
    printf("All memory freed successfully!\n");
    
    return 0;
}
