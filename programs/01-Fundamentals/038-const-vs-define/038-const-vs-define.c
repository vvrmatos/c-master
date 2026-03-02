#include <stdio.h>

#define MACRO_PI 3.14159265358979
#define MACRO_BUFFER_SIZE 1024
#define MACRO_SQUARE(x) ((x) * (x))

const double CONST_PI = 3.14159265358979;
const int CONST_BUFFER_SIZE = 1024;

static inline int const_square(int x) {
    return x * x;
}

int main(void) {
    printf("=== const vs #define ===\n\n");
    
    printf("1. TYPE SAFETY:\n");
    printf("   #define has no type - pure text substitution\n");
    printf("   const has a type - compiler checks type compatibility\n\n");
    
    printf("   MACRO_PI: %f (no type, substituted as text)\n", MACRO_PI);
    printf("   CONST_PI: %f (type: const double)\n", CONST_PI);
    
    printf("\n2. SCOPE:\n");
    printf("   #define has file scope from definition to #undef or EOF\n");
    printf("   const follows normal C scoping rules\n");
    {
        const int local_const = 42;
        printf("   Local const in block: %d\n", local_const);
    }
    
    printf("\n3. DEBUGGING:\n");
    printf("   #define: symbol not in debug info (already substituted)\n");
    printf("   const: symbol visible in debugger\n");
    printf("   CONST_BUFFER_SIZE address: %p\n", (void*)&CONST_BUFFER_SIZE);
    
    printf("\n4. MEMORY:\n");
    printf("   #define: no memory (text substitution)\n");
    printf("   const: may occupy memory (depends on usage)\n");
    printf("   sizeof pointer to CONST_PI: %zu bytes\n", sizeof(&CONST_PI));
    
    printf("\n5. MACRO PITFALL - multiple evaluation:\n");
    int a = 5;
    printf("   a = 5\n");
    printf("   MACRO_SQUARE(a++) = %d\n", MACRO_SQUARE(a++));
    printf("   a is now %d (incremented TWICE!)\n", a);
    
    a = 5;
    printf("   a = 5\n");
    printf("   const_square(a++) = %d\n", const_square(a++));
    printf("   a is now %d (incremented ONCE)\n", a);
    
    printf("\n6. WHEN TO USE #define:\n");
    printf("   - Conditional compilation: #if DEBUG\n");
    printf("   - Include guards: #ifndef HEADER_H\n");
    printf("   - Stringification: #var\n");
    printf("   - Token pasting: a##b\n");
    printf("   - Compile-time array sizes (C89)\n");
    
    printf("\n7. WHEN TO USE const:\n");
    printf("   - Type-safe constants\n");
    printf("   - Debuggable values\n");
    printf("   - When you need an address\n");
    printf("   - Modern C best practice\n");
    
    printf("\n8. ARRAY SIZE COMPARISON:\n");
    
    int macro_array[MACRO_BUFFER_SIZE];
    printf("   int macro_array[MACRO_BUFFER_SIZE]; // Works\n");
    printf("   sizeof(macro_array) = %zu\n", sizeof(macro_array));
    
    printf("\n9. C99+ Variable Length Arrays:\n");
    int size = 10;
    int vla[size];
    printf("   int vla[size]; // Works in C99+ with variable\n");
    printf("   sizeof(vla) = %zu\n", sizeof(vla));
    
    printf("\n10. RECOMMENDATION:\n");
    printf("   Use const for values, #define for preprocessor features\n");
    printf("   Use enum for related integer constants\n");
    printf("   Use static const for file-scope constants\n");
    
    return 0;
}
