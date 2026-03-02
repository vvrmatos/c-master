# Pointer Size - sizeof on Pointers

## Overview
All pointers on a given system are the same size, regardless of what type they point to. This size depends on the system architecture (32-bit or 64-bit), not the pointed-to type.

## Key Concept
```c
sizeof(char*)   == sizeof(int*)   == sizeof(double*)
sizeof(void*)   == sizeof(struct*)  == sizeof(int**)
```

## Pointer Sizes by Architecture

| Architecture | Pointer Size | Address Range |
|--------------|--------------|---------------|
| 32-bit | 4 bytes | 0 to 4GB |
| 64-bit | 8 bytes | 0 to 16EB (theoretical) |

## sizeof with Pointers

### Pointer Size
```c
int *ptr;
sizeof(ptr)      // Size of pointer: 8 bytes (64-bit)
sizeof(int*)     // Same: 8 bytes
```

### Target Size
```c
int *ptr;
sizeof(*ptr)     // Size of what ptr points to: 4 bytes
```

## Why All Pointers Same Size?
A pointer stores a memory address. On a 64-bit system:
- All addresses are 64 bits (8 bytes)
- Doesn't matter if pointing to char (1 byte) or struct (many bytes)
- The address itself is always the same size

## Practical Implications

### Array of Pointers
```c
int *arr[10];
sizeof(arr)  // 10 * 8 = 80 bytes (on 64-bit)
```

### Structure with Pointers
```c
struct Node {
    int data;       // 4 bytes
    struct Node *next;  // 8 bytes (+ padding)
};
// sizeof(struct Node) typically 16 bytes with alignment
```

### Pointer to Different Types
```c
char c;
int i;
char *cp = &c;    // 8 bytes
int *ip = &i;     // 8 bytes (same!)
// But *cp is 1 byte, *ip is 4 bytes
```

## Common Patterns
```c
// Allocating array of pointers
int **arr = malloc(n * sizeof(int*));

// Passing array to function
void func(int *arr, size_t count);  // Only pointer passed (8 bytes)
```

---

# Kata Challenge: Memory Layout Analyzer

## Objective
Write a program that analyzes and displays memory layout including pointer sizes, alignment, and structure padding.

## Requirements
1. Display sizes of all basic types and their pointers
2. Create structures with various pointer combinations
3. Show:
   - Individual member sizes
   - Total structure size
   - Padding bytes
   - Alignment requirements
4. Compare pointer sizes across types

## Example Output
```
=== System Information ===
Architecture: 64-bit
Pointer size: 8 bytes

=== Basic Types vs Pointers ===
Type        Size    Pointer Size
char        1       8
short       2       8
int         4       8
long        8       8
float       4       8
double      8       8

=== Structure Analysis ===
struct Example {
    char c;      // offset 0, size 1, padding 7
    double d;    // offset 8, size 8, padding 0
    char *ptr;   // offset 16, size 8, padding 0
    int i;       // offset 24, size 4, padding 4
};
Total size: 32 bytes
Without padding: 21 bytes
Padding overhead: 11 bytes (34%)

=== Pointer Array vs Value Array ===
int values[100]: 400 bytes
int *pointers[100]: 800 bytes
```

## Hints
- Use `offsetof()` macro for structure member offsets
- Calculate padding as gaps between members
- Use `__alignof__` or `_Alignof` for alignment requirements

## Bonus
- Reorder struct members to minimize padding
- Show difference between packed and unpacked structs
- Demonstrate pointer alignment requirements
- Create a generic struct analyzer macro
