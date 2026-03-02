# 156 - strlen: String Length Function

## Overview
`strlen` returns the number of characters in a string, **not counting the null terminator**. It's one of the most commonly used string functions in C.

## Function Signature

```c
#include <string.h>

size_t strlen(const char *s);
```

- **Returns**: Number of characters before `'\0'`
- **Parameter**: Pointer to null-terminated string
- **Return type**: `size_t` (unsigned integer type)

## Basic Usage

```c
char str[] = "Hello";
size_t len = strlen(str);  // len = 5
```

## strlen vs sizeof

```c
char str[] = "Hello";
strlen(str)  // 5 (characters only)
sizeof(str)  // 6 (includes '\0')

char *ptr = "Hello";
strlen(ptr)  // 5 (characters)
sizeof(ptr)  // 8 (pointer size, not string!)
```

## Implementation

```c
// Simple implementation
size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// Pointer arithmetic version
size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}
```

## Common Patterns

### Iterating Over String
```c
// Inefficient - strlen called each iteration!
for (int i = 0; i < strlen(str); i++) { ... }

// Better - cache the length
size_t len = strlen(str);
for (size_t i = 0; i < len; i++) { ... }

// Best - use pointer
for (char *p = str; *p; p++) { ... }
```

### Checking Empty String
```c
if (strlen(str) == 0) { ... }  // Works
if (str[0] == '\0') { ... }    // Faster
if (!*str) { ... }             // Same, idiomatic
```

## Important Notes

1. **Requires null terminator** - undefined behavior without it
2. **Returns 0 for empty string** - `strlen("")` returns 0
3. **Stops at first null** - `strlen("Hi\0Bye")` returns 2
4. **O(n) time complexity** - must scan entire string

---

# Kata Challenge

## Challenge: String Length Analyzer
Create a program that analyzes string lengths with custom implementations.

## Requirements
1. Implement `strlen` three different ways:
   - Loop with index
   - Loop with pointer
   - Recursive (for learning)
2. Create `strnlen` - strlen with maximum limit
3. Compare performance on long strings
4. Handle edge cases

## Expected Output
```
=== String Length Analyzer ===

Test string: "Hello, World!"
strlen:       13
my_strlen_v1: 13
my_strlen_v2: 13
my_strlen_v3: 13

Edge cases:
  strlen(""):           0
  strlen("a"):          1
  strlen("Hi\0Bye"):    2

strnlen tests:
  strnlen("Hello", 10): 5
  strnlen("Hello", 3):  3
  strnlen("Hello", 0):  0

Performance test (1000000 iterations on 100-char string):
  Library strlen: 45ms
  my_strlen_v1:   52ms
  my_strlen_v2:   48ms
```

## Function Signatures
```c
size_t my_strlen_v1(const char *s);  // Index-based
size_t my_strlen_v2(const char *s);  // Pointer-based
size_t my_strlen_v3(const char *s);  // Recursive

size_t my_strnlen(const char *s, size_t maxlen);
```

## strnlen Specification
```c
// Returns min(strlen(s), maxlen)
// Does NOT require null terminator if maxlen reached
size_t strnlen(const char *s, size_t maxlen);
```

## Bonus
- Implement `wcslen` for wide strings
- Optimize using word-at-a-time comparison
- Handle strings longer than SIZE_MAX (edge case)
