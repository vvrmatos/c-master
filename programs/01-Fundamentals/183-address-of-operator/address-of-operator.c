/*
 * Address-of Operator - Using the & operator
 */

#include <stdio.h>

int main(void) {
    int number = 42;
    char letter = 'A';
    float decimal = 3.14f;
    
    printf("The Address-of Operator (&)\n\n");
    
    printf("Variable values:\n");
    printf("  number = %d\n", number);
    printf("  letter = %c\n", letter);
    printf("  decimal = %.2f\n", decimal);
    
    printf("\nAddresses (using &):\n");
    printf("  &number = %p\n", (void*)&number);
    printf("  &letter = %p\n", (void*)&letter);
    printf("  &decimal = %p\n", (void*)&decimal);
    
    // Storing address in pointer
    int *ptr = &number;
    
    printf("\nStoring address in pointer:\n");
    printf("  int *ptr = &number;\n");
    printf("  ptr = %p (same as &number)\n", (void*)ptr);
    printf("  *ptr = %d (same as number)\n", *ptr);
    
    // Address of array elements
    int arr[3] = {10, 20, 30};
    printf("\nAddresses of array elements:\n");
    for (int i = 0; i < 3; i++) {
        printf("  &arr[%d] = %p (value: %d)\n", 
               i, (void*)&arr[i], arr[i]);
    }
    
    return 0;
}
