# Pointer Assignment - Assigning Pointers

## Overview
There are two fundamental assignment operations with pointers:
1. **Assigning TO a pointer** - Change what address the pointer holds
2. **Assigning THROUGH a pointer** - Change the value at the pointed-to address

## Two Types of Assignment

### Assign TO Pointer (Change Address)
```c
int x = 10, y = 20;
int *ptr;

ptr = &x;    // ptr now holds address of x
ptr = &y;    // ptr now holds address of y
```

### Assign THROUGH Pointer (Change Value)
```c
int x = 10;
int *ptr = &x;

*ptr = 100;  // x is now 100
```

## Visual Comparison

```
ptr = &y;     // Change WHERE ptr points
┌─────┐       ┌─────┐
│ ptr │──────>│  y  │
└─────┘       └─────┘

*ptr = 100;   // Change WHAT ptr points to
┌─────┐       ┌─────┐
│ ptr │──────>│ 100 │  (value changed)
└─────┘       └─────┘
```

## Copying Pointers

```c
int *ptr1 = &x;
int *ptr2 = ptr1;  // Both point to same location
```

After copying:
- `ptr1 == ptr2` (same address)
- `*ptr1 == *ptr2` (same value)
- Changing `*ptr1` affects what `*ptr2` sees

## Assignment Chain
```c
int x = 5;
int *p = &x;
int **pp = &p;

*p = 10;      // x = 10
**pp = 20;    // x = 20
*pp = NULL;   // p = NULL (not x!)
```

## Key Distinctions

| Operation | Syntax | Effect |
|-----------|--------|--------|
| Assign address | `ptr = &var` | Change what ptr points to |
| Assign value | `*ptr = val` | Change value at address |
| Copy pointer | `ptr2 = ptr1` | Both point to same place |
| Reassign | `ptr = &other` | Point to different variable |

---

# Kata Challenge: Pointer Swap Operations

## Objective
Write a program demonstrating the difference between swapping pointers and swapping values through pointers.

## Requirements
1. Implement two functions:
   - `swap_values(int *a, int *b)` - Swap the values at two addresses
   - `swap_pointers(int **a, int **b)` - Swap two pointer variables
2. Show the difference in effect
3. Demonstrate with original variables and pointers

## Example Output
```
=== Initial State ===
x = 10, y = 20
ptr1 -> x (&x = 0x7fff...)
ptr2 -> y (&y = 0x7fff...)

=== After swap_values(ptr1, ptr2) ===
x = 20, y = 10 (values swapped)
ptr1 still -> x
ptr2 still -> y

=== Reset and try swap_pointers ===
x = 10, y = 20

=== After swap_pointers(&ptr1, &ptr2) ===
x = 10, y = 20 (values unchanged)
ptr1 now -> y (addresses swapped)
ptr2 now -> x
*ptr1 = 20, *ptr2 = 10
```

## Hints
- `swap_values` uses: `int temp = *a; *a = *b; *b = temp;`
- `swap_pointers` uses: `int *temp = *a; *a = *b; *b = temp;`
- Track both the variable values AND what pointers point to

## Bonus
- Create a generic swap using `void*`
- Implement cyclic rotation of three pointers
- Show pointer assignment in linked list operations
