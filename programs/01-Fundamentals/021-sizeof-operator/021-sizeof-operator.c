#include <stdio.h>

int main(void) {
    int i = 42;
    double d = 3.14159;
    char c = 'A';
    char str[] = "Hello";
    int arr[10];
    
    printf("=== The sizeof Operator ===\n\n");
    
    printf("sizeof on fundamental types:\n");
    printf("  sizeof(char)        = %zu byte\n", sizeof(char));
    printf("  sizeof(short)       = %zu bytes\n", sizeof(short));
    printf("  sizeof(int)         = %zu bytes\n", sizeof(int));
    printf("  sizeof(long)        = %zu bytes\n", sizeof(long));
    printf("  sizeof(long long)   = %zu bytes\n", sizeof(long long));
    printf("  sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("  sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("  sizeof(long double) = %zu bytes\n", sizeof(long double));
    
    printf("\nsizeof on variables:\n");
    printf("  sizeof(i) = %zu bytes (int)\n", sizeof(i));
    printf("  sizeof(d) = %zu bytes (double)\n", sizeof(d));
    printf("  sizeof(c) = %zu byte (char)\n", sizeof(c));
    
    printf("\nsizeof on arrays:\n");
    printf("  sizeof(str) = %zu bytes (includes null terminator)\n", sizeof(str));
    printf("  sizeof(arr) = %zu bytes (10 ints)\n", sizeof(arr));
    printf("  Number of elements in arr: %zu\n", sizeof(arr) / sizeof(arr[0]));
    
    printf("\nsizeof on pointers:\n");
    printf("  sizeof(int *)    = %zu bytes\n", sizeof(int *));
    printf("  sizeof(char *)   = %zu bytes\n", sizeof(char *));
    printf("  sizeof(double *) = %zu bytes\n", sizeof(double *));
    printf("  sizeof(void *)   = %zu bytes\n", sizeof(void *));
    
    printf("\nCompile-time vs runtime:\n");
    printf("  sizeof is evaluated at compile time (mostly)\n");
    printf("  Result type is size_t (use %%zu format specifier)\n");
    
    return 0;
}
