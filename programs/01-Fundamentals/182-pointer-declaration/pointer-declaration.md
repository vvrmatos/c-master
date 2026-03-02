# Pointer Declaration - Declaring Pointers

## Overview
A pointer is declared by using the asterisk (*) symbol. The type before the asterisk indicates what type of data the pointer will point to.

## Declaration Syntax
```c
type *pointer_name;
```

## Declaration Styles
All three styles are syntactically valid:
```c
int *ptr;    // Style 1: * near variable name (K&R style, preferred)
int* ptr;    // Style 2: * near type
int * ptr;   // Style 3: Spaces on both sides
```

### Why Style 1 is Preferred
```c
int* a, b;    // MISLEADING! Only 'a' is a pointer, 'b' is int
int *a, *b;   // CLEAR: Both are pointers
```

The `*` binds to the variable name, not the type.

## Pointer for Different Types
```c
int *int_ptr;        // Points to int
char *char_ptr;      // Points to char
float *float_ptr;    // Points to float
double *dbl_ptr;     // Points to double
void *void_ptr;      // Generic pointer (any type)
```

## Declaration vs Initialization
```c
int *ptr;           // Declaration only (uninitialized - dangerous!)
int *ptr = NULL;    // Declared and initialized to NULL (safe)
int *ptr = &var;    // Declared and initialized to address
```

## Multiple Declarations
```c
// Correct way to declare multiple pointers:
int *p1, *p2, *p3;

// Each * is required:
int *p1;
int *p2;
int *p3;

// DO NOT do this (common mistake):
int* p1, p2, p3;  // Only p1 is pointer!
```

## Reading Pointer Declarations
Read from right to left:
- `int *p` → "p is a pointer to int"
- `const int *p` → "p is a pointer to const int"
- `int *const p` → "p is a const pointer to int"

---

# Kata Challenge: Pointer Declaration Practice

## Objective
Write a program that declares and uses pointers to various types, demonstrating proper declaration syntax.

## Requirements
1. Declare pointers to: int, char, float, double, and another pointer (pointer to pointer)
2. Initialize each pointer with a valid address
3. Print:
   - The declaration style used
   - The type of data pointed to
   - The size of the pointer
   - The size of what it points to

## Example Output
```
=== Pointer Declarations ===

int *int_ptr = &integer_var;
  Pointer size: 8 bytes
  Target size: 4 bytes
  Target value: 42

char *char_ptr = &char_var;
  Pointer size: 8 bytes
  Target size: 1 byte
  Target value: 'A'

double *dbl_ptr = &double_var;
  Pointer size: 8 bytes
  Target size: 8 bytes
  Target value: 3.14159

int **ptr_to_ptr = &int_ptr;
  Pointer size: 8 bytes
  **ptr_to_ptr: 42
```

## Hints
- Use `sizeof(ptr)` for pointer size
- Use `sizeof(*ptr)` for target size
- All pointers are typically the same size (8 bytes on 64-bit)
- What changes is the size of what they point to

## Bonus
- Demonstrate the multiple declaration trap
- Show const pointer variants
- Create an array of pointers
