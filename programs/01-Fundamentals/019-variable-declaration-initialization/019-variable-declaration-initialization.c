#include <stdio.h>

int main(void) {
    printf("=== Variable Declaration & Initialization ===\n\n");
    
    int a;
    printf("Declared but not initialized:\n");
    printf("  int a; (value is UNDEFINED - garbage!)\n\n");
    
    int b = 10;
    printf("Declared and initialized:\n");
    printf("  int b = 10; -> b = %d\n\n", b);
    
    int x, y, z;
    x = 1;
    y = 2;
    z = 3;
    printf("Declared, then assigned:\n");
    printf("  int x, y, z;\n");
    printf("  x = %d, y = %d, z = %d\n\n", x, y, z);
    
    int p = 5, q = 10, r = 15;
    printf("Multiple declarations with initialization:\n");
    printf("  int p = 5, q = 10, r = 15;\n");
    printf("  p = %d, q = %d, r = %d\n\n", p, q, r);
    
    const int MAX = 100;
    printf("Constant (must be initialized):\n");
    printf("  const int MAX = %d;\n", MAX);
    
    return 0;
}
