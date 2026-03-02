#include <stdio.h>
#include <string.h>

int arrays_equal(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {1, 2, 3, 4, 9};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("arr1 == arr2 compares addresses, not content!\n");
    printf("arr1 == arr2: %s\n\n", arr1 == arr2 ? "true" : "false");
    
    printf("Correct: Compare element by element\n");
    printf("arrays_equal(arr1, arr2): %s\n", 
           arrays_equal(arr1, arr2, size) ? "true" : "false");
    printf("arrays_equal(arr1, arr3): %s\n", 
           arrays_equal(arr1, arr3, size) ? "true" : "false");
    
    printf("\nUsing memcmp():\n");
    printf("memcmp(arr1, arr2, size): %d (0 = equal)\n", 
           memcmp(arr1, arr2, sizeof(arr1)));
    printf("memcmp(arr1, arr3, size): %d (non-zero = different)\n", 
           memcmp(arr1, arr3, sizeof(arr1)));
    
    return 0;
}
