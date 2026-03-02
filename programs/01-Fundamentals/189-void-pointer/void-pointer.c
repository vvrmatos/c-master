/*
 * Void Pointer - Generic void* pointers
 */

#include <stdio.h>

// Generic print function using void pointer
void print_value(void *ptr, char type) {
    switch (type) {
        case 'i':
            printf("int: %d\n", *(int*)ptr);
            break;
        case 'f':
            printf("float: %.2f\n", *(float*)ptr);
            break;
        case 'c':
            printf("char: %c\n", *(char*)ptr);
            break;
        case 'd':
            printf("double: %.4f\n", *(double*)ptr);
            break;
    }
}

// Generic swap function
void generic_swap(void *a, void *b, size_t size) {
    unsigned char temp[size];
    unsigned char *pa = a;
    unsigned char *pb = b;
    
    for (size_t i = 0; i < size; i++) {
        temp[i] = pa[i];
        pa[i] = pb[i];
        pb[i] = temp[i];
    }
}

int main(void) {
    printf("Void Pointer (void*):\n\n");
    
    int i = 42;
    float f = 3.14f;
    char c = 'X';
    double d = 2.71828;
    
    void *generic;
    
    printf("void* can point to any type:\n");
    generic = &i;
    printf("  generic = &i; *(int*)generic = %d\n", *(int*)generic);
    generic = &f;
    printf("  generic = &f; *(float*)generic = %.2f\n", *(float*)generic);
    generic = &c;
    printf("  generic = &c; *(char*)generic = %c\n\n", *(char*)generic);
    
    printf("Generic print function:\n");
    print_value(&i, 'i');
    print_value(&f, 'f');
    print_value(&c, 'c');
    print_value(&d, 'd');
    
    printf("\nGeneric swap:\n");
    int x = 100, y = 200;
    printf("  Before: x=%d, y=%d\n", x, y);
    generic_swap(&x, &y, sizeof(int));
    printf("  After:  x=%d, y=%d\n", x, y);
    
    return 0;
}
