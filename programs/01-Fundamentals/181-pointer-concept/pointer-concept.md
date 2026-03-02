# Pointer Concept - What Pointers Are

## Overview
A pointer is a variable that stores a memory address. Instead of holding a data value directly, a pointer holds the location (address) where data is stored in memory.

## The Fundamental Concept

```
Memory:
┌──────────┬──────────┬──────────┬──────────┐
│ Address  │  1000    │  1004    │  1008    │
├──────────┼──────────┼──────────┼──────────┤
│ Variable │  value   │   ptr    │   ...    │
├──────────┼──────────┼──────────┼──────────┤
│ Content  │   42     │  1000    │   ...    │
└──────────┴──────────┴──────────┴──────────┘
```

- `value` contains 42
- `ptr` contains 1000 (the address of `value`)
- `*ptr` means "what's at address 1000" = 42

## Key Terminology

| Term | Meaning |
|------|---------|
| Pointer | Variable storing an address |
| Address | Memory location (like 0x7fff5...) |
| Reference | Getting address of variable (&var) |
| Dereference | Accessing value at address (*ptr) |
| Point to | A pointer "points to" what it references |

## Why Pointers Matter

### 1. Indirect Access
Access and modify variables through their address:
```c
int x = 10;
int *p = &x;
*p = 20;  // x is now 20
```

### 2. Efficiency
Pass large data by address, not by copying:
```c
void process(struct BigData *data);  // Pass address, not copy
```

### 3. Dynamic Memory
Allocate memory at runtime:
```c
int *arr = malloc(n * sizeof(int));  // Array of unknown size
```

### 4. Data Structures
Build linked structures:
```c
struct Node {
    int data;
    struct Node *next;  // Pointer to another node
};
```

## Mental Model
Think of pointers like:
- A **house address** written on paper (pointer = paper with address)
- The **house** is the actual variable (stored at that address)
- You can visit the house using the address (dereferencing)

---

# Kata Challenge: Memory Address Explorer

## Objective
Write a program that demonstrates the relationship between variables and their addresses.

## Requirements
1. Declare variables of different types (int, char, float, double)
2. Create pointers to each variable
3. Display:
   - Each variable's value
   - Each variable's address
   - Each pointer's value (the address it holds)
   - Each pointer's own address
   - The dereferenced value (*ptr)
4. Modify variables through pointers and show the changes

## Example Output
```
=== Integer ===
int x = 42
Address of x: 0x7fff5e8aa8ac
Pointer px holds: 0x7fff5e8aa8ac
Address of px: 0x7fff5e8aa8a0
Value via *px: 42

[After *px = 100]
x is now: 100

=== Character ===
char c = 'A'
...
```

## Hints
- Use `%p` format for addresses (cast to `void*`)
- Notice that different types have different sizes
- Observe how addresses differ between variables

## Bonus
- Show the byte difference between consecutive addresses
- Display memory alignment patterns
- Create a function that swaps two variables using pointers
