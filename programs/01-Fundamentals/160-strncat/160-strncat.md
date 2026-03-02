# 160 - strncat: Bounded Concatenation

## Overview
`strncat` appends at most `n` characters from source to destination. Unlike `strncpy`, it **always null-terminates** the result.

## Function Signature

```c
#include <string.h>

char *strncat(char *dest, const char *src, size_t n);
```

- **dest**: Destination string (must have space for appended chars + '\0')
- **src**: Source string to append
- **n**: Maximum characters to append from src
- **Returns**: Pointer to dest

## Basic Usage

```c
char buffer[20] = "Hello";
strncat(buffer, " World!", 3);
// buffer: "Hello Wo" (only 3 chars appended: ' ', 'W', 'o')
```

## Key Difference from strncpy

| Feature | strncpy | strncat |
|---------|---------|---------|
| Null terminates | NOT if src >= n | ALWAYS |
| n meaning | Total bytes to write | Max chars from src |
| Null padding | Yes, fills rest | No |

## Implementation

```c
char *strncat(char *dest, const char *src, size_t n) {
    char *p = dest;
    while (*p) p++;              // Find end of dest
    while (n-- > 0 && *src) {    // Copy up to n chars
        *p++ = *src++;
    }
    *p = '\0';                   // ALWAYS null-terminate
    return dest;
}
```

## Correct Usage

### Calculate Remaining Space
```c
char buffer[SIZE] = "Hello";
size_t remaining = sizeof(buffer) - strlen(buffer) - 1;
strncat(buffer, " World", remaining);
```

### Common Mistake
```c
// WRONG - n is NOT buffer size!
strncat(buffer, src, sizeof(buffer));  // Can overflow!

// CORRECT - calculate remaining space
strncat(buffer, src, sizeof(buffer) - strlen(buffer) - 1);
```

## Safe Pattern

```c
#define SAFE_STRNCAT(dest, src) \
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1)

// Usage:
char buf[20] = "Hi";
SAFE_STRNCAT(buf, " there");
```

## Comparison with Alternatives

```c
char dest[20] = "Hello";

// strncat - manual remaining calculation
strncat(dest, " World", sizeof(dest) - strlen(dest) - 1);

// snprintf - cleaner, handles everything
snprintf(dest + strlen(dest), sizeof(dest) - strlen(dest), " World");

// strlcat (BSD) - returns total length needed
size_t needed = strlcat(dest, " World", sizeof(dest));
if (needed >= sizeof(dest)) {
    // Truncation occurred
}
```

---

# Kata Challenge

## Challenge: Safe String Concatenator
Build utilities for safe string concatenation with truncation detection.

## Requirements
Implement:
1. `safe_concat(char *dest, size_t size, const char *src)` - append with bounds check
2. `multi_concat(char *dest, size_t size, ...)` - append multiple strings
3. `my_strlcat(char *dest, const char *src, size_t size)` - BSD-style strlcat

All functions should:
- Never overflow buffer
- Return information about truncation
- Handle NULL pointers gracefully

## Expected Output
```
=== Safe Concatenation Demo ===

Basic strncat:
  "Hello" + " World!" (max 3): "Hello Wo"

safe_concat tests:
  Buffer[15] = "Hello"
  + " World" -> "Hello World" (OK)
  + "!!!!!!" -> "Hello World!" (TRUNCATED, 5 chars lost)

multi_concat test:
  Buffer[20] = ""
  Adding: "One", " Two", " Three", " Four"
  Result: "One Two Three Fo" (TRUNCATED)
  Chars needed: 22, available: 20

strlcat test:
  dest[10] = "Hello"
  strlcat(dest, " World!", 10)
  Result: "Hello Wor"
  Return: 13 (total length needed if no truncation)
  Truncated: YES (13 >= 10)
```

## Function Signatures
```c
// Returns: 0=success, >0=chars truncated
int safe_concat(char *dest, size_t size, const char *src);

// Returns: total chars that would be needed
size_t multi_concat(char *dest, size_t size, ...); // NULL-terminated varargs

// BSD-compatible strlcat
size_t my_strlcat(char *dest, const char *src, size_t size);
```

## Bonus
- Add formatted concatenation: `safe_catf(dest, size, "%s: %d", name, value)`
- Implement a logging function that safely builds log messages
- Benchmark against repeated strcat calls
