/*
 * Return Pointer
 * Returning pointers from functions
 */

#include <stdio.h>
#include <stdlib.h>

// Return pointer to static variable (safe but shared)
int *get_static_value(void) {
    static int value = 42;
    return &value;
}

// Return pointer to array element (safe if array outlives pointer)
int *find_element(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return &arr[i];
        }
    }
    return NULL;
}

// Return pointer to heap memory (caller must free)
int *create_array(int size, int initial) {
    int *arr = malloc(size * sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < size; i++) {
            arr[i] = initial;
        }
    }
    return arr;
}

// DANGEROUS: returning pointer to local variable
// int *bad_function(void) {
//     int local = 10;
//     return &local;  // UNDEFINED BEHAVIOR!
// }

int main(void) {
    // Static variable pointer
    int *p1 = get_static_value();
    printf("Static value: %d\n", *p1);
    
    // Find element
    int arr[] = {10, 20, 30, 40, 50};
    int *found = find_element(arr, 5, 30);
    if (found) {
        printf("Found 30 at address %p, value = %d\n", (void *)found, *found);
    }
    
    // Heap allocation
    int *heap_arr = create_array(5, 7);
    if (heap_arr) {
        printf("Heap array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", heap_arr[i]);
        }
        printf("\n");
        free(heap_arr);
    }
    
    return 0;
}
