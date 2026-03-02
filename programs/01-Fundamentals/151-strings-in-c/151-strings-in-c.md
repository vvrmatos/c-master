# 151 - Strings in C: Character Arrays with Null Terminator

## Overview
In C, a **string** is simply an array of characters terminated by a null character (`'\0'`). There is no dedicated string type - strings are built from the primitive `char` type.

## What Makes a String

```c
// A string is a char array ending with '\0'
char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};

// This is NOT a valid string (no terminator)
char chars[] = {'H', 'e', 'l', 'l', 'o'};  // Just a char array
```

## String Literals

```c
// Compiler automatically adds '\0'
char greeting[] = "Hello";  // 6 chars: H e l l o \0

// Equivalent to:
char greeting[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

## Memory Layout

```
char str[] = "Cat";

Index:    [0]  [1]  [2]  [3]
Value:    'C'  'a'  't'  '\0'
ASCII:     67   97  116    0
```

## Key Concepts

### Null Terminator
- `'\0'` has ASCII value 0
- Marks end of string
- Functions like `printf("%s")` read until they find `'\0'`

### String vs Array Size
```c
char str[] = "Hello";
sizeof(str)    // 6 (includes '\0')
strlen(str)    // 5 (excludes '\0')
```

### Mutable vs Immutable
```c
// Mutable - stored in stack/data segment
char arr[] = "Hello";
arr[0] = 'J';  // OK: "Jello"

// Immutable - stored in read-only memory
char *ptr = "Hello";
ptr[0] = 'J';  // UNDEFINED BEHAVIOR!
```

## Common Pitfalls

```c
// Pitfall 1: Forgetting null terminator
char bad[5] = {'H', 'e', 'l', 'l', 'o'};  // Not a string!
printf("%s", bad);  // Undefined behavior

// Pitfall 2: Buffer too small
char small[5] = "Hello";  // No room for '\0'!

// Pitfall 3: Comparing strings with ==
if (str1 == str2)  // Compares pointers, not contents!
```

---

# Kata Challenge

## Challenge: String Anatomy Explorer
Write a program that:
1. Takes a string from user (max 50 chars)
2. Displays each character with its index and ASCII value
3. Shows the null terminator explicitly
4. Reports both `sizeof` and string length

## Requirements
- Use `fgets` for safe input
- Handle the newline character from fgets
- Display the null terminator position

## Expected Output
```
Enter a string: Hello

String Anatomy:
Index  Char  ASCII  Hex
-----  ----  -----  ----
  0     'H'    72   0x48
  1     'e'   101   0x65
  2     'l'   108   0x6c
  3     'l'   108   0x6c
  4     'o'   111   0x6f
  5    '\0'     0   0x00  <-- NULL TERMINATOR

Array size (sizeof): 51 bytes
String length: 5 characters
Null terminator at index: 5
```

## Bonus
- Display non-printable characters specially (like newline as '\n')
- Show memory addresses of each character
- Demonstrate the difference between `char[]` and `char*`
