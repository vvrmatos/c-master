# Pointer Types - Typed Pointers

## Overview
In C, pointers are typed. An `int*` points to an `int`, a `char*` points to a `char`, etc. The type determines how the pointed-to memory is interpreted and how pointer arithmetic works.

## Why Pointers Have Types

### 1. Correct Dereferencing
```c
int x = 0x41424344;  // Byte representation
int *ip = &x;
char *cp = (char*)&x;

printf("%d\n", *ip);   // Reads 4 bytes as int
printf("%c\n", *cp);   // Reads 1 byte as char
```

### 2. Pointer Arithmetic
```c
int *ip = arr;     // ip + 1 moves 4 bytes (sizeof int)
char *cp = str;    // cp + 1 moves 1 byte (sizeof char)
double *dp = d;    // dp + 1 moves 8 bytes (sizeof double)
```

### 3. Type Safety
Compiler warns about type mismatches:
```c
int x = 42;
float *fp = &x;  // Warning: incompatible pointer type
```

## Pointer Size vs Target Size

| Type | Pointer Size | Target Size |
|------|--------------|-------------|
| char* | 8 bytes* | 1 byte |
| int* | 8 bytes* | 4 bytes |
| double* | 8 bytes* | 8 bytes |
| struct* | 8 bytes* | varies |

*On 64-bit systems. All pointers are same size!

## Pointer Arithmetic by Type
```c
int arr[5];
int *p = arr;

p + 1   // Address + sizeof(int) = +4 bytes
p + 2   // Address + 2*sizeof(int) = +8 bytes
p[3]    // Same as *(p + 3)
```

## Type Conversion (Casting)
```c
int x = 65;
int *ip = &x;
char *cp = (char*)ip;  // Explicit cast

printf("%d\n", *ip);   // 65 (as integer)
printf("%c\n", *cp);   // 'A' (first byte as char)
```

## Common Pointer Types

| Declaration | Points to |
|-------------|-----------|
| int *p | Integer |
| char *p | Character / String |
| float *p | Float |
| double *p | Double |
| void *p | Unknown type (generic) |
| struct X *p | Structure |
| int **p | Pointer to int pointer |
| int (*p)[10] | Array of 10 ints |
| int (*p)(int) | Function returning int |

---

# Kata Challenge: Type-Aware Memory Inspector

## Objective
Write a program that displays the same memory region interpreted as different types.

## Requirements
1. Create a union or array of bytes
2. Set up pointers of different types to the same memory
3. Display how the same bytes appear when interpreted as:
   - Individual bytes (unsigned char*)
   - Short integers (short*)
   - Integers (int*)
   - Float (float*)
4. Show how pointer arithmetic differs by type

## Example Output
```
=== Same Memory, Different Interpretations ===
Memory (8 bytes): 00 00 80 3F 00 00 00 40

As unsigned char*: 0 0 128 63 0 0 0 64
As short*: 0 16256 0 16384
As int*: 1065353216 1073741824
As float*: 1.000000 2.000000

=== Pointer Arithmetic ===
Base address: 0x7fff5e8a8a00

char* + 1:   0x7fff5e8a8a01 (+ 1 byte)
short* + 1:  0x7fff5e8a8a02 (+ 2 bytes)
int* + 1:    0x7fff5e8a8a04 (+ 4 bytes)
double* + 1: 0x7fff5e8a8a08 (+ 8 bytes)
```

## Hints
- Use a union to overlay different types
- Cast carefully and use proper format specifiers
- Remember endianness affects byte order

## Bonus
- Detect system endianness
- Show IEEE 754 float bit layout
- Create a hex dump function using char*
