---
id: "029"
title: "The register Hint"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - register
  - storage-class
  - optimization
  - performance
difficulty: beginner
source: "C11 Standard 6.7.1"
---

# 029 — The register Hint

## Concept

`register` is a storage class specifier that **suggests** the compiler store a variable in a CPU register instead of RAM for faster access.

**Important: It's only a hint!** Modern compilers typically ignore it and make their own register allocation decisions.

**Syntax:**
```c
register int counter;
register char *ptr;
register unsigned long accumulator;
```

**Key restriction: Cannot take the address**
```c
register int x = 10;
int *p = &x;  // COMPILE ERROR! Registers don't have addresses
```

**Historical context:**
| Era | register Usefulness |
|-----|---------------------|
| 1970s-80s | Very useful, compilers had limited optimization |
| 1990s | Somewhat useful on some platforms |
| 2000s+ | Mostly ignored, compilers optimize better |

**Why compilers ignore it:**
1. Modern optimizers analyze entire functions
2. They track variable "liveness" and access patterns
3. They make globally optimal register allocation
4. Programmer hints are often counterproductive

**When register might still matter:**
- Embedded systems with primitive compilers
- Specific architectures with compiler quirks
- As documentation of programmer intent

**Modern best practice:**
```c
// Old style (discouraged)
register int i;
for (i = 0; i < n; i++) { }

// Modern style (preferred)
for (int i = 0; i < n; i++) { }  // Compiler handles optimization
```

**Compile with optimization instead:**
```bash
gcc -O2 program.c   # Let compiler optimize
gcc -O3 program.c   # Aggressive optimization
```

## Code

```c
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
```

## Output

```
=== The register Hint ===

--- What is register? ---
'register' suggests storing a variable in a CPU register
for faster access. It's only a HINT - compiler may ignore it.

--- Key Restrictions ---
1. Cannot take address of register variable (&var is illegal)
2. Modern compilers usually ignore the hint
3. Compiler's optimizer often makes better choices

--- Syntax Examples ---
register int counter;        // Hint for fast counter
register char *ptr;          // Hint for fast pointer
register unsigned long acc;  // Hint for accumulator

--- Cannot Take Address ---
register int fast_var = 42;
// &fast_var would be a compile error!
// Registers don't have memory addresses.

--- Historical Context ---
In early C (1970s-1980s):
  - Compilers had limited optimization
  - Programmers knew which variables were 'hot'
  - register gave meaningful performance gains

In modern C:
  - Compilers analyze data flow automatically
  - Better at register allocation than humans
  - register is effectively ignored by most compilers

--- Performance Comparison ---
With 'register' hint: 5000000050000000 (0.231 seconds)
Without 'register':   5000000050000000 (0.228 seconds)

(Results likely similar - optimizer handles both cases)

--- Modern Best Practice ---
1. Don't use 'register' in new code
2. Trust the compiler's optimizer (-O2, -O3)
3. Profile before optimizing
4. If you see it in old code, it's safe to remove

--- Still Useful For ---
1. Documenting intent (this variable is performance-critical)
2. Preventing accidental address-taking
3. Embedded systems with specific compilers
```

## Key Takeaways

- `register` hints that a variable should be in a CPU register
- Modern compilers typically ignore this hint
- You cannot take the address (`&`) of a register variable
- Trust compiler optimization (`-O2`, `-O3`) instead
- The restriction on `&` is the only guaranteed effect
- Legacy code may use it; safe to remove in modern code
- Profile before attempting manual optimization

## Challenge

Compare the assembly output (using `gcc -S`) for functions with and without `register` variables. Compile with `-O0` (no optimization) and `-O2` (optimization). Does `register` make a difference?

## Related

- [[027-auto-storage-class]] — auto storage class
- [[028-static-variables]] — static storage class
- [[030-extern-declaration]] — extern linkage
