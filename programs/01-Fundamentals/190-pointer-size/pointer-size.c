/*
 * Pointer Size - sizeof on pointers
 */

#include <stdio.h>

int main(void) {
    printf("Pointer Sizes (sizeof):\n\n");
    
    // Declare various pointer types
    char *cp;
    short *sp;
    int *ip;
    long *lp;
    float *fp;
    double *dp;
    void *vp;
    int **pp;  // Pointer to pointer
    
    printf("Pointer sizes (all same on this system):\n");
    printf("  sizeof(char*)   = %zu bytes\n", sizeof(cp));
    printf("  sizeof(short*)  = %zu bytes\n", sizeof(sp));
    printf("  sizeof(int*)    = %zu bytes\n", sizeof(ip));
    printf("  sizeof(long*)   = %zu bytes\n", sizeof(lp));
    printf("  sizeof(float*)  = %zu bytes\n", sizeof(fp));
    printf("  sizeof(double*) = %zu bytes\n", sizeof(dp));
    printf("  sizeof(void*)   = %zu bytes\n", sizeof(vp));
    printf("  sizeof(int**)   = %zu bytes\n\n", sizeof(pp));
    
    printf("Target sizes (different):\n");
    printf("  sizeof(char)   = %zu byte\n", sizeof(char));
    printf("  sizeof(short)  = %zu bytes\n", sizeof(short));
    printf("  sizeof(int)    = %zu bytes\n", sizeof(int));
    printf("  sizeof(long)   = %zu bytes\n", sizeof(long));
    printf("  sizeof(float)  = %zu bytes\n", sizeof(float));
    printf("  sizeof(double) = %zu bytes\n\n", sizeof(double));
    
    // Pointer vs target size
    int x = 42;
    int *ptr = &x;
    
    printf("Pointer vs Target:\n");
    printf("  sizeof(ptr)  = %zu bytes (the pointer)\n", sizeof(ptr));
    printf("  sizeof(*ptr) = %zu bytes (what it points to)\n", sizeof(*ptr));
    
    printf("\nSystem architecture: %zu-bit\n", sizeof(void*) * 8);
    
    return 0;
}
