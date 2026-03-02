# 159 - strcat: Concatenate Strings

## Overview
`strcat` appends the source string to the end of the destination string. Like `strcpy`, it has no bounds checking and can cause buffer overflows.

## Function Signature

```c
#include <string.h>

char *strcat(char *dest, const char *src);
```

- **dest**: Destination buffer (must have room for both strings!)
- **src**: String to append
- **Returns**: Pointer to dest

## Basic Usage

```c
char buffer[50] = "Hello";
strcat(buffer, " World");
// buffer: "Hello World"
```

## How It Works

```c
char *strcat(char *dest, const char *src) {
    char *p = dest;
    // 1. Find end of dest
    while (*p) p++;
    // 2. Copy src starting at end
    while ((*p++ = *src++) != '\0');
    return dest;
}
```

```
Before: [H][e][l][l][o][\0][ ][ ][ ][ ]
                       ^-- start copying here
After:  [H][e][l][l][o][ ][W][o][r][l][d][\0]
```

## DANGER: Buffer Overflow

```c
char small[10] = "Hello";  // 5 chars + '\0' = 6 used, 4 free
strcat(small, "World!");   // Needs 7 more bytes - OVERFLOW!
```

### Required Buffer Size
```c
// Buffer must hold: strlen(dest) + strlen(src) + 1
char buffer[100];
strcpy(buffer, str1);
if (strlen(buffer) + strlen(str2) < sizeof(buffer)) {
    strcat(buffer, str2);  // Safe
}
```

## Performance Consideration

```c
// Inefficient - O(n²) for multiple strcat
char result[1000] = "";
for (int i = 0; i < 100; i++) {
    strcat(result, "x");  // Scans from beginning each time!
}

// Better - track position
char result[1000];
char *p = result;
for (int i = 0; i < 100; i++) {
    *p++ = 'x';
}
*p = '\0';
```

## Safe Alternatives

### strncat (Bounded)
```c
strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
```

### snprintf (Recommended)
```c
snprintf(buffer, sizeof(buffer), "%s%s", str1, str2);
// Or append:
size_t len = strlen(buffer);
snprintf(buffer + len, sizeof(buffer) - len, "%s", str2);
```

### strlcat (BSD)
```c
strlcat(dest, src, sizeof(dest));
// Returns total length needed (for truncation detection)
```

---

# Kata Challenge

## Challenge: String Builder
Create a string builder that safely concatenates multiple strings.

## Requirements
Implement a `StringBuilder` with:
1. `sb_init(char *buf, size_t size)` - initialize builder
2. `sb_append(StringBuilder *sb, const char *str)` - append string
3. `sb_append_char(StringBuilder *sb, char c)` - append character
4. `sb_length(StringBuilder *sb)` - current length
5. `sb_remaining(StringBuilder *sb)` - space remaining

## Expected Output
```
=== String Builder Demo ===

Basic strcat:
  "Hello" + " World" = "Hello World"

String Builder:
  Initialized with buffer size 50
  append("Hello"): OK, length=5, remaining=44
  append(", "): OK, length=7, remaining=42
  append("World"): OK, length=12, remaining=37
  append("!"): OK, length=13, remaining=36
  Result: "Hello, World!"

Overflow handling:
  Buffer size: 10
  append("Hello"): OK
  append("World!"): TRUNCATED (only "Wor" added)
  Result: "HelloWor" (length 9, null at 10)

Multiple concatenation performance:
  strcat loop (1000x): XXms
  StringBuilder (1000x): XXms
```

## Struct Definition
```c
typedef struct {
    char *buffer;
    size_t capacity;
    size_t length;
} StringBuilder;
```

## Bonus
- Add `sb_printf(StringBuilder *sb, const char *fmt, ...)`
- Add `sb_clear(StringBuilder *sb)`
- Track truncation count
