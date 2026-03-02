# 152 - String Initialization: `char str[] = "hello";`

## Overview
C provides several ways to initialize strings. Understanding the differences between them is crucial for writing correct and safe code.

## Initialization Methods

### Method 1: String Literal (Recommended)
```c
char str[] = "Hello";
// Size: 6 (5 chars + '\0')
// Mutable: YES
```

### Method 2: Character Array
```c
char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
// Must include '\0' manually!
// Mutable: YES
```

### Method 3: Fixed Size
```c
char str[10] = "Hi";
// Size: 10 (explicit)
// Remaining bytes: filled with '\0'
// Mutable: YES
```

### Method 4: Pointer to Literal
```c
const char *str = "Hello";
// Size: 8 (pointer size, not string)
// Mutable: NO - string is in read-only memory
// Use const to be explicit
```

## Comparison Chart

| Declaration | Size | Mutable | Location |
|-------------|------|---------|----------|
| `char s[] = "Hi"` | 3 | Yes | Stack |
| `char s[10] = "Hi"` | 10 | Yes | Stack |
| `char *s = "Hi"` | 8* | No | Read-only |
| `static char s[] = "Hi"` | 3 | Yes | Data segment |

*Pointer size on 64-bit systems

## Zero-Fill Behavior

```c
char buf[10] = "AB";
// Memory: ['A']['B'][0][0][0][0][0][0][0][0]
// All uninitialized elements become '\0'

char buf[10] = {0};  // All 10 bytes are zero
char buf[10] = "";   // Same as above
```

## Common Patterns

```c
// Array of strings
char *days[] = {"Mon", "Tue", "Wed", "Thu", "Fri"};

// 2D char array (fixed-length strings)
char names[3][10] = {"Alice", "Bob", "Charlie"};

// Empty string
char empty[] = "";  // sizeof = 1 (just '\0')
```

## Pitfalls

```c
// Pitfall 1: Buffer overflow
char s[3] = "Hello";  // ERROR or truncation!

// Pitfall 2: Modifying literal
char *s = "Hello";
s[0] = 'J';  // CRASH! Undefined behavior

// Pitfall 3: Forgetting null terminator  
char s[5] = {'H', 'e', 'l', 'l', 'o'};  // NOT a string!
```

---

# Kata Challenge

## Challenge: String Initializer Showcase
Write a program that demonstrates all string initialization methods and their properties.

## Requirements
Create and display information about strings initialized using:
1. `char s[] = "literal"`
2. `char s[] = {'c','h','a','r','s','\0'}`
3. `char s[20] = "sized"`
4. `const char *s = "pointer"`
5. `char *strings[] = {"array", "of", "strings"}`

For each, display:
- The string content
- sizeof the variable
- Whether it's mutable (test by attempting modification)
- Memory address

## Expected Output
```
=== String Initialization Methods ===

1. char s[] = "Hello"
   Content: "Hello"
   sizeof: 6 bytes
   Mutable: YES (modified to "Jello")
   Address: 0x7fff...

2. char s[] = {'W','o','r','l','d','\0'}
   Content: "World"
   sizeof: 6 bytes
   Mutable: YES
   Address: 0x7fff...

3. char s[20] = "Fixed"
   Content: "Fixed"
   sizeof: 20 bytes
   Mutable: YES
   Unused bytes: 15 (all zeros)
   Address: 0x7fff...

4. const char *s = "Pointer"
   Content: "Pointer"
   sizeof: 8 bytes (pointer!)
   Mutable: NO (read-only literal)
   Address: 0x...

5. char *arr[] = {"one", "two", "three"}
   strings[0]: "one"
   strings[1]: "two"
   strings[2]: "three"
   sizeof(arr): 24 bytes (3 pointers)
```

## Bonus
- Show the actual bytes in memory for a partially initialized array
- Demonstrate what happens with `char s[5] = "Hello"` (if compiler allows)
