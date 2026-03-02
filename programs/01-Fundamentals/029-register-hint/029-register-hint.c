#include <stdio.h>
#include <time.h>

long sum_with_register(int n) {
    register long sum = 0;
    register int i;
    
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    
    return sum;
}

long sum_without_register(int n) {
    long sum = 0;
    int i;
    
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    
    return sum;
}

int main(void) {
    printf("=== The register Hint ===\n\n");
    
    printf("--- What is register? ---\n");
    printf("'register' suggests storing a variable in a CPU register\n");
    printf("for faster access. It's only a HINT - compiler may ignore it.\n");
    
    printf("\n--- Key Restrictions ---\n");
    printf("1. Cannot take address of register variable (&var is illegal)\n");
    printf("2. Modern compilers usually ignore the hint\n");
    printf("3. Compiler's optimizer often makes better choices\n");
    
    printf("\n--- Syntax Examples ---\n");
    printf("register int counter;        // Hint for fast counter\n");
    printf("register char *ptr;          // Hint for fast pointer\n");
    printf("register unsigned long acc;  // Hint for accumulator\n");
    
    printf("\n--- Cannot Take Address ---\n");
    register int fast_var = 42;
    printf("register int fast_var = %d;\n", fast_var);
    printf("// &fast_var would be a compile error!\n");
    printf("// Registers don't have memory addresses.\n");
    
    printf("\n--- Historical Context ---\n");
    printf("In early C (1970s-1980s):\n");
    printf("  - Compilers had limited optimization\n");
    printf("  - Programmers knew which variables were 'hot'\n");
    printf("  - register gave meaningful performance gains\n");
    printf("\nIn modern C:\n");
    printf("  - Compilers analyze data flow automatically\n");
    printf("  - Better at register allocation than humans\n");
    printf("  - register is effectively ignored by most compilers\n");
    
    printf("\n--- Performance Comparison ---\n");
    int iterations = 100000000;
    clock_t start, end;
    long result;
    
    start = clock();
    result = sum_with_register(iterations);
    end = clock();
    printf("With 'register' hint: %ld (%.3f seconds)\n", 
           result, (double)(end - start) / CLOCKS_PER_SEC);
    
    start = clock();
    result = sum_without_register(iterations);
    end = clock();
    printf("Without 'register':   %ld (%.3f seconds)\n", 
           result, (double)(end - start) / CLOCKS_PER_SEC);
    
    printf("\n(Results likely similar - optimizer handles both cases)\n");
    
    printf("\n--- Modern Best Practice ---\n");
    printf("1. Don't use 'register' in new code\n");
    printf("2. Trust the compiler's optimizer (-O2, -O3)\n");
    printf("3. Profile before optimizing\n");
    printf("4. If you see it in old code, it's safe to remove\n");
    
    printf("\n--- Still Useful For ---\n");
    printf("1. Documenting intent (this variable is performance-critical)\n");
    printf("2. Preventing accidental address-taking\n");
    printf("3. Embedded systems with specific compilers\n");
    
    return 0;
}
