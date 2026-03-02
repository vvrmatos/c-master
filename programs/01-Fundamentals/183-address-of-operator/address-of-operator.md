# Address-of Operator - Using &

## Overview
The address-of operator `&` returns the memory address of a variable. This address can be stored in a pointer variable, enabling indirect access to the original variable.

## Syntax
```c
&variable_name
```

## Basic Usage
```c
int x = 10;
int *ptr = &x;  // ptr now holds the address of x

printf("Address of x: %p\n", (void*)&x);
```

## What & Returns
- The memory location where the variable is stored
- A value of type "pointer to [variable's type]"
- Typically displayed as hexadecimal (e.g., 0x7fff5e8a)

## Type Matching
```c
int num = 5;
int *ip = &num;      // OK: int* = address of int

char ch = 'A';
char *cp = &ch;      // OK: char* = address of char

// Type mismatch (compiler warning):
int *bad = &ch;      // Warning: incompatible pointer type
```

## Where & Can Be Used

### Valid
```c
int x;
&x         // Address of variable

int arr[5];
&arr[0]    // Address of array element
&arr       // Address of entire array (different type!)

struct Point p;
&p         // Address of structure
&p.x       // Address of structure member
```

### Invalid
```c
&10        // Error: cannot take address of literal
&(x + 1)   // Error: cannot take address of expression
```

## Address vs Value
| Expression | Type | Meaning |
|------------|------|---------|
| x | int | The value stored in x |
| &x | int* | The address where x is stored |
| *&x | int | Value at address of x (same as x) |

---

# Kata Challenge: Address Explorer

## Objective
Write a program that explores memory addresses of various variable types and demonstrates address relationships.

## Requirements
1. Declare variables of types: int, char, float, double, array
2. Print the address of each variable
3. Calculate and display the byte offset between consecutive variables
4. Show how array element addresses relate to each other
5. Demonstrate that `&array[i]` equals `array + i`

## Example Output
```
=== Variable Addresses ===
int a at:    0x7fff5e8a8a10
char b at:   0x7fff5e8a8a0f
float c at:  0x7fff5e8a8a08
double d at: 0x7fff5e8a8a00

=== Address Relationships ===
Bytes between a and b: 1
Bytes between c and d: 8

=== Array Address Arithmetic ===
int arr[5] at: 0x7fff5e8a89f0
&arr[0] = 0x7fff5e8a89f0
&arr[1] = 0x7fff5e8a89f4 (offset: 4 bytes)
&arr[2] = 0x7fff5e8a89f8 (offset: 4 bytes)

arr + 0 = 0x7fff5e8a89f0 (same as &arr[0])
arr + 1 = 0x7fff5e8a89f4 (same as &arr[1])
```

## Hints
- Cast addresses to `(void*)` for `%p` format
- Calculate byte difference by casting to `char*`
- Remember: `arr + i` is same as `&arr[i]`

## Bonus
- Show stack growth direction
- Display addresses before and after function calls
- Compare local vs global variable addresses
