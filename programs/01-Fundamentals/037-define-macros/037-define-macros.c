#include <stdio.h>

#define PI 3.14159265358979
#define E 2.71828182845904
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 100
#define VERSION "1.0.0"
#define DEBUG_MODE 1

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define PRINT_INT(var) printf("  " #var " = %d\n", var)
#define PRINT_VAR(var) printf("  " #var " = %d\n", var)

#define CONCAT(a, b) a##b

#define KILOBYTE 1024
#define MEGABYTE (KILOBYTE * 1024)
#define GIGABYTE (MEGABYTE * 1024)

int main(void) {
    printf("=== #define Macros ===\n\n");
    
    printf("Constant macros:\n");
    printf("  PI = %.14f\n", PI);
    printf("  E = %.14f\n", E);
    printf("  BUFFER_SIZE = %d\n", BUFFER_SIZE);
    printf("  MAX_CONNECTIONS = %d\n", MAX_CONNECTIONS);
    printf("  VERSION = %s\n", VERSION);
    
    printf("\nFunction-like macros:\n");
    int x = 5;
    printf("  SQUARE(5) = %d\n", SQUARE(5));
    printf("  SQUARE(x) = %d\n", SQUARE(x));
    printf("  MAX(10, 20) = %d\n", MAX(10, 20));
    printf("  MIN(10, 20) = %d\n", MIN(10, 20));
    printf("  ABS(-42) = %d\n", ABS(-42));
    
    printf("\nStringification operator (#):\n");
    int count = 42;
    PRINT_INT(count);
    int value = 100;
    PRINT_VAR(value);
    
    printf("\nToken concatenation (##):\n");
    int var1 = 10, var2 = 20;
    printf("  CONCAT(var, 1) = %d\n", CONCAT(var, 1));
    printf("  CONCAT(var, 2) = %d\n", CONCAT(var, 2));
    
    printf("\nSize calculations:\n");
    printf("  KILOBYTE = %d\n", KILOBYTE);
    printf("  MEGABYTE = %d\n", MEGABYTE);
    printf("  GIGABYTE = %d\n", GIGABYTE);
    
    printf("\nConditional compilation:\n");
#if DEBUG_MODE
    printf("  DEBUG_MODE is enabled\n");
#else
    printf("  DEBUG_MODE is disabled\n");
#endif
    
    printf("\nPredefined macros:\n");
    printf("  __FILE__ = %s\n", __FILE__);
    printf("  __LINE__ = %d\n", __LINE__);
    printf("  __DATE__ = %s\n", __DATE__);
    printf("  __TIME__ = %s\n", __TIME__);
    
    printf("\nMacro pitfall - side effects:\n");
    int a = 5;
    printf("  a = 5, SQUARE(a++) = %d\n", SQUARE(a++));
    printf("  a is now %d (incremented twice!)\n", a);
    
    return 0;
}
