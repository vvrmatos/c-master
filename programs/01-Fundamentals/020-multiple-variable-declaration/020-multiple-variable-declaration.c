#include <stdio.h>

int main(void) {
    printf("=== Multiple Variable Declaration ===\n\n");
    
    int a, b, c;
    a = 1; b = 2; c = 3;
    printf("Same type, declared together:\n");
    printf("  int a, b, c;\n");
    printf("  a = %d, b = %d, c = %d\n\n", a, b, c);
    
    int x = 10, y = 20, z = 30;
    printf("With initialization:\n");
    printf("  int x = 10, y = 20, z = 30;\n");
    printf("  x = %d, y = %d, z = %d\n\n", x, y, z);
    
    printf("GOTCHA with pointers:\n");
    printf("  int* p, q;    // p is pointer, q is int!\n");
    printf("  int *p, *q;   // Both are pointers\n\n");
    
    int *p1, *p2;
    int value = 100;
    p1 = &value;
    p2 = &value;
    printf("Correct pointer declaration:\n");
    printf("  int *p1, *p2;\n");
    printf("  *p1 = %d, *p2 = %d\n\n", *p1, *p2);
    
    printf("Best practice: One declaration per line\n");
    printf("  int width = 10;\n");
    printf("  int height = 20;\n");
    printf("  int *ptr = NULL;\n");
    
    return 0;
}
