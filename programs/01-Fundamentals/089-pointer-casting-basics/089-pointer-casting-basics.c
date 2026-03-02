// Pointer casting basics - void*

#include <stdio.h>

int main(void) {
    int x = 42;
    double d = 3.14;
    
    // Any pointer can convert to void*
    void *vp = &x;
    printf("int address: %p\n", vp);
    
    // void* can convert back to original type
    int *ip = vp;
    printf("Value via int*: %d\n", *ip);
    
    // void* to different pointer - works but dangerous!
    vp = &d;
    double *dp = vp;
    printf("Value via double*: %.2f\n", *dp);
    
    // Generic swap using void* (concept preview)
    printf("\nBefore swap: x=%d\n", x);
    int temp = 100;
    vp = &temp;
    ip = vp;
    printf("Temp via void*: %d\n", *ip);
    
    // Warning: casting to wrong type = undefined behavior
    // int *wrong = (int*)&d;  // Compiles but UB if dereferenced
    
    return 0;
}
