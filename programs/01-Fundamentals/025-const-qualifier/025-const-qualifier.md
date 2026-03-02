---
id: "025"
title: "The const Qualifier"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - const
  - qualifiers
  - pointers
  - immutability
difficulty: beginner
source: "C11 Standard 6.7.3"
---

# 025 — The const Qualifier

## Concept

The `const` qualifier declares that a variable's value cannot be modified after initialization. It's essential for:

- Creating named constants
- Preventing accidental modifications
- Self-documenting code (reader knows value won't change)
- Enabling compiler optimizations
- Function contracts (promising not to modify parameters)

**Basic usage:**
```c
const int MAX = 100;      // Cannot be changed
const double PI = 3.14159;
```

**const with pointers (read right-to-left):**

| Declaration | What's const? | Can change ptr? | Can change *ptr? |
|-------------|---------------|-----------------|------------------|
| `const int *p` | Data pointed to | Yes | No |
| `int *const p` | Pointer itself | No | Yes |
| `const int *const p` | Both | No | No |

**Mnemonic:** "const before * = const data, const after * = const pointer"

**In function parameters:**
```c
// Promise: function won't modify the string
void print(const char *str);

// Promise: function won't modify the array
int sum(const int *arr, int size);
```

**const vs #define:**
| Feature | const | #define |
|---------|-------|---------|
| Type checking | Yes | No |
| Debuggable | Yes | No (just text replacement) |
| Scope | Block/file | Global from definition |
| Memory | May use memory | No memory |

Prefer `const` for typed constants in modern C.

## Code

```c
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
```

## Output

```
=== The const Qualifier ===

--- Basic const Variables ---
MAX_SIZE = 100
PI = 3.1415926536
NEWLINE = '\n' (ASCII 10)

--- const with Pointers ---
Pointer to const int: *ptr_to_const = 42
Can change pointer: *ptr_to_const = 99

Const pointer to int: *const_ptr = 42
Can change value: *const_ptr = 100

Const pointer to const int: 100 (nothing can change)

--- const in Function Parameters ---
String: Hello, World!
Sum of array: 15
(const ensures the function won't modify our array)

--- const vs #define ---
const int:  Has type, scope, can be debugged
#define:    Text replacement, no type checking
Prefer const for typed constants!

--- Reading const Pointer Declarations ---
Read right to left:
  const int *p     -> p is pointer to int that is const
  int *const p     -> p is const pointer to int
  const int *const p -> p is const pointer to const int
```

## Key Takeaways

- `const` makes variables immutable after initialization
- Use `const` for function parameters to document and enforce contracts
- Read pointer declarations right-to-left for clarity
- `const int *p` = pointer to const data (data protected)
- `int *const p` = const pointer (pointer protected)
- Prefer `const` over `#define` for typed constants
- Compiler may optimize const variables more aggressively

## Challenge

Create a function that safely copies a string: `void safe_copy(char *dest, size_t dest_size, const char *src)`. Use const correctly to show which parameters are inputs vs outputs.

## Related

- [[026-volatile-qualifier]] — volatile qualifier
- [[024-signed-vs-unsigned]] — Type modifiers
- [[005-preprocessor-and-include]] — #define macros
