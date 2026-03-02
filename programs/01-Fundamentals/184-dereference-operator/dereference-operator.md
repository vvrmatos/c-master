# Dereference Operator - Using *

## Overview
The dereference operator `*` (also called indirection operator) accesses the value stored at the memory address held by a pointer. It "follows" the pointer to get or set the actual data.

## Syntax
```c
*pointer_name
```

## Reading Values (Dereferencing)
```c
int x = 42;
int *ptr = &x;

printf("%d\n", *ptr);  // Prints 42 (value at address in ptr)
```

## Writing Values (Indirect Assignment)
```c
int x = 42;
int *ptr = &x;

*ptr = 100;  // Changes x to 100
printf("%d\n", x);  // Prints 100
```

## * Has Two Meanings

| Context | Meaning | Example |
|---------|---------|---------|
| Declaration | "pointer to" | `int *ptr;` |
| Expression | "value at" | `*ptr = 10;` |

## Dereference Operations

### Read
```c
int value = *ptr;    // Get value at ptr
```

### Write
```c
*ptr = 100;          // Set value at ptr
```

### Modify
```c
(*ptr)++;            // Increment value at ptr
*ptr += 10;          // Add 10 to value at ptr
```

### Compare
```c
if (*ptr == 42)      // Check value at ptr
```

## Multiple Indirection
```c
int x = 5;
int *p = &x;         // Pointer to x
int **pp = &p;       // Pointer to pointer

printf("%d\n", **pp);  // Prints 5 (dereference twice)
```

## Common Mistakes
```c
int *ptr;            // Uninitialized pointer
*ptr = 42;           // CRASH! No valid address

int *ptr = NULL;
*ptr = 42;           // CRASH! Dereferencing NULL
```

---

# Kata Challenge: Pointer Manipulation

## Objective
Write a program that demonstrates various dereference operations and their effects on original variables.

## Requirements
1. Create variables and pointers to them
2. Demonstrate:
   - Reading values through pointers
   - Modifying values through pointers
   - Arithmetic operations through pointers
   - Multiple levels of indirection (pointer to pointer)
3. Create a swap function using pointers
4. Show before/after values for all operations

## Example Output
```
=== Dereference Operations ===

Initial: x = 10, y = 20
ptr_x points to x, ptr_y points to y

Reading: *ptr_x = 10, *ptr_y = 20

Modifying *ptr_x = 100:
  x is now: 100

Arithmetic (*ptr_y += 5):
  y is now: 25

=== Swap Function ===
Before swap: a = 5, b = 10
After swap:  a = 10, b = 5

=== Double Pointer ===
int **pp = &ptr_x;
*pp = ptr_y;  // Now ptr_x points to y!
*ptr_x = 999;
y is now: 999
```

## Hints
- Use parentheses for clarity: `(*ptr)++` vs `*ptr++`
- Swap function: `void swap(int *a, int *b)`
- Double pointer allows changing what a pointer points to

## Bonus
- Implement increment/decrement through pointers
- Create a function that uses triple pointers
- Show how dereference works with struct pointers (`->`)
