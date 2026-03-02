---
id: "012"
title: "Integer Variants (short, long, long long)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - short
  - long
  - data-types
  - integers
difficulty: beginner
source: "C11 Standard 6.2.5"
---

# 012 — Integer Variants (short, long, long long)

## Concept

C provides different integer sizes for different needs:

| Type | Minimum Size | Typical Size | Format |
|------|--------------|--------------|--------|
| `short` | 16 bits | 2 bytes | `%hd` |
| `int` | 16 bits | 4 bytes | `%d` |
| `long` | 32 bits | 4-8 bytes | `%ld` |
| `long long` | 64 bits | 8 bytes | `%lld` |

**Size relationships (guaranteed by C standard):**
```
sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
```

**Literal suffixes:**
```c
int i = 42;           // No suffix = int
long l = 42L;         // L suffix = long
long long ll = 42LL;  // LL suffix = long long
```

**When to use each:**
- `short`: Saving memory when values are small (rarely used)
- `int`: Default choice for integer values
- `long`: When `int` might overflow (file sizes on 32-bit)
- `long long`: Large values, timestamps, 64-bit calculations

**Platform differences:**
- On most 64-bit systems: `long` is 8 bytes
- On Windows 64-bit: `long` is still 4 bytes!
- Use `<stdint.h>` types (`int32_t`, `int64_t`) for guaranteed sizes

## Code

```c
#include <stdio.h>

int main(void) {
    short s = 32767;
    long l = 2147483647L;
    long long ll = 9223372036854775807LL;
    
    printf("=== Integer Variants ===\n\n");
    
    printf("short s = %hd\n", s);
    printf("long l = %ld\n", l);
    printf("long long ll = %lld\n", ll);
    
    printf("\nSizes:\n");
    printf("  sizeof(short)     = %zu bytes\n", sizeof(short));
    printf("  sizeof(int)       = %zu bytes\n", sizeof(int));
    printf("  sizeof(long)      = %zu bytes\n", sizeof(long));
    printf("  sizeof(long long) = %zu bytes\n", sizeof(long long));
    
    printf("\nMinimum guaranteed sizes:\n");
    printf("  short:     >= 16 bits (2 bytes)\n");
    printf("  int:       >= 16 bits (2 bytes)\n");
    printf("  long:      >= 32 bits (4 bytes)\n");
    printf("  long long: >= 64 bits (8 bytes)\n");
    
    return 0;
}
```

## Output

```
=== Integer Variants ===

short s = 32767
long l = 2147483647
long long ll = 9223372036854775807

Sizes:
  sizeof(short)     = 2 bytes
  sizeof(int)       = 4 bytes
  sizeof(long)      = 8 bytes
  sizeof(long long) = 8 bytes

Minimum guaranteed sizes:
  short:     >= 16 bits (2 bytes)
  int:       >= 16 bits (2 bytes)
  long:      >= 32 bits (4 bytes)
  long long: >= 64 bits (8 bytes)
```

## Key Takeaways

- Use `short` for small values (saves memory)
- Use `long` when `int` might be too small
- Use `long long` for 64-bit values
- Add `L` suffix for `long` literals, `LL` for `long long`
- Sizes vary by platform — use `sizeof` to check
- Match format specifiers: `%hd`, `%ld`, `%lld`

## Challenge

Calculate the maximum values each type can hold using bit math: for n bits, max signed = 2^(n-1) - 1. Verify with `<limits.h>` constants.

## Related

- [[011-integer-type-int]] — Basic int type
- [[013-unsigned-integers]] — Unsigned variants
- [[021-sizeof-operator]] — Checking sizes
- [[022-integer-limits]] — Limit constants
