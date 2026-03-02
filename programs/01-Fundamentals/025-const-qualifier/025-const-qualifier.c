#include <stdio.h>
#include <string.h>

void print_string(const char *str) {
    printf("String: %s\n", str);
}

int sum_array(const int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main(void) {
    printf("=== The const Qualifier ===\n\n");
    
    printf("--- Basic const Variables ---\n");
    const int MAX_SIZE = 100;
    const double PI = 3.14159265358979;
    const char NEWLINE = '\n';
    
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("PI = %.10f\n", PI);
    printf("NEWLINE = '\\n' (ASCII %d)\n", NEWLINE);
    
    printf("\n--- const with Pointers ---\n");
    
    int value = 42;
    int other = 99;
    
    const int *ptr_to_const = &value;
    printf("Pointer to const int: *ptr_to_const = %d\n", *ptr_to_const);
    ptr_to_const = &other;
    printf("Can change pointer: *ptr_to_const = %d\n", *ptr_to_const);
    
    int *const const_ptr = &value;
    printf("\nConst pointer to int: *const_ptr = %d\n", *const_ptr);
    *const_ptr = 100;
    printf("Can change value: *const_ptr = %d\n", *const_ptr);
    
    const int *const const_ptr_to_const = &value;
    printf("\nConst pointer to const int: %d (nothing can change)\n", 
           *const_ptr_to_const);
    
    printf("\n--- const in Function Parameters ---\n");
    print_string("Hello, World!");
    
    int numbers[] = {1, 2, 3, 4, 5};
    int total = sum_array(numbers, 5);
    printf("Sum of array: %d\n", total);
    printf("(const ensures the function won't modify our array)\n");
    
    printf("\n--- const vs #define ---\n");
    printf("const int:  Has type, scope, can be debugged\n");
    printf("#define:    Text replacement, no type checking\n");
    printf("Prefer const for typed constants!\n");
    
    printf("\n--- Reading const Pointer Declarations ---\n");
    printf("Read right to left:\n");
    printf("  const int *p     -> p is pointer to int that is const\n");
    printf("  int *const p     -> p is const pointer to int\n");
    printf("  const int *const p -> p is const pointer to const int\n");
    
    return 0;
}
