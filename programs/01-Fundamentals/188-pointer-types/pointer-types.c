/*
 * Pointer Types - Typed pointers in C
 */

#include <stdio.h>

int main(void) {
    printf("Typed Pointers in C:\n\n");
    
    // Different pointer types
    int i = 42;
    char c = 'A';
    float f = 3.14f;
    double d = 2.71828;
    
    int *ip = &i;
    char *cp = &c;
    float *fp = &f;
    double *dp = &d;
    
    printf("Pointer types and their targets:\n");
    printf("  int *ip    -> int:    %d\n", *ip);
    printf("  char *cp   -> char:   %c\n", *cp);
    printf("  float *fp  -> float:  %.2f\n", *fp);
    printf("  double *dp -> double: %.5f\n\n", *dp);
    
    // Why type matters: pointer arithmetic
    printf("Why pointer types matter (pointer arithmetic):\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    
    printf("  int arr[] = {10, 20, 30, 40, 50};\n");
    printf("  int *p = arr;\n\n");
    
    printf("  p     = %p, *p = %d\n", (void*)p, *p);
    printf("  p + 1 = %p, *(p+1) = %d\n", (void*)(p+1), *(p+1));
    printf("  p + 2 = %p, *(p+2) = %d\n\n", (void*)(p+2), *(p+2));
    
    printf("  Address increment: %lu bytes (sizeof(int))\n\n", 
           (unsigned long)((char*)(p+1) - (char*)p));
    
    // Type mismatch warning demonstration
    printf("Type safety:\n");
    printf("  int *ip assigned to float* would misinterpret data\n");
    printf("  Same bytes, different interpretation!\n");
    
    return 0;
}
