# 158 - strncpy: Bounded String Copy

## Overview
`strncpy` copies at most `n` characters from source to destination. Despite being "bounded," it has quirks that make it tricky to use correctly.

## Function Signature

```c
#include <string.h>

char *strncpy(char *dest, const char *src, size_t n);
```

## Behavior (Important!)

### Case 1: strlen(src) < n
```c
char dest[10];
strncpy(dest, "Hi", 10);
// Copies "Hi" then PADS with '\0' to fill all 10 bytes
// dest: ['H']['i']['\0']['\0']...['\0']
```

### Case 2: strlen(src) >= n
```c
char dest[5];
strncpy(dest, "Hello World", 5);
// Copies exactly 5 chars: "Hello"
// NO NULL TERMINATOR ADDED!
// dest: ['H']['e']['l']['l']['o']  <- NOT a valid string!
```

## The strncpy Gotchas

| Gotcha | Problem |
|--------|---------|
| No null terminator | If src >= n, result isn't null-terminated |
| Wasteful padding | Writes n bytes even if src is short |
| Performance | O(n) always, not O(strlen(src)) |

## Safe Usage Pattern

```c
// ALWAYS do this:
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';

// Or use a wrapper:
void safe_strncpy(char *dest, const char *src, size_t size) {
    if (size > 0) {
        strncpy(dest, src, size - 1);
        dest[size - 1] = '\0';
    }
}
```

## Better Alternatives

### snprintf (Recommended)
```c
snprintf(dest, sizeof(dest), "%s", src);
// Always null-terminates
// Returns number of chars that would be written
```

### strlcpy (BSD/POSIX)
```c
size_t len = strlcpy(dest, src, sizeof(dest));
// Always null-terminates
// Returns strlen(src) for truncation detection
if (len >= sizeof(dest)) {
    // Truncation occurred
}
```

## Implementation

```c
char *strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    // Copy up to n chars from src
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    // Pad remainder with '\0'
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
```

## When to Use strncpy

- Fixed-width fields (database records, network protocols)
- When you need null-padding behavior
- Legacy code compatibility

## When NOT to Use strncpy

- General string copying (use snprintf)
- When performance matters (null-padding is slow)
- When you forget to manually null-terminate

---

# Kata Challenge

## Challenge: strncpy Peculiarities Explorer
Create a program that demonstrates all the quirks of strncpy and builds safer alternatives.

## Requirements
1. Demonstrate all three cases (src < n, src == n, src > n)
2. Show the null-padding behavior visually
3. Implement `safe_strncpy` that always null-terminates
4. Implement `strlcpy` if not available on your system

## Expected Output
```
=== strncpy Behavior Analysis ===

Case 1: Source shorter than n
  strncpy(dest, "Hi", 10)
  Result: [H|i|\0|\0|\0|\0|\0|\0|\0|\0]
  Valid string: YES
  Null-padded: 8 extra '\0' bytes

Case 2: Source equals n
  strncpy(dest, "Hello", 5)
  Result: [H|e|l|l|o]
  Valid string: NO - missing null terminator!
  
Case 3: Source longer than n
  strncpy(dest, "Hello World", 5)  
  Result: [H|e|l|l|o]
  Valid string: NO - truncated without null!

=== Safe Alternatives ===

safe_strncpy(dest, "Hello World", 5):
  Result: [H|e|l|l|\0]
  Valid string: YES (truncated but safe)

strlcpy(dest, "Hello World", 5):
  Result: [H|e|l|l|\0]
  Return: 11 (original length - truncation detected!)
```

## Function Signatures
```c
// Always null-terminates, returns dest
char *safe_strncpy(char *dest, const char *src, size_t size);

// Always null-terminates, returns strlen(src)
size_t my_strlcpy(char *dest, const char *src, size_t size);
```

## Bonus
- Benchmark strncpy vs snprintf vs strlcpy
- Implement truncation logging
- Create a memory visualizer for buffer contents
