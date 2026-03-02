/* 148-vla-limitations.c - Stack allocation, no initialization */
#include <stdio.h>
#include <stdlib.h>

void demonstrate_no_init(int n) {
    int vla[n];  /* Contains garbage - cannot initialize VLA */
    
    printf("Uninitialized VLA contents (garbage values):\n");
    for (int i = 0; i < n && i < 5; i++) {
        printf("vla[%d] = %d\n", i, vla[i]);
    }
    
    /* Must initialize manually */
    for (int i = 0; i < n; i++) {
        vla[i] = 0;
    }
    printf("After manual initialization: vla[0] = %d\n", vla[0]);
}

void demonstrate_stack_limit(void) {
    /* WARNING: This could crash with stack overflow! */
    /* int huge[1000000]; // BAD - likely exceeds stack */
    
    printf("\nStack size is limited (typically 1-8 MB)\n");
    printf("Large VLAs can cause stack overflow!\n");
    
    /* Safe alternative for large arrays */
    int *heap_array = malloc(1000000 * sizeof(int));
    if (heap_array) {
        printf("Large array allocated on heap: OK\n");
        free(heap_array);
    }
}

int main(void) {
    int n = 5;
    
    /* VLA limitation 1: Cannot use initializer list */
    int vla[n];
    /* int vla[n] = {1,2,3,4,5}; // ERROR: cannot initialize VLA */
    
    /* VLA limitation 2: No sizeof at compile time */
    printf("sizeof(vla) = %zu (computed at runtime)\n", sizeof(vla));
    
    demonstrate_no_init(n);
    demonstrate_stack_limit();
    
    /* VLA limitation 3: Cannot be static or extern */
    /* static int static_vla[n]; // ERROR */
    
    printf("\nVLA Limitations Summary:\n");
    printf("1. Cannot use initializer lists\n");
    printf("2. Allocated on stack (size limited)\n");
    printf("3. Cannot be static or file-scope\n");
    printf("4. Optional in C11 (check __STDC_NO_VLA__)\n");
    
    return 0;
}
