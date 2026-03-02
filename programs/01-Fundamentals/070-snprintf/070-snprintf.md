---
id: "070"
title: "snprintf() - Safe Formatted Strings"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - snprintf
  - formatting
  - strings
  - security
  - buffer-safety
difficulty: intermediate
source: "C11 Standard 7.21.6.5"
---

# 070 — snprintf() - Safe Formatted Strings

## Concept

`snprintf()` is the **safe version of sprintf()** — it limits characters written to prevent buffer overflow. Always use snprintf over sprintf.

**Syntax:**
```c
int snprintf(char *str, size_t size, const char *format, ...);
```

**Parameters:**
- `str` — Destination buffer
- `size` — Buffer size (including null terminator)
- `format` — Format string
- `...` — Arguments

**Return value:**
- Number of characters that **would have been written** (excluding null)
- If return >= size: **truncation occurred**

**Key safety features:**
1. Never writes more than `size` bytes
2. Always null-terminates (if size > 0)
3. Return value indicates if truncation happened

**Detecting truncation:**
```c
int needed = snprintf(buf, sizeof(buf), "...", args);
if (needed >= sizeof(buf)) {
    // Truncation occurred!
}
```

**Calculating required size:**
```c
int needed = snprintf(NULL, 0, "format", args);  // Size needed
char *buf = malloc(needed + 1);                   // +1 for null
snprintf(buf, needed + 1, "format", args);
```

## Code

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("=== snprintf() - Safe Formatted Strings ===\n\n");
    
    char small[10];
    int written;
    
    written = snprintf(small, sizeof(small), "Hello!");
    printf("Fits: \"%s\" (wrote %d, needed %d)\n\n", small, (int)strlen(small), written);
    
    written = snprintf(small, sizeof(small), "Hello, World! This is long.");
    printf("Truncated: \"%s\" (would need %d chars)\n", small, written);
    printf("Buffer safe - no overflow!\n\n");
    
    printf("snprintf() return value:\n");
    printf("  Returns: number of chars that WOULD be written\n");
    printf("  (excluding null terminator)\n");
    printf("  If return >= size: truncation occurred\n\n");
    
    char buf[20];
    int needed;
    
    needed = snprintf(buf, sizeof(buf), "Count: %d", 42);
    printf("Check truncation:\n");
    printf("  Buffer size: %zu\n", sizeof(buf));
    printf("  Would need: %d\n", needed);
    printf("  Truncated: %s\n\n", needed >= (int)sizeof(buf) ? "YES" : "NO");
    
    printf("Safe string building:\n");
    char message[50];
    char name[] = "Alice";
    int age = 25;
    
    needed = snprintf(message, sizeof(message), 
                      "User: %s, Age: %d, Status: Active", name, age);
    if (needed >= (int)sizeof(message)) {
        printf("  Warning: message truncated!\n");
        printf("  Needed %d bytes, had %zu\n", needed, sizeof(message));
    }
    printf("  Message: %s\n\n", message);
    
    printf("Calculating required size:\n");
    int count = 1000;
    double price = 12345.67;
    
    needed = snprintf(NULL, 0, "Items: %d, Total: $%.2f", count, price);
    printf("  Need %d bytes for format\n", needed + 1);
    
    char *dynamic = malloc(needed + 1);
    if (dynamic) {
        snprintf(dynamic, needed + 1, "Items: %d, Total: $%.2f", count, price);
        printf("  Result: %s\n\n", dynamic);
        free(dynamic);
    }
    
    printf("Incremental building with bounds:\n");
    char report[100];
    size_t size = sizeof(report);
    size_t offset = 0;
    int ret;
    
    ret = snprintf(report + offset, size - offset, "=== Report ===\n");
    if (ret > 0 && ret < (int)(size - offset)) offset += ret;
    
    ret = snprintf(report + offset, size - offset, "Items: %d\n", 42);
    if (ret > 0 && ret < (int)(size - offset)) offset += ret;
    
    ret = snprintf(report + offset, size - offset, "Status: %s\n", "OK");
    if (ret > 0 && ret < (int)(size - offset)) offset += ret;
    
    printf("%s\n", report);
    
    printf("snprintf() vs sprintf():\n");
    printf("  sprintf():  NO size limit - DANGEROUS\n");
    printf("  snprintf(): Size limit - SAFE\n");
    printf("  Always prefer snprintf() in production\n\n");
    
    printf("Portable size calculation:\n");
    char path[256];
    char dir[] = "/very/long/directory/path/that/might/be/truncated";
    char file[] = "filename.txt";
    
    ret = snprintf(path, sizeof(path), "%s/%s", dir, file);
    if (ret >= (int)sizeof(path)) {
        printf("  Path truncated! Needed %d, had %zu\n", ret, sizeof(path));
    } else {
        printf("  Path OK: %s\n", path);
    }
    
    printf("\nBest practices:\n");
    printf("  1. Always use snprintf, never sprintf\n");
    printf("  2. Check return value for truncation\n");
    printf("  3. Use sizeof(buf) for size parameter\n");
    printf("  4. Use snprintf(NULL, 0, ...) to calculate size\n");
    printf("  5. Always null-terminate (snprintf does this)\n");
    
    return 0;
}
```

## Output

```
=== snprintf() - Safe Formatted Strings ===

Fits: "Hello!" (wrote 6, needed 6)

Truncated: "Hello, Wo" (would need 27 chars)
Buffer safe - no overflow!

snprintf() return value:
  Returns: number of chars that WOULD be written
  (excluding null terminator)
  If return >= size: truncation occurred

Check truncation:
  Buffer size: 20
  Would need: 9
  Truncated: NO

Safe string building:
  Message: User: Alice, Age: 25, Status: Active

Calculating required size:
  Need 28 bytes for format
  Result: Items: 1000, Total: $12345.67

Incremental building with bounds:
=== Report ===
Items: 42
Status: OK

snprintf() vs sprintf():
  sprintf():  NO size limit - DANGEROUS
  snprintf(): Size limit - SAFE
  Always prefer snprintf() in production

Portable size calculation:
  Path OK: /very/long/directory/path/that/might/be/truncated/filename.txt

Best practices:
  1. Always use snprintf, never sprintf
  2. Check return value for truncation
  3. Use sizeof(buf) for size parameter
  4. Use snprintf(NULL, 0, ...) to calculate size
  5. Always null-terminate (snprintf does this)
```

## Compilation

```bash
gcc 070-snprintf.c -o 070-snprintf
./070-snprintf
```

## Key Takeaways

- `snprintf()` is buffer-overflow safe sprintf
- Always pass buffer size as second argument
- Return value shows chars that would be written
- If return >= size, truncation occurred
- Use `snprintf(NULL, 0, ...)` to calculate needed size
- Always prefer snprintf over sprintf in production

## Challenge

Write a safe function that concatenates multiple strings with a separator, handling buffer limits gracefully.

## Related

- [[069-sprintf]] — Unsafe version (avoid)
- [[068-sscanf]] — Parsing strings (inverse)
