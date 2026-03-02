# 157 - strcpy: Copy Strings

## Overview
`strcpy` copies a string from source to destination, including the null terminator. It's simple but dangerous due to lack of bounds checking.

## Function Signature

```c
#include <string.h>

char *strcpy(char *dest, const char *src);
```

- **dest**: Destination buffer (must be large enough!)
- **src**: Source string (null-terminated)
- **Returns**: Pointer to dest

## Basic Usage

```c
char src[] = "Hello";
char dest[10];

strcpy(dest, src);
// dest now contains "Hello\0"
```

## Implementation

```c
char *strcpy(char *dest, const char *src) {
    char *p = dest;
    while ((*p++ = *src++) != '\0');
    return dest;
}

// Breaking it down:
// *p++ = *src++  copies one char and advances both pointers
// != '\0'        loop continues until null copied
```

## Return Value

```c
// Returns destination - enables chaining
char buf[100];
printf("%s\n", strcpy(buf, "Hello"));

// But chaining is dangerous:
strcat(strcpy(buf, "Hello"), " World");  // Works but risky
```

## DANGER: No Bounds Checking!

```c
char small[5];
strcpy(small, "Hello, World!");  // BUFFER OVERFLOW!
// Writes past end of array - undefined behavior
// May crash, corrupt data, or create security vulnerability
```

## Safe Alternatives

### strncpy (Bounded)
```c
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';  // Ensure termination
```

### snprintf (Safe)
```c
snprintf(dest, sizeof(dest), "%s", src);
// Always null-terminates, returns chars needed
```

### strlcpy (BSD/POSIX)
```c
strlcpy(dest, src, sizeof(dest));
// Like strncpy but always null-terminates
// Returns strlen(src) for truncation detection
```

## Common Patterns

```c
// Allocate exact size needed
char *copy = malloc(strlen(src) + 1);
if (copy) {
    strcpy(copy, src);  // Safe: exact size allocated
}

// Copy with length check
if (strlen(src) < sizeof(dest)) {
    strcpy(dest, src);
}
```

---

# Kata Challenge

## Challenge: Safe String Copy Library
Create a comprehensive string copy library with safety features.

## Requirements
Implement:
1. `my_strcpy` - basic implementation (understand the mechanics)
2. `safe_strcpy` - returns success/failure, never overflows
3. `dup_string` - allocates and returns a copy
4. All functions should handle NULL pointers gracefully

## Expected Output
```
=== String Copy Library ===

Basic strcpy:
  Source: "Hello, World!"
  my_strcpy result: "Hello, World!"

Safe strcpy (buffer size 10):
  Copying "Hello": SUCCESS -> "Hello"
  Copying "Hello, World!": TRUNCATED -> "Hello, Wo"

dup_string:
  Original: "Dynamic copy"
  Duplicate: "Dynamic copy"
  (allocated 13 bytes)

Edge cases:
  Empty string: "" (length 0)
  NULL source: (handled gracefully)
  NULL dest: (handled gracefully)
```

## Function Signatures
```c
char *my_strcpy(char *dest, const char *src);

// Returns: 0=success, -1=null ptr, 1=truncated
int safe_strcpy(char *dest, size_t dest_size, const char *src);

// Returns: allocated copy (caller must free) or NULL
char *dup_string(const char *src);
```

## Bonus
- Implement `strcpy_s` (C11 Annex K bounds-checking interface)
- Add copy statistics (bytes copied, truncation count)
- Implement overlapping copy detection
