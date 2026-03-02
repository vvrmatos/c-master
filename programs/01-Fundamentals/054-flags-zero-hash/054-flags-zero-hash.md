---
id: "054"
title: "Flags: 0 and #"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - formatting
  - flags
  - zero-padding
  - hex
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 054 — Flags: 0 and #

## Concept

The `0` and `#` flags provide additional formatting control for numbers.

**Flag summary:**
| Flag | Effect |
|------|--------|
| `0` | Pad with leading zeros instead of spaces |
| `#` | Alternate form (prefix for hex/octal, decimal point for floats) |

**The `0` flag (zero-padding):**
```c
printf("%05d", 42);    // "00042"
printf("%08x", 255);   // "000000ff"
printf("%010.2f", 3.14); // "0000003.14"
```

**Zero-padding rules:**
- Only works with numeric types
- `-` flag overrides `0` (left-align wins)
- Sign appears before zeros: `%+05d` → "+0042" for 42

**The `#` flag (alternate form):**
| Specifier | Effect of # |
|-----------|-------------|
| `%#x`, `%#X` | Adds 0x or 0X prefix |
| `%#o` | Adds leading 0 |
| `%#f` | Always show decimal point |
| `%#g` | Keep trailing zeros |

**Notable behaviors:**
- `%#x` with value 0 prints just "0" (no prefix)
- `%#.0f` with 3.0 prints "3." (decimal shown)

**Common uses:**
- Zero-padding: timestamps, hex dumps, fixed-width IDs
- Hash flag: explicit hex notation, debugging output

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Flags: 0 and # ===\n\n");
    
    printf("Zero flag (0) - pad with zeros:\n");
    printf("  %%5d:  [%5d]\n", 42);
    printf("  %%05d: [%05d]\n", 42);
    printf("  %%8d:  [%8d]\n", 42);
    printf("  %%08d: [%08d]\n", 42);
    
    printf("\nZero padding with negative numbers:\n");
    printf("  %%05d: [%05d]\n", -42);
    printf("  %%+05d: [%+05d]\n", 42);
    printf("  %%+05d: [%+05d]\n", -42);
    
    printf("\nZero padding with floats:\n");
    printf("  %%10.2f:  [%10.2f]\n", 3.14);
    printf("  %%010.2f: [%010.2f]\n", 3.14);
    printf("  %%010.2f: [%010.2f]\n", -3.14);
    
    printf("\nZero padding for hex (common use):\n");
    printf("  %%x:   %x\n", 255);
    printf("  %%02x: %02x\n", 255);
    printf("  %%04x: %04x\n", 255);
    printf("  %%08x: %08x\n", 255);
    
    printf("\nByte dump example:\n");
    unsigned char data[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F};
    printf("  ");
    for (int i = 0; i < 5; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
    
    printf("\nHash flag (#) - alternate form:\n");
    printf("  %%x:  %x (no prefix)\n", 255);
    printf("  %%#x: %#x (with 0x)\n", 255);
    printf("  %%X:  %X\n", 255);
    printf("  %%#X: %#X (with 0X)\n", 255);
    
    printf("\nHash with octal:\n");
    printf("  %%o:  %o\n", 64);
    printf("  %%#o: %#o (with leading 0)\n", 64);
    
    printf("\nHash with zero value (special case):\n");
    printf("  %%#x with 0: %#x (no prefix for 0)\n", 0);
    printf("  %%#o with 0: %#o\n", 0);
    
    printf("\nHash with floats (show decimal point):\n");
    printf("  %%.0f: %.0f (no decimal)\n", 3.0);
    printf("  %%#.0f: %#.0f (forced decimal)\n", 3.0);
    printf("  %%g: %g (trailing zeros removed)\n", 1.0);
    printf("  %%#g: %#g (keeps trailing zeros)\n", 1.0);
    
    printf("\nCombining 0 and #:\n");
    printf("  %%#08x: %#08x\n", 255);
    printf("  %%#010x: %#010x\n", 255);
    printf("  %%#08X: %#08X\n", 0xABCD);
    
    printf("\nZero flag with left-align (- wins):\n");
    printf("  %%08d:  [%08d]\n", 42);
    printf("  %%-08d: [%-08d] (- overrides 0)\n", 42);
    
    printf("\nPractical examples:\n");
    printf("  Time: %02d:%02d:%02d\n", 9, 5, 3);
    printf("  Date: %04d-%02d-%02d\n", 2024, 1, 5);
    printf("  MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", 
           0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF);
    printf("  IP (hex): %02X.%02X.%02X.%02X\n", 192, 168, 1, 1);
    printf("  Color: #%02X%02X%02X\n", 255, 128, 0);
    
    return 0;
}
```

## Output

```
=== Flags: 0 and # ===

Zero flag (0) - pad with zeros:
  %5d:  [   42]
  %05d: [00042]
  %8d:  [      42]
  %08d: [00000042]

Zero padding with negative numbers:
  %05d: [-0042]
  %+05d: [+0042]
  %+05d: [-0042]

Zero padding with floats:
  %10.2f:  [      3.14]
  %010.2f: [0000003.14]
  %010.2f: [-000003.14]

Zero padding for hex (common use):
  %x:   ff
  %02x: ff
  %04x: 00ff
  %08x: 000000ff

Byte dump example:
  48 65 6C 6C 6F 

Hash flag (#) - alternate form:
  %x:  ff (no prefix)
  %#x: 0xff (with 0x)
  %X:  FF
  %#X: 0XFF (with 0X)

Hash with octal:
  %o:  100
  %#o: 0100 (with leading 0)

Hash with zero value (special case):
  %#x with 0: 0 (no prefix for 0)
  %#o with 0: 0

Hash with floats (show decimal point):
  %.0f: 3 (no decimal)
  %#.0f: 3. (forced decimal)
  %g: 1 (trailing zeros removed)
  %#g: 1.00000 (keeps trailing zeros)

Combining 0 and #:
  %#08x: 0x0000ff
  %#010x: 0x000000ff
  %#08X: 0X00ABCD

Zero flag with left-align (- wins):
  %08d:  [00000042]
  %-08d: [42      ] (- overrides 0)

Practical examples:
  Time: 09:05:03
  Date: 2024-01-05
  MAC: AA:BB:CC:DD:EE:FF
  IP (hex): C0.A8.01.01
  Color: #FF8000
```

## Compilation

```bash
gcc 054-flags-zero-hash.c -o 054-flags-zero-hash
./054-flags-zero-hash
```

## Key Takeaways

- `0` flag pads with leading zeros instead of spaces
- `-` flag overrides `0` (left alignment wins)
- `#` adds 0x/0X prefix for hex, leading 0 for octal
- `#` with floats forces decimal point
- Zero-padding is essential for timestamps and hex output
- Combine flags: `%#08x` for consistent hex representation

## Challenge

Write a program that creates a hex dump display showing memory addresses, hex bytes, and ASCII representation like a hex editor.

## Related

- [[053-flags-minus-plus-space]] — Other flags
- [[049-format-specifier-x-X-o]] — Hex/octal formats
