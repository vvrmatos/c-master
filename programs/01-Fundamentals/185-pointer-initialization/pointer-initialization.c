/*
 * Pointer Initialization - Properly initializing pointers
 */

#include <stdio.h>
#include <stdlib.h>

int global_var = 100;

int main(void) {
    printf("Pointer Initialization Methods:\n\n");
    
    // 1. Initialize with address of existing variable
    int local_var = 42;
    int *ptr1 = &local_var;
    printf("1. Address of variable:\n");
    printf("   int *ptr1 = &local_var;\n");
    printf("   *ptr1 = %d\n\n", *ptr1);
    
    // 2. Initialize to NULL (safe but unusable until assigned)
    int *ptr2 = NULL;
    printf("2. Initialize to NULL:\n");
    printf("   int *ptr2 = NULL;\n");
    printf("   ptr2 = %p\n\n", (void*)ptr2);
    
    // 3. Initialize with dynamic memory
    int *ptr3 = malloc(sizeof(int));
    if (ptr3 != NULL) {
        *ptr3 = 99;
        printf("3. Dynamic allocation:\n");
        printf("   int *ptr3 = malloc(sizeof(int));\n");
        printf("   *ptr3 = %d\n\n", *ptr3);
        free(ptr3);
    }
    
    // 4. Initialize with global variable address
    int *ptr4 = &global_var;
    printf("4. Global variable address:\n");
    printf("   int *ptr4 = &global_var;\n");
    printf("   *ptr4 = %d\n\n", *ptr4);
    
    // 5. Initialize array pointer
    int arr[] = {10, 20, 30};
    int *ptr5 = arr;  // Array decays to pointer
    printf("5. Array pointer:\n");
    printf("   int *ptr5 = arr;\n");
    printf("   *ptr5 = %d, *(ptr5+1) = %d\n", *ptr5, *(ptr5+1));
    
    return 0;
}
