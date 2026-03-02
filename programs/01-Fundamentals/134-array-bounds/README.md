# 134 - No Bounds Checking: The Danger

## Overview
C does **not perform bounds checking** on array accesses. Accessing elements outside array bounds causes **undefined behavior** - one of C's most dangerous pitfalls.

## The Problem

### What C Allows (But Shouldn't)
```c
int arr[5] = {10, 20, 30, 40, 50};

arr[5] = 100;    /* Out of bounds - compiles fine! */
arr[100] = 200;  /* Way out of bounds - still compiles! */
arr[-1] = 300;   /* Negative index - compiles! */
```

The compiler generates code without checking if indices are valid.

## Why No Bounds Checking?

### 1. Performance
```c
/* With bounds checking (hypothetical): */
if (i >= 0 && i < size) {
    return arr[i];
} else {
    handle_error();
}

/* Without bounds checking (C): */
return arr[i];  /* Just calculate address and access */
```
Runtime checking adds overhead to every array access.

### 2. Philosophy
C trusts programmers to manage their own memory. It provides minimal safety rails for maximum speed and control.

### 3. Hardware Access
Low-level hardware access sometimes requires accessing specific memory addresses without restrictions.

## Consequences of Out-of-Bounds Access

### 1. Reading Garbage
```c
int arr[3] = {1, 2, 3};
int x = arr[10];  /* Returns whatever is at that address */
```

### 2. Corrupting Other Variables
```c
int a = 100;
int arr[3] = {1, 2, 3};
int b = 200;

arr[3] = 999;  /* Might overwrite 'a' or 'b'! */
```

### 3. Stack Smashing
```c
void function(void) {
    int arr[4];
    arr[10] = 0xDEADBEEF;  /* Might corrupt return address */
}
/* Could crash or allow code injection */
```

### 4. Segmentation Fault
```c
int arr[5];
arr[1000000] = 0;  /* Likely accesses invalid memory -> crash */
```

### 5. Silent Corruption
```c
int scores[3] = {95, 87, 91};
int total = 0;

scores[3] = 100;  /* Might overwrite 'total' */
/* Program continues with wrong values */
```

## Memory Layout Example

```c
int a = 111;
int arr[3] = {10, 20, 30};
int b = 222;

/* Possible memory layout: */
Address:  1000   1004   1008   1012   1016
Value:    [ a ][ arr0 ][ arr1 ][ arr2 ][ b ]
          [111][ 10  ][ 20  ][ 30  ][222]

arr[3] = 999;  /* Writes to address 1016, overwriting b! */
```

## Buffer Overflow Attacks

Out-of-bounds writes are the basis for **buffer overflow** attacks:

```c
void vulnerable(char* input) {
    char buffer[10];
    strcpy(buffer, input);  /* No length check! */
}

/* Attacker provides: */
"AAAAAAAAAAAAAAAA\x08\x04\x08..."  /* Overflows and overwrites return address */
```

This can:
- Crash the program
- Execute arbitrary code
- Bypass security measures

## Safe Programming Practices

### 1. Always Track Size
```c
#define ARRAY_SIZE 10
int arr[ARRAY_SIZE];

for (int i = 0; i < ARRAY_SIZE; i++) {  /* Safe */
    arr[i] = i;
}
```

### 2. Validate Before Access
```c
int safe_access(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        fprintf(stderr, "Index out of bounds: %d\n", index);
        return -1;  /* Or handle error appropriately */
    }
    return arr[index];
}
```

### 3. Use sizeof Idiom
```c
int arr[100];
size_t size = sizeof(arr) / sizeof(arr[0]);

for (size_t i = 0; i < size; i++) {
    arr[i] = 0;
}
```

### 4. Bounds-Check Macros
```c
#define ARRAY_GET(arr, size, idx) \
    ((idx) >= 0 && (idx) < (size) ? (arr)[idx] : (abort(), 0))

#define ARRAY_SET(arr, size, idx, val) \
    do { \
        if ((idx) >= 0 && (idx) < (size)) \
            (arr)[idx] = (val); \
        else \
            abort(); \
    } while(0)
```

### 5. Use Compiler Warnings
```bash
gcc -Wall -Wextra -Warray-bounds program.c
```

### 6. Use Static Analysis Tools
- Clang Static Analyzer
- Valgrind
- AddressSanitizer

## Common Bug Patterns

### Off-by-One Errors
```c
int arr[10];
for (int i = 0; i <= 10; i++) {  /* Bug: should be i < 10 */
    arr[i] = i;
}
```

### Wrong Loop Bounds
```c
int arr[5];
for (int i = 0; i < 10; i++) {  /* Bug: loops too many times */
    arr[i] = 0;
}
```

### User Input as Index
```c
int arr[10];
int index;
scanf("%d", &index);
arr[index] = 100;  /* Dangerous! */
```

---

## Kata Challenge

### Challenge: Safe Array Access

**Task**: Implement a safe array system that:
1. Has a fixed-size array of 10 integers
2. Provides safe get/set operations with bounds checking
3. Returns an error code for invalid accesses
4. Tracks how many invalid accesses were attempted

**Requirements**:
1. Implement `safe_get(arr, index, *value)` returning 0 on success, -1 on failure
2. Implement `safe_set(arr, index, value)` returning 0 on success, -1 on failure
3. Test with valid and invalid indices
4. Report statistics at the end

**Expected Output**:
```
Setting arr[0] = 100: OK
Setting arr[9] = 900: OK
Setting arr[10] = 1000: ERROR (out of bounds)
Setting arr[-1] = -100: ERROR (out of bounds)
Getting arr[5]: 500 OK
Getting arr[15]: ERROR (out of bounds)

Statistics:
- Successful operations: 4
- Failed operations: 3
```

**Starter Code**:
```c
#include <stdio.h>

#define SIZE 10
int error_count = 0;
int success_count = 0;

int safe_get(int arr[], int index, int *value) {
    /* Implement bounds-checked get */
}

int safe_set(int arr[], int index, int value) {
    /* Implement bounds-checked set */
}

int main(void) {
    int arr[SIZE] = {0};
    
    /* Test operations here */
    
    return 0;
}
```

---
**Difficulty**: ⭐⭐ (Easy)  
**Time**: 20 minutes  
**Topics**: Arrays, Bounds Checking, Security
